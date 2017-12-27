
class Array

  def add_indent(indent = " " * 4)
    self.map {|item| indent + item }
  end

  def add_indent!(indent = " " * 4)
    self.map! {|item| indent + item }
  end

end

class CodeGeneratorProxy

  def generate_function_call(name, param_list)
    raise NotImplementedError.new("#{self.class.name} : generate_function_call has not been implemented.")
  end

  def generate_function_prototype(name, param_list)
    raise NotImplementedError.new("#{self.class.name} : generate_function_prototype has not been implemented.")
  end

  def generate_transmit_code(name, state)
    raise NotImplementedError.new("#{self.class.name} : generate_transmit_code has not been implemented.")
  end
  
  def generate_alt_code(branches)
    raise NotImplementedError.new("#{self.class.name} : generate_alt_code has not been implemented.")
  end
  
  def generate_loop_code(branch)
    raise NotImplementedError.new("#{self.class.name} : generate_loop_code has not been implemented.")
  end
  
  def generate_break_code(branch)
    raise NotImplementedError.new("#{self.class.name} : generate_break_code has not been implemented.")
  end
  
  def generate_opt_code(branch)
    raise NotImplementedError.new("#{self.class.name} : generate_opt_code has not been implemented.")
  end
  
end