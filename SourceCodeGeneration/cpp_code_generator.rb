require './statement_ast'
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
                    @statement.contents[:source_component_name] == target_module ? "API" : "api"
                  when ScriptStatement::TYPE_SEND_MESSAGE
                    "API_SendMessage"
                  else
                    ""
                  end
    "#{target_module}_#{type_symbol}_#{message_name}(#{param_list})"
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
  "SystemCtrl_" + condition.split.map(&:capitalize).join + "()" 
end

class CppAltStructure < MultiConditionOperations
  def generate_code
    count = 0
    @branches.inject [] do |code, branch|
      count += 1
      code  << ["#{generate_judgement(branch.condition, count)} {", 
                branch.generate_code.flatten.add_indent!,
                "}"]
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
    ["while (#{convert_condition_sentence_to_api(@condition)}) {", 
      super.flatten.add_indent!,
     "}"]
  end
end

class BreakLoopStructure < SingleConditionStruction
  def generate_code
    ["if (#{convert_condition_sentence_to_api(@condition)}) {", 
      super.push("break;").flatten.add_indent!,
     "}"]
  end
end

class OptLoopStructure < SingleConditionStruction
  def generate_code
    ["if (#{convert_condition_sentence_to_api(@condition)}) {", 
      super.flatten.add_indent!,
     "}"]
  end
end