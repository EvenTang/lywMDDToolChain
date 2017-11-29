

# All operations should be summarize in class diagrams



class SendMessageMethod
  attr_reader :method_name
  attr_reader :params       # [[type, name], [type, name]]
  attr_reader :return_type

  # @brief generate a send message method from a planUML seqence statement
  # 
  # @param statement string : SetTempareture(NewTemp = 2)
  def initialize(statement)
    @params = []
    @param_values = Hash.new([]) # Hash [name => [value1, value2]]
    analyzer_send_message_statement(statement)
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
    @send_message_methods << SendMessageMethod.new(statement)
  end

  def clean_up
    # FIXME: remove depulicate things and guess types for methods
    puts "Do nothing right now"
  end

end

class Operation
  attr_reader :statement      # Ref to ScriptStatement
  attr_reader :operation_name # Similar to function name or method name
  attr_reader :comment        # Operation comment
  attr_reader :params         # Pramaters :Hash {type, value}
  attr_reader :return_type

  def initialize(statement)
    @statement = statement
  end

end

=begin
   @brief OperationCall is use to call a operatin with arguments.
          It should be drived by CppOperationCall/PythonOperationCall/...
=end
class OperationCall
  attr_reader :arguments # Hash {name, value}
  attr_reader :operation # Ref to Operation instance
  attr_reader :return_value

end