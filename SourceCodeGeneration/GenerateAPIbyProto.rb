require 'erb'
require './lyw_rblib_extension.rb'


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


@proto_analyzer = nil
proto_file_name = ARGV[0] # .\InputForAPIFileGen\SystemCtrlMessageDef.proto
if proto_file_name =~ /\.\\InputForAPIFileGen\\(\w+)MessageDef\.proto/
    @proto_analyzer = ProtoAnalyzer.new($1)
    File.open(proto_file_name).each_line do |line|
        @proto_analyzer.ParseProtoStructure line
    end
end

@proto_obj = @proto_analyzer.proto_file

#=begin
erb_template_list = Dir["./InputForAPIFileGen/API.*.erb"]
erb_template_list.each do | temp_file |
    if temp_file =~ /\.\/InputForAPIFileGen\/(.+)\.erb/
        new_file_name = "./GeneratedFile/" + @proto_obj.module_name + "_" + $1
        f = File.new(new_file_name, "w") 
        puts "Generating #{new_file_name}"
        File.open(temp_file) { |fh| 
            erb_engine = ERB.new( fh.read ) 
            f.print erb_engine.result( binding )   
        }
    end
end
#=end

