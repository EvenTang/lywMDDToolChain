require 'set'
require 'erb'

puts "Start Parsing!"

class String
    def underscore
        self.gsub(/::/, '/').
        gsub(/([A-Z]+)([A-Z][a-z])/,'\1_\2').
        gsub(/([a-z\d])([A-Z])/,'\1_\2').
        tr("-", "_").
        downcase
    end
end

def EnumrateAllFileInDir(file_ext, dir = ".")
    target_file_name_list = Dir[dir + "/*." + file_ext]
    target_file_name_list.each do | target_file_name |
        puts "Openning #{target_file_name}"
        File.open(target_file_name) do |fh| 
            yield fh
        end
    end
end

class Event 
    attr_accessor :name, :params

    def initialize(name)
        @name = name
        @params = Hash.new # Hash as : field_name => field_value
    end

    def == (other)
        if other == nil
            return false      
        end  
        name == other.name
    end

    def eql?(other)
        self == other
    end
end

class StateMachine

    attr_accessor :module_name, :states, :events

    def initialize(module_name)
        @module_name = module_name
        @states = Set.new 
        @events = Set.new
    end

end


class SeqenceAnalzyer
    attr_accessor :state_machine
    
    def initialize(module_name)
        @state_machine = StateMachine.new(module_name)
    end

    def GetAllStates(seq_file_line)
        module_name = @state_machine.module_name.to_s
        if seq_file_line =~ /state over #{module_name}:\s*(\w+)\s*/ then
            @state_machine.states.add($1)
        end
    end

    def GetAllEvents(seq_file_line)
        # RFComm->>+SystemCtrl:Set temprature (fieldName=value, fiedlName=value)
        module_name = @state_machine.module_name.to_s
        if seq_file_line =~ /.+->>.*#{module_name}:\s*(\w+)\((.*)\)$/ then
            new_event = @state_machine.events.find {|e| e.name == $1}
            if new_event == nil
                @state_machine.events << Event.new($1)
                new_event = @state_machine.events.find {|e| e.name == $1}
            end
            
            puts $2
            left_str = $2
            while left_str =~ /((\w+)=([\w"]+)),?(.*)/
                new_event.params[$2] = $3
                puts $2
                puts $3
                left_str = $4
            end
            
        end
    end
end

@analyzer = SeqenceAnalzyer.new(:SystemCtrl)

EnumrateAllFileInDir("seq") do |fh|
    fh.each_line do | line |
        @analyzer.GetAllStates(line)
        @analyzer.GetAllEvents(line)
    end
end

#=begin
system_ctrl_stm = @analyzer.state_machine

erb_template_list = Dir["./*.erb"]
#Special File
erb_template_list.delete("./STMDesigner.html.erb")

erb_template_list.each do | temp_file |
    if temp_file =~ /\.\/(.+)\.erb/
        new_file_name = "./GeneratedFile/" + system_ctrl_stm.module_name.to_s + "_" + $1
        f = File.new(new_file_name, "w") 
        puts "Generating #{new_file_name}"
        File.open(temp_file) { |fh| 
            erb_engine = ERB.new( fh.read ) 
            f.print erb_engine.result( binding )   
        }
    end
end
#=end


