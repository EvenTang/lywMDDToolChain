require File.expand_path('../statement_ast', __FILE__)
require File.expand_path('../sequence_script_statement', __FILE__)
require File.expand_path('../stm_model', __FILE__)
require File.expand_path('../code_generator_proxy', __FILE__)

# TODO: collect all internal apis to generate "stm_internal_calls.h/stm_internal_calls.cpp"
# TODO: generate code that considering the vairable used in call chains.
# TODO: generate comments

class PythonCodeGenerator < CodeGeneratorProxy

  def generate_function_call(name, param_list)
    args = param_list.values.join(", ")
    ["//> #{name}(#{args})", "#{name}(#{args});"]
  end

  def generate_function_prototype(name, param_list)
    args = param_list.keys.join(", ")
    "def #{name}(#{args}):"
  end

  def generate_transmit_code(name, state)
    ["//> #{name}(#{state})",
    "#{name}(#{state});"]
  end
  
  def generate_alt_code(branches)
    count = 0
    code = ["#> alt: ?????"]
    code = branches.inject code do |code, branch|
      count += 1
      code  << ["#> opt: #{convert_condition_sentence_to_api(branch.condition)}",
                "#{generate_judgement(branch.condition, count)} :", 
                branch.sequence.generate_code(self).flatten.add_indent!]
    end
    code << "#> :end" 
  end
  
  def generate_loop_code(branch)
    ["#> loop: #{convert_condition_sentence_to_api(branch.condition)}", 
     "while (#{convert_condition_sentence_to_api(branch.condition)}) :", 
      branch.sequence.generate_code(self).flatten.add_indent!,
     "#> :end"]
  end
  
  def generate_break_code(branch)
    ["#> alt: #{convert_condition_sentence_to_api(branch.condition)}", 
     "if (#{convert_condition_sentence_to_api(condition)}) :", 
      branch.sequence.generate_code(self).push("break;").flatten.add_indent!,
     "#> :end"]
  end
  
  def generate_opt_code(branch)
    ["if (#{convert_condition_sentence_to_api(branch.scondition)}) :", 
      branch.sequence.generate_code(self).flatten.add_indent!]
  end
  
  private
  def generate_judgement(condition, branch_cout)
    if condition != ""
      "%s (%s)" % [(branch_cout > 1 ? "elif" : "if"), convert_condition_sentence_to_api(condition)]
    else
      "else"
    end
  end
  
  private
  def convert_condition_sentence_to_api(condition)
    return "" if condition == ""
    # TODO: "SystemCtrl" as a module name should be configurable
    if condition =~ /\w+(==|!=|>=|<=)\w+/
      condition
    else
      "SystemCtrl_api" + condition.split.map(&:capitalize).join + "()"
    end
  end
  
end



