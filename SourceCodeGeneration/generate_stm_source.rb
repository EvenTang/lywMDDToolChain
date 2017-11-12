require 'set'
require 'erb'
require './lyw_rblib_extension'
require './sequence_parser'
require './software_model'

puts "Start Parsing!"

def EnumrateAllFileNamesInDir(file_ext, dir = ".")
    target_file_name_list = Dir[dir + "/*." + file_ext]
    target_file_name_list.each do | target_file_name |
        puts "Openning #{target_file_name}"
        File.open(target_file_name) do |fh| 
            yield fh
        end
    end
end

def enumrate_all_file_names_by(file_ext, dir = ".")
    target_file_name_list = Dir[dir + "/*." + file_ext]
    target_file_name_list.each do | target_file_name |
        yield target_file_name
    end
end

@software_model = SoftwareModel.new(:SystemCtrl)

enumrate_all_file_names_by("wsd", "./InputForSTMSourceGen") do |file_name|
    @software_model.get_information_from_sequence SequenceParser.new(file_name)
end

#=begin
system_ctrl_stm = @software_model.state_machine

erb_template_list = Dir["./InputForSTMSourceGen/*.erb"]
erb_template_list.each do | temp_file |
    if temp_file =~ /\.\/InputForSTMSourceGen\/SourceGen_(.+)\.erb/
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


