

class Operation
  attr_reader :statement
  def initialize(statement)
    @statement = statement
  end

  def generate_code()
    @statement
  end

end


class StructBase
  attr_accessor :parent
end

class OperationSequence < StructBase
  def initialize
    @operations = []
  end

  def add_operation(operation)
    @operations << operation
  end

  def pop_operation
    @operations.pop
  end

  def generate_code()
    @operations.inject([]) {|code, op| code << op.generate_code}
  end

  def empty?
    @operations.empty?
  end

end

class SingleConditionStruction < OperationSequence
  attr_reader :condition

  def initialize(condition)
    super()
    @condition = condition
  end
end



class MultiConditionOperations < StructBase
  
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
    
    def generate_code
    end 
    
    def empty?
      @branches.all? &:empty?
    end
    
  end

class LoopStructure < SingleConditionStruction
end

class BreakStructure < SingleConditionStruction
end

class OptStructure < SingleConditionStruction
end

class AltStructure < MultiConditionOperations
end
