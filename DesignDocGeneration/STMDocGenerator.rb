require 'erb'

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
        @statements = ["statement1", "statement2", AltStatement.new]
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
    attr_accessor :prediction, :branches

    PREDICT_PRIFIX = "┌◆ "
    BRANCH_PRIFIX  = "├◇ "
    ALT_END_PRIFIX = "└─"
    PLAN_PRIFIX    = "│ "

    def initialize()
        @prediction = "condition"
        @branches = {"yes" => ["statement1"], "no" => ["statement2","statement3","statement4"]}
    end
    
    def GetAllStatements()
        all_statements = [PREDICT_PRIFIX + @prediction]
        @branches.each do |cond, stms|
            all_statements.push BRANCH_PRIFIX + cond
            stms.each do |st|
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
    attr_accessor :prediction, :loop_body

    PREDICT_PRIFIX = "┌◎ "
    LOOP_S_PRIFIX  = "├─ "
    LOOP_E_PRIFIX  = "└─ "
    PLAN_PRIFIX    = "│ "

    def initialize()
        @prediction = "loop condition"
        @loop_body = ["statement2", AltStatement.new, " statement4"]
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
    
end

class STMCell
    attr_accessor :all_statements

    def initialize(type)
        if type == 1 
            @all_statements = AltStatement.new
        elsif type == 0
            @all_statements = LoopStatement.new
        else
            @all_statements = NormalStatement.new
        end
    end

    def GetAllStatements()
        @all_statements.GetAllStatements
    end
end

class STMInfor
    attr_accessor :states, :events, :cells

    def initialize()
        @states = ["Idle", "S2"]
        @events = ["SetTemperature", "SetTemperatureResult"]
        @cells = [[STMCell.new(1), STMCell.new(0)], [STMCell.new(2), STMCell.new(1)]]
    end

    def GetStatementsOfCell(cell_row, cell_col)
        @cells[cell_row][cell_col].GetAllStatements
    end    
end

stm_generator = STMInfor.new

erb_template_list = Dir["./*.html.erb"]
erb_template_list.each do | temp_file |
    if temp_file =~ /\.\/(.+)\.erb/
        new_file_name = "./GeneratedFile/SystemCtrl_" + $1
        f = File.new(new_file_name, "w") 
        puts "Generating #{new_file_name}"
        File.open(temp_file) do |fh| 
            erb_engine = ERB.new( fh.read ) 
            f.print erb_engine.result( binding )   
        end
    end
end
