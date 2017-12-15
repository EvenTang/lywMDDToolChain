# ruby file parameter format
# ./generate_API.rb -Input input_dir -Output output_dir -Module ModuleA,ModuleB...
# or ./generate_API.rb -Input input_dir -Output output_dir -Module all (we will generate all components API file)
# -Input, -Output :optional parameter
require 'erb'
require File.expand_path('../CommonLib/lyw_rblib_extension', __FILE__)
require File.expand_path('../MetaModel/component_parser', __FILE__)


class ProtoFile
  attr_accessor :name, :messages, :parent
  attr_accessor :module_name

  def initialize(module_name)
    @messages = []
    @parent = self
    @name = "ProtoFile"
    @module_name = module_name
  end

  def Push(element)
    @messages.push element
    element.parent = self
  end

  def ParseContents(line)
  end
end

class MsgField
  # field_attribute : const String, one of :required, optional, repeated
  attr_accessor :name, :type, :field_attribute

  def initialize()
  end

  def initialize(name, type, field_attr)
    @name, @type, @field_attribute = name, type, field_attr
  end
end

class EnumValue
  # field_attribute : const String, one of :required, optional, repeated
  attr_accessor :name, :value

  def initialize()
  end

  def initialize(name, value)
    @name = name
    @value = value
  end
end

class EnumDef
  # name : String
  # values : Hash {ConstName(String) => value(int)}
  attr_accessor :name, :values
  attr_accessor :parent  # For parser
    
  def initialize(name)
    @name = name
    @values = []
  end

  def ParseContents(line)
    if line =~ /(\w+)\s*=\s*(\d+);/
      @values.push EnumValue.new($1, $2.to_i)
    end
  end

  def Push(element)
    @values.push element
  end
end

class OneofField
  attr_accessor :name, :fields
  attr_accessor :parent  # For parser
    
  def initialize(name)
    @name = name
    @fields = []
  end

  def ParseContents(line)
    if line =~ /(\w+)\s+(\w+)\s+=\s+(\d+);/
      @fields.push MsgField.new($2, $1, "")
    end
  end

  def Push(element)
    @fields.push element
    case element
    when Message, EnumDef, OneofField 
      element.parent = self
    end
  end
end

class Message
  attr_accessor :name, :fields
  attr_accessor :parent  # For parser
    
  def initialize(name)
    @name = name
    @fields = []
  end

  def ParseContents(line)
    if line =~ /(require|optional|repeated)?\s*(\w+)\s+(\w+)\s+=\s+(\d+);/
      @fields.push MsgField.new($3, $2, $1)
    end
  end

  def Push(element)
    @fields.push element
    case element
    when Message, EnumDef, OneofField
      element.parent = self
    end
  end
end

class ProtoAnalyzer 
  attr_accessor :proto_file

  def initialize(module_name)
    @proto_file = ProtoFile.new(module_name)
    @current_container = @proto_file # type could be ProtoFile, Message, EnumDef
  end

  def ParseProtoStructure(line)
    case line
    when /message\s+(\w+)\s+\{/   # message definition start
      new_element = Message.new($1)
      @current_container.Push new_element
      @current_container = new_element
    when /enum\s+(\w+)\s+\{/      # enum definition start
      new_element = EnumDef.new($1) 
      @current_container.Push new_element
      @current_container = new_element
    when /oneof\s+(\w+)\s+{/      # Oneof  definition start
      new_element = OneofField.new($1) 
      @current_container.Push new_element
      @current_container = new_element   
    when /\}/                      # '{' must be in a single line
      @current_container = @current_container.parent
    else
      @current_container.ParseContents(line)
    end
  end
end



def run_generate_external_API(input_dir, output_dir, component_name)
  @proto_analyzer = nil
  proto_file_name = input_dir + "/" + component_name + "MessageDef.proto"
  if File.exist?(proto_file_name)
    @proto_analyzer = ProtoAnalyzer.new(component_name)
    File.open(proto_file_name).each_line do |line|
      @proto_analyzer.ParseProtoStructure line
    end
  else
    return
  end

  @proto_obj = @proto_analyzer.proto_file

  erb_template_list = Dir["./ErbFile/API.*.erb"]
  erb_template_list.each do | temp_file |
    if temp_file =~ /\.\/ErbFile\/(.+)\.erb/
      new_file_name = output_dir + @proto_obj.module_name + "_" + $1
      f = File.new(new_file_name, "w") 
      puts "Generating #{new_file_name}"
      File.open(temp_file) { |fh| 
        erb_engine = ERB.new( fh.read ) 
        f.print erb_engine.result( binding )   
      }
    end
  end
end
  
default_input_dir = "../production/ProtoFile/EditableFile/"
default_output_dir = "../production/Code_ExternalAPI/GeneratedFile/"
  
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
  run_generate_external_API(input_dir, output_dir, module_str)
end
