require 'set'
require 'erb'
require 'fileutils'
require './component_parser'
require './generate_stm_source'
require './generate_service_source'

puts "Start Parsing!"

INPUT_CONTENT  = 1
OUTPUT_CONTENT = 2
MODULE_CONTENT = 3

input_dir = []
output_dir = ""
component_array = []
cur_content = INPUT_CONTENT

def run_code_generator(input_dir, output_dir, module_str)
  com_parser = ComponentParser.new(".\\InputForSTMSourceGen\\ArchDesign\\com_Components.wsd")
  if com_parser.component_def_of?(module_str)
    case com_parser.get_component_type(module_str)
    when ComponentAnalyzer::COM_TYPE_STM
      puts "=====current module is STM type====="
      generate_STM_source(input_dir, output_dir, module_str)
    when ComponentAnalyzer::COM_TYPE_SERVICE
      puts "=====current module is SERVICE type====="
      generate_Service_source(input_dir, output_dir, module_str)
    when ComponentAnalyzer::COM_TYPE_LIB
      #generate_LIB_source(input_dir, output_dir, module_str)
    else
    end
  else
    puts "!!!!!!! invalid component : #{module_str} !!!!!!!"
  end
end

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
        str_array = str.split(",")
        str_array.each do |module_str|
          run_code_generator(input_dir, output_dir, module_str)
        end
      else
      end
    end
  end
end

component_array.each do |component|
  puts "current module : " + component.module_name
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
  #=end
end