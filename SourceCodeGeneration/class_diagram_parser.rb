

# All operations should be summarize in class diagrams

# @brief TypeAnalyzer is used to guess type from a value list
#
class TypeAnalyzer

  def initialize(value_list)
    @value_list = value_list
    @type_name = :UnknowType
  end
  
  def get_type
    which_type = methods(false).select {|m| m =~ /guess_.*_type\?/ }.find { |m| send(m) }
    if which_type && which_type =~ /guess_(.*)_type\?/
      $1
    else
      :UnknowType
    end
  end

  private
  def guess_int_type?
    @value_list.all? {|v| v =~ /^(\+|-)?\d?$/ }
  end

  # FIXME: hex like 0x?? should be considered
  def guess_uint_type?
    @value_list.all? {|v| v =~ /^\d?$/ }
  end

  def guess_enum_type?
    puts @value_list
    @value_list.all? {|v| v =~ /^[A-Z_]$/ }
  end

  def guess_string_type?
    @value_list.all? {|v| v =~ /^".*"$/ }
  end

end

class EnumClass
  attr_reader :name
  attr_reader :value_list

  def initialize(name, value_list)
    @name, @value_list = name, value_list
  end

end


class SendMessageMethod
  attr_reader :method_name
  attr_reader :params       # [[type, name], [type, name]]
  attr_reader :return_type
  attr_reader :param_values
  attr_reader :related_enum_class

  # @brief generate a send message method from a planUML seqence statement
  # 
  # @param String statement : SetTempareture(NewTemp = 2)
  def initialize(statement)
    @params = []
    @param_values = Hash.new([]) # Hash [name => [value1, value2]]
    analyzer_send_message_statement(statement)
    @related_enum_class = []    
  end

  # @param SendMessageMethod other_method : another send method with the same method name  
  def update_param_values_by(other_method) 
    other_method.param_values.each do |name, value|
      @param_values[name] << value
    end
  end

  def guess_param_type
    @params.each do |param_type, param_name|
      if param_type == :UnknowType
        value_list = @param_values[param_name]
        param_type = TypeAnalyzer.new(value_list).get_type
        if param_type == :enum
          param_type = "Enum" + param_name.Capitalize
          @related_enum_class << EnumClass.new(param_type.to_sym, value_list)
        end
      end
    end
  end

  private 
  def analyzer_send_message_statement(statement)
    if statement =~ /(\w+)(\(.*\))?/ then
      @method_name = $1
      left_str = $2
      while left_str =~ /((\w+)=([\w"]+)),?(.*)/
        @params << [:UnknowType, $2]
        @param_values[$2].push $3
        left_str = $4
      end
    end
  end

end

class ModuleClass
  attr_reader :module_name             # class name
  attr_reader :private_methods
  attr_reader :public_methods
  attr_reader :send_message_methods
  attr_reader :data_members

  def initialize(module_name)
    @module_name = module_name
    @send_message_methods = []
  end

  def generate_send_msg_method_from_seq(statement)
    new_method = SendMessageMethod.new(statement)
    exited_method = @send_message_methods.find {|m| m.method_name == new_method.method_name}
    if exited_method
      exited_method.update_param_values_by new_method
    else
      @send_message_methods << new_method
    end
  end

  def clean_up
    @send_message_methods.map &:guess_param_type
  end

end

