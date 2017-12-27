require File.expand_path('../code_generator_proxy', __FILE__)

class CodeStatement
  
  attr_accessor :parent
  
  MATCH_NONE = 0
  MATCH_PART = 1
  MATCH_ALL  = 2
  
  def generate_code(proxy)
    raise NotImplementedError.new("#{self.class.name} : generate_code method has not been implemented.")
  end
  
  def all_internal_call_operations
    nil
  end
  
  def match(other)
    return MATCH_NONE
  end
  
end

class SingleOperation < CodeStatement
  
  attr_reader :statement
  attr_reader :comment
  
  def initialize(statement)
    @statement = statement;    
  end  
  
  def inner_api_call?
    if @statement.type == ScriptStatement::TYPE_INTERNAL_CALL_API
      true
    else
      false
    end
  end

  def all_internal_call_operations
    inner_api_call? ? self : nil
  end
    
  def generate_code(proxy)
    target_module = @statement.contents[:destination_component_name]
    event = Event.new(statement.contents[:message])
    message_name = event.name
    param_list = event.params
    type_symbol = case @statement.type
                  when ScriptStatement::TYPE_INTERNAL_CALL_API
                    "api"
                  when ScriptStatement::TYPE_EXTERNAL_CALL_API
                    "API"
                  when ScriptStatement::TYPE_SEND_MESSAGE
                    "API_SendMessage"
                  else
                    ""
                  end
    proxy.generate_function_call("#{target_module}_#{type_symbol}_#{message_name}", param_list)
  end
  
  def generate_prototype(proxy = nil)
    module_name = @statement.contents[:source_component_name]
    event = Event.new(statement.contents[:message])
    message_name = event.name
    param_list = event.params
    
    proxy = CppCodeGenerator.new if proxy == nil    
    proxy.generate_function_prototype("#{module_name}_api_#{message_name}", param_list)
  end
  
  def match(other)
    return MATCH_NONE if (other == nil) || (other.class != self.class)
    
    self_event = Event.new(statement.contents[:message])
    other_event = Event.new(other.statement.contents[:message])
      
    if (self_event.name.eql?(other_event.name))      
      if (self_event.params.eql?(other_event.params))
        MATCH_ALL              
      else
        MATCH_PART
      end        
    else
      MATCH_NONE
    end 
  end
  
  def merge(other)
    case match(other)
    when MATCH_ALL
      self
    when MATCH_PART
      [self, other]
    else
      nil
    end
  end   
  
end

class StateTransmit < SingleOperation
  
  def initialize(statement)
    super
  end

  def all_internal_call_operations
    nil
  end
  
  def generate_code(proxy)
    module_name = @statement.contents[:component_name]
    state = @statement.contents[:states]
      
    # It's invalid to transmit to multi states 
    if state.size == 1
      proxy.generate_transmit_code("#{module_name}_SetStatus", "ST_#{state[0]}")
    end
  end
  
  def match(other)
    return MATCH_NONE if (other == nil) || (other.class != self.class)
    
    self_state = statement.contents[:states]
    other_state= other.statement.contents[:states]

    if (self_state.eql?(other_state))      
      MATCH_ALL
    else
      MATCH_PART
    end 
  end
end


class OperationSequence < CodeStatement
  attr_reader :operations
  
  def initialize
    @operations = []
  end

  def add_operation(operation)
    @operations << operation
  end
  
  def add_operation_list(list)
    list.operations.each do |item|
      @operations << item
    end
  end

  def pop_operation
    @operations.pop
  end

  def generate_code(proxy)
    @operations.inject([]) {|code, op| code << op.generate_code(proxy)}
  end

  def all_internal_call_operations
    @operations.inject([]) {|code, op| code << op.all_internal_call_operations }
  end

  def empty?
    @operations.empty?
  end
  
  def match(other)
    return MATCH_NONE if (other == nil) || (other.class != self.class)
    
    loop = 0
    result = other.operations.map {|op| 
      type, loop = match_single(operations, loop, op)
      loop += 1 if type != MATCH_NONE
      type
    }

    is_all = result.include?(MATCH_ALL)
    is_part = result.include?(MATCH_PART)
    is_none = result.include?(MATCH_NONE)
                    
    if (is_all || is_part)
      if (is_part || is_none)
        MATCH_PART
      else
        MATCH_ALL
      end
    else
      MATCH_NONE
    end
    
  end
  
  def merge(other)
    case match(other)
    when MATCH_ALL
      self
    when MATCH_PART
      seq = self.class.new
      list = []
      undo_list = []
      loop = 0
      other.operations.each do |op|
        loop = merge_single(list, operations, loop, op, undo_list)
      end
      
      list.push(operations.values_at(loop..(operations.size - 1))) if loop < operations.size
      list.push(undo_list) if undo_list != nil
      list.flatten!
      
      seq.replace_operations(list)
      seq
    else
      nil   
    end 
  end
  
  def match_single(list, loop, other)
    result = []
    list.each_index {|index| 
      if (index >= loop)
        result << list[index].match(other)
      else
        result << MATCH_NONE
      end
    }
    
    all_index = result.index(MATCH_ALL)
    part_index= result.index(MATCH_PART)
    
    if (all_index != nil)
      [MATCH_ALL, all_index]
    elsif (part_index != nil)
      [MATCH_PART, part_index]
    else
      [MATCH_NONE, loop]
    end
  end
  
  def merge_single(list, self_list, self_index, other, undo_list)
      result, index = match_single(self_list, self_index, other)
      if result != MATCH_NONE
        if (index > self_index)          
          list.push(self_list.values_at(self_index..(index-1)))
        end
        list.push(undo_list) if undo_list.size > 0
        undo_list.clear   
        list.push(self_list[index].merge(other))
        index += 1
      else
        undo_list << other  
      end
      
      return index  
  end
  
  def replace_operations(list)
    @operations = list 
  end
 
end



class SingleConditionStruction < CodeStatement
  attr_reader :condition
  attr_reader :sequence

  def initialize(condition)
    @condition = condition
    @sequence = OperationSequence.new
  end
  
  def add_operation(operation)
    @sequence.add_operation(operation)
  end

  def pop_operation
    @sequence.pop_operation()
  end

  def all_internal_call_operations
    @sequence.all_internal_call_operations()
  end

  def empty?
    @sequence.empty?
  end
  
  def match(other)
    return MATCH_NONE if (other == nil) || (other.class != self.class)
    
    if (condition.eql?(other.condition))
      if (MATCH_ALL == sequence.match(other.sequence))
        MATCH_ALL
      else
        MATCH_PART        
      end      
    else
      MATCH_NONE
    end   
  end
  
  def merge(other)
    case match(other)
    when MATCH_ALL
      self
    when MATCH_PART
      sc = self.class.new(condition)
      sc.replace_sequence(sequence.merge(other.sequence))
      sc
    else
      nil 
    end   
  end
  
  def replace_sequence(seq)
    @sequence = seq
  end
  
end


class MultiConditionOperations < CodeStatement
  
  attr_accessor :branches
  
  def initialize(condition)
    @branches = [SingleConditionStruction.new(condition)]
    @current_op_seq = @branches.last 
  end

  def pop_operation
    @current_op_seq.pop_operation
  end

  def add_operation(operation)
    @current_op_seq.add_operation operation
  end

  def update_structure(key_word, condition)
    @branches << SingleConditionStruction.new(condition)
    @current_op_seq = @branches.last 
  end
  
  def empty?
    @branches.all? &:empty?
  end
  
  def all_internal_call_operations
    @branches.inject [] do |inner_calls, branch|
      inner_calls << branch.all_internal_call_operations
    end
  end
  
  def match(other)
    return MATCH_NONE if (other == nil) || (other.class != self.class)
    
    result = other.branches.map {|branch| match_single(branches, branch)[0]}

    is_all = result.include?(MATCH_ALL)
    is_part = result.include?(MATCH_PART)
    is_none = result.include?(MATCH_NONE)
                    
    if (is_all || is_part)
      if (is_part || is_none)
        MATCH_PART
      else
        MATCH_ALL
      end
    else
      MATCH_NONE
    end
    
  end
  
  def merge(other)
    case match(other)
    when MATCH_ALL
      self
    when MATCH_PART
      mc = self.class.new("")
      list = branches.clone
      other.branches.each do |branch|
        merge_single(list, branch)
      end   
      mc.replace_branches(list)
      mc
    else
      nil  
    end  
  end
  
  def match_single(list, other)
    result = list.map {|branch| branch.match(other)}
    all_index = result.index(MATCH_ALL)
    part_index= result.index(MATCH_PART)
       
    if (all_index != nil)
      [MATCH_ALL, all_index]
    elsif (part_index != nil)
      [MATCH_PART, part_index]
    else
      [MATCH_NONE, -1]
    end
  end
  
  def merge_single(list, other)
      result, index = match_single(list, other)
    
      case result
      when MATCH_ALL
        # nothing        
      when MATCH_PART
        list[index] = list[index].merge(other)
      else
        list << other 
      end   
  end
  
  def replace_branches(list)
    @branches = list
    @current_op_seq = @branches.last    
  end  
end

class LoopStructure < SingleConditionStruction
  def generate_code(proxy)
    proxy.generate_loop_code(self)    
  end
end

class BreakStructure < SingleConditionStruction
  def generate_code(proxy)
    proxy.generate_break_code(self)    
  end
end

class OptStructure < SingleConditionStruction
  def generate_code(proxy)
    proxy.generate_opt_code(self)    
  end
end

class AltStructure < MultiConditionOperations
  def generate_code(proxy)
    proxy.generate_alt_code(@branches)    
  end
end

def creat_structure_node(structure_key_word, condition)
  case structure_key_word
  when /alt/i, /loop/i, /break/i, /opt/i
    Object.const_get("#{structure_key_word.capitalize}Structure").new(condition)
  end
end
