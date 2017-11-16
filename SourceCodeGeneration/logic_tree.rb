
class Array

  def add_indent(indent = " "*4)
    self.map {|item| indent + item }
  end

  def add_indent!(indent = " "*4)
    self.map! {|item| indent + item }
  end

end



class LogicTree

  def initialize
    @top_level_operations = SequenceOperation.new
    @current_strut = @top_level_operations
  end

  def add_operation(operation)
    @current_strut.add_operation operation
  end

  def update_structure(key_word, condition)
    case key_word
    when /alt/i, /loop/i, /break/i, /opt/i
      new_struct = Object.const_get(key_word.capitalize + "Structure").new(condition)
      new_struct.parent = @current_strut
      @current_strut.add_operation new_struct
      @current_strut = new_struct
    when /else/i
      @current_strut.update_structure(key_word, condition)
    when /end/i
      last_struct = @current_strut
      @current_strut = @current_strut.parent
      @current_strut.pop_operation if last_struct.empty?
    end
  end

  def generate_code
    code = @top_level_operations.generate_code
    code
  end
end

class Operation
  attr_accessor :statement
  def initialize(statement)
    @statement = statement
  end

  def generate_code()
    @statement
  end

end


class SequenceOperation
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
    code = []
    @operations.each do |op|
      code.push op.generate_code
    end
    code
  end

  def empty?
    @operations.empty?
  end

end

class StructBase

  attr_accessor :parent

  def initialize()
  end

  def pop_operation
    @current_op_seq.pop_operation
  end

  def add_operation(operation)
    @current_op_seq.add_operation operation
  end

end


class AltStructure < StructBase

  def initialize(condition)
    @condition = condition
    @branches = {condition => SequenceOperation.new}
    @current_op_seq = @branches[condition]    
  end

  def update_structure(key_word, condition)
    new_or_last_branch = (condition == "" ? "else" : condition)
    @current_op_seq = SequenceOperation.new
    @branches[new_or_last_branch] = @current_op_seq
  end
  
  def generate_code
    code = []
    @branches.each do |condition, op_seq|
      code << (condition == "else" ? "else {" : "if (%s) {" % condition)
      code.push op_seq.generate_code.flatten.add_indent!
      code << "}"
    end
    code
  end 
  
  def empty?
    @branches.each do |condition, op_seq|
      return false unless op_seq.empty?
    end
    true
  end
  
end

class LoopStructure < StructBase
  def initialize(condition)
    @condition = condition
    @operation_seq = SequenceOperation.new
    @current_op_seq = @operation_seq
  end
  
  
  def generate_code
    code = []
    code << "while (%s) {" % @condition
    puts @operation_seq.generate_code
    code.push @operation_seq.generate_code.flatten.add_indent!
    code << "}"
    code
  end
  
  def empty?
    @operation_seq.empty?
  end

end

class BreakStructure < StructBase
  def initialize(condition)
    @condition = condition
    @operation_seq = SequenceOperation.new
    @current_op_seq = @operation_seq
  end

  def generate_code
    code = []
    code << "if (%s) {" % @condition
    code << "    break"
    code.push @operation_seq.generate_code.flatten.add_indent!
    code << "}"
    code
  end

  def empty?
    @operation_seq.empty?
  end
  
end

class OptStructure < StructBase
  def initialize(condition)
    @condition = condition
    @operation_seq = SequenceOperation.new
    @current_op_seq = @operation_seq
  end

  def generate_code
    code = []
    code << "if (%s) {" % @condition
    code.push @operation_seq.generate_code.flatten.add_indent!
    code << "}"
    code
  end

  def empty?
    @operation_seq.empty?
  end

end
