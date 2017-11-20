require './statement_ast'
require './sequence_script_statement'
require './stm_model'

class Array

  def add_indent(indent = " " * 4)
    self.map {|item| indent + item }
  end

  def add_indent!(indent = " " * 4)
    self.map! {|item| indent + item }
  end

end


# TODO: collect all internal apis to generate "stm_internal_calls.h/stm_internal_calls.cpp"
# TODO: generate code that considering the vairable used in call chains.
# TODO: generate comments

class CppOperation
  attr_reader :statement
  attr_reader :comment

  def initialize(statement)
    @statement = statement
  end

  def generate_code()
    target_module = @statement.contents[:destination_component_name]
    event = Event.new(statement.contents[:message])
    message_name = event.name
    param_list = event.params.values.join(", ")
    type_symbol = case @statement.type
                  when ScriptStatement::TYPE_CALL_API
                    inner_api_call? ? "api" : "API"
                  when ScriptStatement::TYPE_SEND_MESSAGE
                    "API_SendMessage"
                  else
                    ""
                  end
    ["//> #{target_module}_#{type_symbol}_#{message_name}(#{param_list})",
     "#{target_module}_#{type_symbol}_#{message_name}(#{param_list})"]
  end

  def inner_api_call?
    if @statement.type == ScriptStatement::TYPE_CALL_API
      @statement.contents[:source_component_name] == @statement.contents[:destination_component_name]
    else
      false
    end
  end

  def all_internal_call_operations
    inner_api_call? ? self : nil
  end

  def generate_prototype
    module_name = @statement.contents[:source_component_name]
    event = Event.new(statement.contents[:message])
    message_name = event.name
    param_list = event.params.keys.join(", ")
    # FIXME: return value
    "BOOL #{module_name}_api_#{message_name}(#{param_list})"
  end
end

def creat_cpp_structure_node(structure_key_word, condition)
  case structure_key_word
  when /alt/i, /loop/i, /break/i, /opt/i
    Object.const_get("Cpp#{structure_key_word.capitalize}Structure").new(condition)
  end
end

def convert_condition_sentence_to_api(condition)
  return "" if condition == ""
  # TODO: "SystemCtrl" as a module name should be configurable
  "SystemCtrl_api" + condition.split.map(&:capitalize).join + "()" 
end

class CppAltStructure < MultiConditionOperations
  def generate_code
    count = 0
    code = ["//> alt: ?????"]
    code = @branches.inject code do |code, branch|
      count += 1
      code  << ["//> opt: #{convert_condition_sentence_to_api(branch.condition)}",
                "#{generate_judgement(branch.condition, count)} {", 
                branch.generate_code.flatten.add_indent!,
                "}"]
    end
    code << "//> :end"
  end

  def all_internal_call_operations
    @branches.inject [] do |inner_calls, branch|
      inner_calls << branch.all_internal_call_operations
    end
  end

  private
  def generate_judgement(condition, branch_cout)
    if condition != ""
      "%s (%s)" % [(branch_cout > 1 ? "else if" : "if"), convert_condition_sentence_to_api(condition)]
    else
      "else"
    end
  end
end

class CppLoopStructure < SingleConditionStruction
  def generate_code
    ["//> loop: #{convert_condition_sentence_to_api(@condition)}", 
     "while (#{convert_condition_sentence_to_api(@condition)}) {", 
      super.flatten.add_indent!,
     "}",
     "//> :end"]
  end

  def all_internal_call_operations
    inner_apis = super
    # FIXME: systemctrl->systemctrl
    temp_statement = ScriptStatement.new("SystemCtrl->SystemCtrl:"+convert_condition_sentence_to_api(@condition))
    inner_apis << CppOperation.new(temp_statement)
  end

end

class BreakLoopStructure < SingleConditionStruction
  def generate_code
    ["//> alt: #{convert_condition_sentence_to_api(@condition)}", 
     "if (#{convert_condition_sentence_to_api(@condition)}) {", 
      super.push("break;").flatten.add_indent!,
     "}",
     "//> :end"]
  end

  def all_internal_call_operations
    inner_apis = super
    temp_statement = ScriptStatement.new("SystemCtrl->SystemCtrl:"+convert_condition_sentence_to_api(@condition))
    inner_apis << CppOperation.new(temp_statement)
  end

end

class OptLoopStructure < SingleConditionStruction
  def generate_code
    ["if (#{convert_condition_sentence_to_api(@condition)}) {", 
      super.flatten.add_indent!,
     "}"]
  end

  def all_internal_call_operations
    inner_apis = super
    temp_statement = ScriptStatement.new("SystemCtrl->SystemCtrl:"+convert_condition_sentence_to_api(@condition))
    inner_apis << CppOperation.new(temp_statement)
  end
  
end