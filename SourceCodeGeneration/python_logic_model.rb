require 'erb'

require './logic_op_base.rb'
require './lyw_rblib_extension.rb'


def creat_cpp_structure_node(structure_key_word, condition)
  case structure_key_word
  when /alt/i, /loop/i, /break/i, /opt/i
    Object.const_get("Python#{structure_key_word.capitalize}Structure").new(condition)
  end
end


class PythonOperation < GeneralOperation
    
  def generate_code()
    erb_engine = ERB.new <<-code_template.strip_heredoc
      //> <%= description %>
      <%= return_value %> = <%= function_name %>(<%= params_list_code %>)
    code_template
    erb_engine.result(binding).split("\n")
  end

  private
  def params_list_code
    @params.values.to_a.join(", ")
  end

  # @brief Using operation_name to check matchable method in class diagram
  #  TODO: replace the operation_name to the method name in class diagram
  def function_name
    @operation_name
  end

end

class PythonAltStructure < AtlStructure

  def initialize
    @key_word_count = -1
  end
  def generate_code()
    @key_word_count = -1
    erb_engine = ERB.new <<-code_template.strip_heredoc
      #> alt: <%= description %>
      <% @branches.each do |branch| %>
      #> opt: ????
      <%= opt_key_word %> <%= branch.condition %> :
      <%= branch.generate_code.flatten.add_indnet!.join("\n") %>
      <% end %>
      end
      #> :end
    code_template
    erb_engine.result(binding).split("\n")
  end

  private
  def opt_key_word
    @key_word_count += 1
    if @key_word_count == 0
      "if"
    elsif @branches[@key_word_count].condition
      "elif"
    else
      "else"
    end
  end


end

class PythonOptStructure < OptStructure
  def generate_code
    erb_engine = ERB.new <<-code_template.strip_heredoc
      #> alt: <%= description %>
      #> opt: <%= description %>    
      if <%= branch.condition %> :
      <%= super.generate_code.flatten.add_indnet!.join("\n") %>
      #> :end
    code_template
    erb_engine.result(binding).split("\n")
  end
end

class PythonBreakStructure < BreakStructure
  def generate_code
    erb_engine = ERB.new <<-code_template.strip_heredoc
      if <%= branch.condition %> :
      <%= super.generate_code.flatten.add_indnet!.join("\n") %>
          break
      #> :end
    code_template
    erb_engine.result(binding).split("\n")
  end
end

class PythonLoopStructure < LoopStructure
  def generate_code
    erb_engine = ERB.new <<-code_template.strip_heredoc
      #> loop: <%= description %>
      while <%= branch.condition %> :
      <%= super.generate_code.flatten.add_indnet!.join("\n") %>
      end
      #> :end
    code_template
    erb_engine.result(binding).split("\n")
  end
end
