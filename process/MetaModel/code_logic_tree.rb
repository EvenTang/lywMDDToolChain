require File.expand_path('../statement_ast', __FILE__)
require File.expand_path('../cpp_code_generator', __FILE__)

# Logic Tree is more likely a AST for method
#     It relies on Code generator to tranlate into realy language like C/C++/Python/PlanUML/lywSTM...
#   TODO: creat_cpp_structure_node/CppOperation will be replaced by some other method
#         for a generic Lauguage generation.
class LogicTree

  def initialize
    @top_level_operations = OperationSequence.new
    @current_strut = @top_level_operations
  end

  def add_operation(operation)
    @current_strut.add_operation CppOperation.new(operation)
  end

  def update_structure(key_word, condition)
    case key_word
    when /alt/i, /loop/i, /break/i, /opt/i
      new_struct = creat_cpp_structure_node(key_word, condition)
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

  def add_state_tramsmit(operation)
    @current_strut.add_operation CppStateTransmit.new(operation)
  end

  def generate_code
    code = @top_level_operations.generate_code
    code
  end

  def all_internal_call_operations
    @top_level_operations.all_internal_call_operations.flatten.compact
  end

end
