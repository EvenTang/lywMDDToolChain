
class ComponentAnalyzer
  attr_reader :statement_str
  attr_reader :component_name
  attr_reader :component_type
  attr_reader :init_state

  COM_TYPE_STM     = 1
  COM_TYPE_SERVICE = 2
  COM_TYPE_LIB     = 3
  COM_TYPE_OTHER   = 20
  COM_TYPE_UNKNOWN = 90

  def initialize(statement_str)
    @statement_str = statement_str
    @component_name = ""
    @component_type = ""
    @init_state = ""
    get_component_info
  end

  private
  def get_component_info()
    # component RemoteCtrl    /' STM     RC_uninitialized '/ 
    if @statement_str =~ /component\s+(\w*)\s*\/\'\s+(\w*)\s+(\w*)\s+\'/
      @component_name = $1
      #type_match = {STM : COM_TYPE_STM, SERVICE : COM_TYPE_SERVICE, LIB : COM_TYPE_LIB, OTHER : COM_TYPE_OTHER}
      @component_type = ComponentAnalyzer.const_get("COM_TYPE_" + $2)
      @init_state = $3
    end
  end
end

class ComponentParser
  attr_reader :component_file_name, :component_line_content
  attr_reader :components

  def initialize(file_name)
    @component_file_name = file_name
    @component_line_content = 
      if File.exist?(@component_file_name)
        File.new(@component_file_name).readlines.map {|str| ComponentAnalyzer.new(str)}
      else
        []
      end
    @components = []
    get_all_components_info
  end

  def get_init_state(component_name)
    target_compo = @components.find {|compo| compo.component_name == component_name }
    return target_compo.init_state
  end

  def get_component_type(component_name)
    target_compo = @components.find {|compo| compo.component_name == component_name }
    return target_compo.component_type
  end

  def component_def_of?(component_name)
    return true if @components.find {|compo| compo.component_name == component_name }
    false
  end
  
private
  def get_all_components_info()
    @components = @component_line_content.select do |statement|
      !statement.component_name.empty?
    end
  end

end

# begin 
#   com_parser = ComponentParser.new(".\\InputForSTMSourceGen\\ArchDesign\\com_Components.wsd")
#   puts "============="
#   com_parser.get_all_components_info
#   com_parser.components.each do |statement|
#     puts statement.component_name + ":" + statement.component_type.to_s
#   end
#   puts "============="
# end