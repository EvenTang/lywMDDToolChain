require './statement_ast'
require './cpp_code_generator'

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
    @current_strut.add_operation operation
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

  # FIXME: add_state_tramsmit --> add_state_transmit
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


# @brief
#  TODO: It should be a singleton
class LogicTreeGenerator

  def initialize()
  end

  def get_logic_tree_by_seq(seq_parser, component, state, event)
    seq_parser.all_behavior_of(component, state, event) do |behavior|
      logic_tree = generate_logic_tree_from behavior
      yield logic_tree
    end
  end

  private
  def generate_logic_tree_from(behavior)
    logic_tree = LogicTree.new
    behavior.each do |action|
      case action.type
      when ScriptStatement::TYPE_SEND_MESSAGE
        logic_tree.add_operation get_send_message_op(action)
      when ScriptStatement::TYPE_INTERNAL_CALL_API
        logic_tree.add_operation get_internal_call_op(action)
      when ScriptStatement::TYPE_EXTERNAL_CALL_API
        logic_tree.add_operation get_external_call_op(action)
      when ScriptStatement::TYPE_STRUCTURE_DEF
        logic_tree.update_structure action.contents[:key_word], action.contents[:condition]
      when ScriptStatement::TYPE_STATE_DEF
        logic_tree.add_state_tramsmit action
      end
    end

    logic_tree    
  end

  def get_send_message_op(send_msg_stat)
    parser = SendMessageStatParser.new(action.contents[:message])
    new_operation = GeneralOperation.new
    new_operation.operation_name = parser.message_name
    new_operation.params = parser.params.clone

    new_operation
  end

  def get_internal_call_op(send_msg_stat)
    parser = InternalCallStatParser.new(action.contents[:message])
    new_operation = GeneralOperation.new
    new_operation.operation_name = parser.message_name
    new_operation.params = parser.params.clone

    new_operation
  end

  def get_external_call_op(send_msg_stat)
    parser = ExternalCallStatParser.new(action.contents[:message])
    new_operation = GeneralOperation.new
    new_operation.operation_name = parser.message_name
    new_operation.params = parser.params.clone

    new_operation
  end

end