

# All operations should be summarize in class diagrams

class ModuleClass
  attr_reader :name             # class name
  attr_reader :private_methods
  attr_reader :public_methods
  attr_reader :data_members


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