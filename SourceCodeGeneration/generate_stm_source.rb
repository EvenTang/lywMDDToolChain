require 'set'
require 'erb'
require 'fileutils'
require './lyw_rblib_extension'
require './sequence_parser'
require './software_model'

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

def GenerateSTMSource(input_dir, output_dir, component_name)
  component= SoftwareModel.new(component_name)
  input_dir.each do |cur_dir|
    puts "current dir : #{cur_dir}" 
    enumrate_all_file_names_by("wsd", cur_dir) do |file_name|		
      puts "current file name :" + file_name
      component.add_sequence_paser SequenceParser.new(file_name)
    end
  end  

  component.generate_stm_frame
  component.update_ecb_logic_tree_from_sequence
  component.update_all_stm_apis

  #=begin
  module_stm = component.state_machine
  stm_apis   = component.stm_apis
  
  erb_template_list = Dir["./InputForSTMSourceGen/*.erb"]

  module_dir = output_dir + "/" + module_stm.module_name.to_s
  FileUtils.mkdir(module_dir) unless File.exists?(module_dir)

  erb_template_list.each do | temp_file |
    if temp_file =~ /\.\/InputForSTMSourceGen\/SourceGen_(.+)\.erb/
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