

class String
    def underscore
        self.gsub(/::/, '/').
        gsub(/([A-Z]+)([A-Z][a-z])/,'\1_\2').
        gsub(/([a-z\d])([A-Z])/,'\1_\2').
        tr("-", "_").
        downcase
    end

    # Strips indentation in heredocs.
    #
    # For example in
    #
    #   if options[:usage]
    #     puts <<-USAGE.strip_heredoc
    #       This command does such and such.
    #
    #       Supported options are:
    #         -h         This message
    #         ...
    #     USAGE
    #   end
    #
    # the user would see the usage message aligned against the left margin.
    #
    # Technically, it looks for the least indented non-empty line
    # in the whole string, and removes that amount of leading whitespace.
    def strip_heredoc
        gsub(/^#{scan(/^[ \t]*(?=\S)/).min}/, "".freeze)
    end

    # sometimes "\n" appears in the code and make the #strip_heredoc
    #   acts in a wrong way. because "\n" causes a "" match
    def strip_heredoc_for_code
        gsub(/^#{scan(/^[ \t]*(?=\S)/).reject(&:empty?).min}/, "".freeze)
    end
end

class Array

  def add_indent(indent = " " * 4)
    self.map {|item| indent + item }
  end

  def add_indent!(indent = " " * 4)
    self.map! {|item| indent + item }
  end

end