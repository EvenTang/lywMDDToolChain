require './statement_ast'


class Array

  def add_indent(indent = " " * 4)
    self.map {|item| indent + item }
  end

  def add_indent!(indent = " " * 4)
    self.map! {|item| indent + item }
  end

end


class APICall
  def generate_code
  end
end

class IfSatatement
  def generate_code
  end
end

class LoopStatement
  def generate_code
  end
end