require 'set'
require 'erb'
require 'fileutils'
require './lyw_rblib_extension'
require './get_STM_info'

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

input_dir = []
SequenceAnaylzer_ary = []
cur_content = 0
output_dir = ""

if ARGV.size > 0
    puts "#{ARGV}"
    ARGV.each do |str|
        case str
        when "-Input"
            cur_content = 1
        when "-Output"
            cur_content = 2
        when "-Module"
            cur_content = 3
        else
            if cur_content == 1 then
                input_dir = str.split(",")
            elsif cur_content == 2 then
                output_dir = str
            elsif cur_content == 3 then
                SequenceAnaylzer_ary.push(SeqenceAnalzyer.new(str))
            else
            end
        end
    end
end

SequenceAnaylzer_ary.each do |analyzer|
    puts "current module name : " + analyzer.state_machine.module_name
    input_dir.each do |cur_dir|
        puts "current dir :" + cur_dir
        EnumrateAllFileInDir("wsd", cur_dir) do |fh|
            fh.each_line do | line |
                analyzer.GetAllStates(line)
                analyzer.GetAllEvents(line)
            end
        end
    end
<<<<<<< HEAD

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
=======
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
>>>>>>> release/V1.3
end