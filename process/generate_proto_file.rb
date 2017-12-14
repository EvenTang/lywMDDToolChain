# ruby file parameter format
# ./generate_proto_file.rb -Input dir1,dir2 -Output output_dir -Module ModuleA,ModuleB...
# or ./generate_proto_file.rb -Input dir1,dir2 -Output output_dir -Module all (we will generate all components proto file)
# -Input, -Output :optional parameter
require 'set'
require 'erb'
require 'fileutils'
require File.expand_path('../MetaModel/software_model', __FILE__)
require File.expand_path('../MetaModel/sequence_parser', __FILE__)
require File.expand_path('../MetaModel/component_parser', __FILE__)
require File.expand_path('../CommonLib/lyw_rblib_extension', __FILE__)

puts "Start generating proto file!"

default_input_dir = "../production/SequenceDiagram/ArchDesign/"
default_output_dir = "../production/ProtoFile/GeneratedFile/"

def enumrate_all_file_names_by(file_ext, dir = ".")
  target_file_name_list = Dir[dir + "/*." + file_ext]
  target_file_name_list.each do | target_file_name |
    yield target_file_name
  end
end

def run_generate_proto_file(input_dir, output_dir, component_name)
  component= SoftwareModel.new(component_name)
  input_dir.each do |cur_dir|
    puts "current dir : #{cur_dir}" 
    enumrate_all_file_names_by("wsd", cur_dir) do |file_name|		
      #puts "current file name :" + file_name
      component.add_sequence_paser SequenceParser.new(file_name)
    end
  end  
  
  component.generate_stm_frame
  component.update_class_diagram_by_seq
  component.update_ecb_logic_tree_from_sequence
  component.update_all_stm_apis
  
  #=begin
  module_stm = component.state_machine
  stm_apis   = component.stm_apis
  class_diag = component.class_diagram

  erb_template_list = Dir["./ErbFile/MessageDefTemplate.proto.erb"]
  
  erb_template_list.each do | temp_file |
    if temp_file =~ /\.\/ErbFile\/(.+)\.erb/
      new_file_name = output_dir + "/" + module_stm.module_name.to_s + "_" + $1
      f = File.new(new_file_name, "w") 
      puts "Generating #{new_file_name}"
      File.open(temp_file) { |fh| 
      erb_engine = ERB.new( fh.read ) 
      f.print erb_engine.result( binding )
    }
    end
  end
end

#begin

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
    when /-Input/i
      cur_content = INPUT_CONTENT
    when /-Output/i
      cur_content = OUTPUT_CONTENT
    when /-Module/i
      cur_content = MODULE_CONTENT
    else
      if cur_content == INPUT_CONTENT
        input_dir = str.split(",")
      elsif cur_content == OUTPUT_CONTENT
        output_dir = str
      elsif cur_content == MODULE_CONTENT
        # if module parameter value is all, we will select all components
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

input_dir.push default_input_dir if input_dir.size == 0
output_dir = default_output_dir if output_dir == ""

component_array.each do |module_str|
  run_generate_proto_file(input_dir, output_dir, module_str)
end

#end