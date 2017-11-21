require 'set'
require 'erb'
require 'fileutils'
require './lyw_rblib_extension'

puts "Start Parsing!"

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

class Transition
    attr_accessor :s_state, :event, :e_state

    def initialize()
    end

    def isComplete?()
        @s_state && @e_state && @event
    end
end

class StateMachine

    attr_accessor :module_name, :states, :events, :transitions

    def initialize(module_name)
        @module_name = module_name
        @states = Set.new 
        @events = Set.new
        @transitions = []
    end

    def PostProcess() 
        @transitions.select! { |tran| tran.isComplete? }
    end

end


class SeqenceAnalzyer
    attr_accessor :state_machine
    
    def initialize(module_name)
        @state_machine = StateMachine.new(module_name)
    end

    def GetAllStates(seq_file_line)
        module_name = @state_machine.module_name.to_s
        if seq_file_line =~ /hnote over #{module_name}\s*:\s*(\w+)\s*/ then
            @state_machine.states.add($1)


            last_transition = @state_machine.transitions.last
            if last_transition != nil
                last_transition.e_state = $1
                puts "%s --> %s : %s" % [last_transition.s_state, last_transition.e_state, last_transition.event]
            end

            new_transition = Transition.new()
            new_transition.s_state = $1            
            @state_machine.transitions.push new_transition
            
        end
    end

    def GetAllEvents(seq_file_line)
        # RFComm->>+SystemCtrl:Set temprature (fieldName=value, fiedlName=value)
        module_name = @state_machine.module_name.to_s
        if seq_file_line =~ /.+->>\s*#{module_name}:\s*(\w+)(\(.*\))?$/ then
            new_event = @state_machine.events.find {|e| e.name == $1}
            if new_event == nil
                @state_machine.events << Event.new($1)
                new_event = @state_machine.events.find {|e| e.name == $1}
            end
            
            left_str = $2
            while left_str =~ /((\w+)=([\w"]+)),?(.*)/
                new_event.params[$2] = $3
                left_str = $4
            end

            puts new_event.name
            last_transition = @state_machine.transitions.last
            if last_transition != nil
                if last_transition.event == nil
                    last_transition.event = new_event.name
                elsif
                    last_transition.e_state = last_transition.s_state
                    new_transition = Transition.new
                    new_transition.s_state = last_transition.s_state
                    new_transition.event = new_event.name
                    @state_machine.transitions.push new_transition
                end
            end
        end
    end
end

INPUT_CONTENT  = 1
OUTPUT_CONTENT = 2
MODULE_CONTENT = 3

input_dir = []
output_dir = ""
component_array = []
cur_content = INPUT_CONTENT

if ARGV.size > 0
    puts "#{ARGV}"
    ARGV.each do |str|
        case str
        when "-Input"
            cur_content = INPUT_CONTENT
        when "-Output"
            cur_content = OUTPUT_CONTENT
        when "-Module"
            cur_content = MODULE_CONTENT
        else
            if cur_content == INPUT_CONTENT
                input_dir = str.split(",")
            elsif cur_content == OUTPUT_CONTENT
                output_dir = str
            elsif cur_content == MODULE_CONTENT
                component_array.push(SeqenceAnalzyer.new(str))
            else
            end
        end
    end
end

component_array.each do |analyzer|
    puts "current module name : " + analyzer.state_machine.module_name
    input_dir.each do |cur_dir|
        puts "current dir :" + cur_dir
        EnumrateAllFileInDir("wsd", cur_dir) do |file_name|
            file_name.each_line do | line |
                analyzer.GetAllStates(line)
                analyzer.GetAllEvents(line)
            end
        end
    end

    module_stm = analyzer.state_machine
    module_stm.PostProcess
    erb_template_list = Dir["./InputForSTMSourceGen/StateChart.wsd.erb"]

    module_dir = output_dir + "/" + module_stm.module_name.to_s
    FileUtils.mkdir(module_dir) unless File.exists?(module_dir)

    erb_template_list.each do | temp_file |
        if temp_file =~ /\.\/InputForSTMSourceGen\/(.+)\.erb/
            new_file_name = module_dir + "/" + module_stm.module_name.to_s + "_" + $1
            f = File.new(new_file_name, "w")
            puts "Generating #{new_file_name}"
            File.open(temp_file) { |fh| 
                erb_engine = ERB.new( fh.read )
                f.print erb_engine.result( binding )
            }
        end
    end
end