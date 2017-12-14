# ruby file parameter format
# ./generate_state_table.rb -Input input_dir -Output output_dir -Module ModuleA,ModuleB...
# or ./generate_state_table.rb -Input input_dir -Output output_dir -Module all (we will generate all components state table)
# -Input, -Output :optional parameter
require 'erb'
require 'find'

class Array
    def AddPrifixForStrings(prifix)
        self.map! {|str| prifix + str}
    end
end


=begin table charactors
─ ━ │ ┃ ╌ ╍ ╎ ╏ ┄ ┅ ┆ ┇ ┈ ┉ ┊ ┋ ┌ ┍ ┎ ┏ ┐ ┑ ┒ ┓ └ ┕ ┖ ┗ ┘ ┙ ┚ ┛ 
├ ┝ ┞ ┟ ┠ ┡ ┢ ┣ ┤ ┥ ┦ ┧ ┨ ┩ ┪ ┫ ┬ ┭ ┮ ┯ ┰ ┱ ┲ ┳ ┴ ┵ ┶ ┷ ┸ ┹ ┺ ┻ 
┼ ┽ ┾ ┿ ╀ ╁ ╂ ╃ ╄ ╅ ╆ ╇ ╈ ╉ ╊ ╋ ╪ ╫ ╬ ═ ║ ╒ ╓ ╔ ╕ ╖ ╗ ╘ ╙ ╚ ╛ ╜
╝ ╞ ╟ ╠ ╡ ╢ ╣ ╤ ╥ ╦ ╧ ╨ ╩ ╔ ╗ ╝ ╚ ╬ ═ ╓ ╩ ┠ ┨ ┯ ┷ ┏ ┓ ┗ ┛ ┳ ⊥ ﹃
﹄ ┌ ╮ ╭ ╯ ╰ ╳ 
○ ☆ ★ ● ◎ ◇ ◆ □ ■ △ ▲
=end


<<-FunctionDiscription

 statement1
 statement2
 
    ==>
 ┌─   
 │ statement1
 │ statement2
 └─

 FunctionDiscription
class NormalStatement
    attr_accessor :statements

    NORMAL_S     = "┌─"
    PLAN_PRIFIX  = "│ "
    NORMAL_E     = "└─"

    def initialize()
        @statements = [] #["statement1", "statement2", AltStatement.new]
    end
    
    def GetAllStatements()
        all_statements = [NORMAL_S]
        @statements.each do |st|
            if st.kind_of? String
                all_statements.push PLAN_PRIFIX + st
            else
                all_statements.concat st.GetAllStatements.AddPrifixForStrings(PLAN_PRIFIX)
            end
        end
        all_statements.push NORMAL_E
        all_statements
    end

    def AddPlainStatementToEnd(line)
        @statements.push line
    end
    
end


<<-FunctionDiscription

 if condition
    statement1
 else 
    statement2
 
    ==>
  
 │◆ condition
 │├◇ yes
 ││ statement1
 │├◇ no
 ││ statement2
 │└─

 FunctionDiscription
class AltStatement
    attr_accessor :prediction, :branches, :parent

    PREDICT_PRIFIX = "┌◆ "
    BRANCH_PRIFIX  = "├◇ "
    ALT_END_PRIFIX = "└─"
    PLAN_PRIFIX    = "│ "

    def initialize()
        @prediction = "condition"
        @branches = [] # [["opt1", [statements]], ["opt2", [statements]]
    end
    
    def GetAllStatements()
        all_statements = [PREDICT_PRIFIX + @prediction]
        @branches.each do |branch|
            all_statements.push BRANCH_PRIFIX + branch[0]
            branch[1].each do |st|
                if st.kind_of? String
                    all_statements.push PLAN_PRIFIX + st
                else
                    all_statements.concat st.GetAllStatements.AddPrifixForStrings(PLAN_PRIFIX)
                end
            end
        end
        all_statements.push ALT_END_PRIFIX        
        all_statements
    end

    def AddPlainStatementToEnd(line)
        @branches.last.last.push line
    end
    
end

<<-FunctionDiscription

 // loop: for every element in list
 for (int i = 0; i<list.size; i++) {
     statement();
 }
 
    ==>
  
 │◎ loop: for every element in list
 │├─ 
 ││ statement1
 ││ statement2
 │└─

 FunctionDiscription
class LoopStatement
    attr_accessor :prediction, :loop_body, :parent

    PREDICT_PRIFIX = "┌◎ "
    LOOP_S_PRIFIX  = "├─ "
    LOOP_E_PRIFIX  = "└─ "
    PLAN_PRIFIX    = "│ "

    def initialize()
        @prediction = "loop condition"
        @loop_body = [] #["statement2", AltStatement.new, " statement4"]
    end
    
    def GetAllStatements()
        all_statements = [PREDICT_PRIFIX + @prediction, LOOP_S_PRIFIX]
        @loop_body.each do |st|
            if st.kind_of? String
                all_statements.push PLAN_PRIFIX + st
            else
                all_statements.concat st.GetAllStatements.AddPrifixForStrings(PLAN_PRIFIX)
            end
        end
        all_statements.push LOOP_E_PRIFIX        
        all_statements
    end

    def AddPlainStatementToEnd(line)
        @loop_body.push line
    end
    
end

class STMCell
    attr_accessor :all_statements, :current_structure

    def initialize()
       @all_statements = NormalStatement.new
       @current_structure = @all_statements
    end

    def GetAllStatements()
        @all_statements.GetAllStatements
    end

    def AddNewStructure(new_structure)
        @current_structure.AddPlainStatementToEnd new_structure
        new_structure.parent = @current_structure
        @current_structure = new_structure
    end

    def CurrentStructureEnded()
        @current_structure = @current_structure.parent
    end

end

class STMInfor
    attr_accessor :states, :events, :cells

    def initialize()
        @states = []
        @events = []
        @cells = Hash.new
    end

    # state and event are string (as the hash keys)
    def GetStatementsOfCell(state, event)
        if @cells[state][event] != nil
            @cells[state][event].GetAllStatements
        else
            []
        end
    end    
end


class STM_Analyzer 
    attr_accessor :stm_info

    NORMAL_STRUCTURE = 1
    ALT_STRUCTURE    = 2
    LOOP_STRUCTURE   = 3

    def initialize(module_name)
        @stm_info = STMInfor.new
        @in_state_def = false
        @in_event_def = false
        @in_ECB_impl = false
        @module_name = module_name
        @current_ecb_cell = nil
        @ecb_struct_flag = NORMAL_STRUCTURE
        @current_structure = nil
    end

    <<-StateEventDef
    // State definition
    enum SystemCtrl_State { 
        ST_Idle,
        ST_Working,
        ST_Unitialized,
        ST_STATE_MAX
    };
    
    // Event definition
    enum SystemCtrl_Event { 
        EV_SetTemperature,
        EV_SetTemperatureResult,
        EV_ShowTemperatureResult,
        EV_PowerOffResult,
        EV_TurnOffDisplayResult,
        EV_PowerOnResult,
        EV_EVENT_MAX
    };
    StateEventDef
    def ParseEventAndState(line)
        case line
        when /enum\s+#{@module_name}_State\s+{/ 
            @in_state_def = true
        when /ST_STATE_MAX/
            @in_state_def = false
        when /ST_(\w+)\s*,/
            if @in_state_def == true
                @stm_info.states.push $1
            end
        when /enum\s+#{@module_name}_Event\s+{/ 
            @in_event_def = true
        when /EV_EVENT_MAX/
            @in_event_def = false
        when /EV_(\w+)\s*,/
            if @in_event_def == true
                @stm_info.events.push $1
            end
        end
    end

    def ParseECBStructure(line)
        case line
        when /STM_Status\s+#{@module_name}_ECB_(\w+)_(\w+)\(#{@module_name}Event\s+const\s+&\s+_msg\)/ 
            @in_ECB_impl = true
            @current_ecb_cell = STMCell.new
            @current_structure = @current_ecb_cell.current_structure
            if @stm_info.cells[$1] == nil
                @stm_info.cells[$1] = Hash.new
            end
            @stm_info.cells[$1][$2] = @current_ecb_cell
        when /^\}/
            @in_ECB_impl = false
        when /.*\/\/>(.*)/
            if @in_ECB_impl == true
                ParseStructure($1)
            end
        end
    end

    private
    def ParseStructure(line)
        next_element = line
        case line
        when /\s*:end*/
            # set @current_structure to uplayer
            @current_ecb_cell.CurrentStructureEnded
            @current_structure = @current_ecb_cell.current_structure
        when /\s*alt:\s*(.*)\s*/
            @current_structure = AltStatement.new
            @current_structure.prediction = $1
            # attach it to the up layer
            @current_ecb_cell.AddNewStructure @current_structure
        when /\s*opt:\s*(.*)\s*/
            @current_structure.branches.push [$1, []]
        when /\s*loop:\s*(.*)\s*/
            @current_structure = LoopStatement.new
            @current_structure.prediction = $1
            # attach it to the up layer
            @current_ecb_cell.AddNewStructure @current_structure
        else
            @current_structure.AddPlainStatementToEnd line
        end
    end

end

def run_generate_state_table(input_dir, output_dir, component_name)
  stm_source_file_dir = input_dir + "/" + component_name + "/"
  Find.find(stm_source_file_dir) do |file_name|
    if file_name.to_s =~ /(\w+)_STM\.h/
      puts file_name
      @source_code_analyzer = STM_Analyzer.new($1)
      File.open(file_name).each_line do |line|
        @source_code_analyzer.ParseEventAndState line
      end
    end
  end

  Find.find(stm_source_file_dir) do |file_name|
    if file_name.to_s =~ /.*_STM\.cpp/
      puts file_name
      File.open(file_name).each_line do |line|
          @source_code_analyzer.ParseECBStructure line
      end
    end
  end

  stm_generator = @source_code_analyzer.stm_info
  puts stm_generator.states
  puts stm_generator.events

  erb_template_list = Dir["./ErbFile/STMDesigner.html.erb"]
  erb_template_list.each do | temp_file |
    if temp_file =~ /\.\/ErbFile\/(.+)\.erb/
      new_file_name = output_dir + component_name.to_s + "_" + $1
      f = File.new(new_file_name, "w") 
      puts "Generating #{new_file_name}"
      File.open(temp_file) do |fh| 
        erb_engine = ERB.new( fh.read ) 
        f.print erb_engine.result( binding )   
      end
    end
  end
end

default_input_dir = "../production/Code/EditableFile/"
default_output_dir = "../production/StateTable/GeneratedFile/"

INPUT_CONTENT  = 1
OUTPUT_CONTENT = 2
MODULE_CONTENT = 3

input_dir = ""
output_dir = ""
component_array = []
cur_content = INPUT_CONTENT

if ARGV.size > 0
  puts "#{ARGV}"
  ARGV.each do |str|
    case str
    when /-Input/i
      cur_content = INPUT_CONTENT
    when /-Output/i
      cur_content = OUTPUT_CONTENT
    when /-Module/i
      cur_content = MODULE_CONTENT
    else
      if cur_content == INPUT_CONTENT
        input_dir = str
      elsif cur_content == OUTPUT_CONTENT
        output_dir = str
      elsif cur_content == MODULE_CONTENT
        str_array = []
        # if module parameter value is all, we will generate all class diagrams
        if str.upcase == "ALL"
          puts "genetare all class diagrams"
          compo_file = "../production/ComponentDiagram/EditableFile/component_diagram.wsd"
          com_parser = ComponentParser.new(compo_file)
          com_parser.components.each do |compo|
            puts compo.component_name
            component_array.push compo.component_name
          end
        else
          component_array = str.split(",")
        end
      else
      end
    end
  end
end

input_dir = default_input_dir if input_dir == ""
output_dir = default_output_dir if output_dir == ""

component_array.each do |module_str|
  run_generate_state_table(input_dir, output_dir, module_str)
end

