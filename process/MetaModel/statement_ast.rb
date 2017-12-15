
#!!!!!!!!!!!! This file is to be deleted.

=begin
  
rescue => exception
  
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

  def all_internal_call_operations
    @operations.inject([]) {|code, op| code << op.all_internal_call_operations }
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

class AtlStructure < MultiConditionOperations
end

class LoopStructure < SingleConditionStruction
end

class BreakStructure < SingleConditionStruction
end

class OptStructure < SingleConditionStruction
end

class AltStructure < MultiConditionOperations
end

class GeneralOperation
  attr_accessor :descirption     # Something like comments in programmer
  attr_accessor :return_value
  attr_accessor :operation_name  # TODO: should it be a string? or a ref to the memebers in class diagrams?
  attr_accessor :params          # Hash {ParamName :ParamValue}

  def initialize
  end

end

=end