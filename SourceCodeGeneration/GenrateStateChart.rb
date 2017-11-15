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

if ARGV.size > 0
   puts ARGV.size
   puts "#{ARGV}"
   SequenceAnaylzer_ary = ARGV.map { | item | SeqenceAnalzyer.new(item)}
end

SequenceAnaylzer_ary.each do |analyzer|
    puts "current module name : " + analyzer.state_machine.module_name
    EnumrateAllFileInDir("wsd", "./InputForSTMSourceGen") do |fh|
        fh.each_line do | line |
            analyzer.GetAllStates(line)
            analyzer.GetAllEvents(line)
        end
    end

    module_stm = analyzer.state_machine
    module_stm.PostProcess
    erb_template_list = Dir["./InputForSTMSourceGen/StateChart.wsd.erb"]
    
    module_dir = "./GeneratedFile/"+module_stm.module_name.to_s
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