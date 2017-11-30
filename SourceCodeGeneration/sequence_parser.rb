require 'set'
require '.\sequence_script_statement'
require '.\code_logic_tree'

class SequenceParser

  attr_accessor :seq_file_name, :seq_file_content
  attr_accessor :components
  attr_accessor :focused_component

  def initialize(file_name)
    @seq_file_name = file_name
    @seq_file_content = 
      if File.exist?(@seq_file_name)
        File.new(@seq_file_name).readlines.map {|str| ScriptStatement.new(str) }
      else
        []
      end
    @components = get_all_components
    @focused_component = ""
  end

  def get_all_states
    states = Set.new
    if @focused_component != ""
      all_state_defs = @seq_file_content.each do |statement|
        if statement.type == ScriptStatement::TYPE_STATE_DEF && @focused_component == statement.contents[:component_name]
          states.merge statement.contents[:states] 
        end
      end
    end
    states
  end

  def get_all_events
    events = Set.new
    if @focused_component != ""
      all_send_message_defs = @seq_file_content.each do |statement|
        if statement.type == ScriptStatement::TYPE_SEND_MESSAGE && @focused_component == statement.contents[:destination_component_name]
          events << statement.contents[:message]
        end
      end
    end
    events
  end

  def focus_on_component(component_name)
    @focused_component = component_name # todo: check the component_name is valid one
  end
  
  def get_sequent_file_name()
    @seq_file_name
  end

  def get_logic_tree_of(component, state, event)
    all_behavior_of(component, state, event) do |behavior|
      logic_tree = generate_logic_tree_from behavior
      yield logic_tree
    end
  end

  def cancel_focusing_on_component()
    @focused_component = ""
  end

  private 
  def get_all_components()
    @components = Set.new
    @seq_file_content.each do |line|
      if line.statement_str =~ /(\w+)\s*(-->|->|->>|-->>)\s*(\w+)\s*:/
        @components.merge [$1, $3]
      end
    end
    @components
  end

  def all_behavior_of(component, state, event)
    # FIXME: remove comments in script
    idx = 0
    loop do
      behavior, idx = selcect_behavior_of(component, state, event, idx)
      break if behavior.empty?
      yield select_relative_script(behavior, component)
    end
  end

  def generate_logic_tree_from(behavior)
    logic_tree = LogicTree.new
    behavior.each do |action|
      case action.type
      when ScriptStatement::TYPE_INTERNAL_CALL_API, ScriptStatement::TYPE_EXTERNAL_CALL_API, ScriptStatement::TYPE_SEND_MESSAGE
        logic_tree.add_operation action
      when ScriptStatement::TYPE_STRUCTURE_DEF
        logic_tree.update_structure action.contents[:key_word], action.contents[:condition]
      when ScriptStatement::TYPE_STATE_DEF
        logic_tree.add_state_tramsmit action
      end
    end
    logic_tree    
  end
  
  def select_relative_script(behavior, component)
    behavior.select do |st| 
      case st.type
      when ScriptStatement::TYPE_STATE_DEF, ScriptStatement::TYPE_STRUCTURE_DEF 
        true
      when ScriptStatement::TYPE_SEND_MESSAGE, ScriptStatement::TYPE_EXTERNAL_CALL_API,  ScriptStatement::TYPE_INTERNAL_CALL_API
        st.contents[:source_component_name] == component
      else 
        false
      end    
    end
  end

  # FIXME: state transition is not considered!
  def selcect_behavior_of(component, state, event, start_from_index = 0)
    last_index = start_from_index
    ecb_detecting = ECBDetecting.new(component, state, event)
    target_script = @seq_file_content[start_from_index...@seq_file_content.size].select do |item|
      last_index += 1
      ecb_detecting.in_ecb?(item)
    end
    return target_script, last_index
  end

end

class ECBDetecting

  LOCATING_STATE = 0
  LOCATING_EVENT = 1
  LOCATING_ACTIVATE = 2
  LOCATING_DEACTIVATE = 3
  LOCATING_END = 4
  IMPOSSIBLE_TO_LOCATE = -1

  def initialize(*param)
    @component, @state, @event = *param
    @yes_i_found = false
    @status = LOCATING_STATE
    @activate_count = 0
  end

  def in_ecb?(script_statement)
    case @status
    when LOCATING_STATE
      if script_statement.state_def_of? @component, @state
        @status = LOCATING_EVENT
      end
    when LOCATING_EVENT
      if script_statement.event_def_of? @component, @event
        @status = LOCATING_ACTIVATE
      end
      if script_statement.state_def_but_not? @component, @state
        @status = LOCATING_END
      end
    when LOCATING_ACTIVATE
      if script_statement.activate_def_of? @component
        @status = LOCATING_DEACTIVATE
        @activate_count += 1
      end
    when LOCATING_DEACTIVATE
      if script_statement.activate_def_of? @component
        @activate_count += 1
      end
      if script_statement.deactivate_def_of? @component
        @activate_count -= 1
        if @activate_count == 0
          @status = LOCATING_END
        end
      end
    else
      @yes_i_found = false      
    end
    @activate_count == 1
  end

end
  
=begin 
seq_parser = SequenceParser.new("D:\\05 MyProject\\lywMDDToolChain\\SourceCodeGeneration\\InputForSTMSourceGen\\ChangeTemprature.wsd")
seq_parser.components.each {|item| puts item }
puts seq_parser.components.size
seq_parser.focus_on_component("SystemCtrl")
seq_parser.get_all_states.each {|item| puts item }
seq_parser.get_all_events.each {|item| puts item }
puts seq_parser.get_event_on("Idle")
puts seq_parser.get_event_on("Working")
=end

# begin 
# seq_parser = SequenceParser.new("D:\\05 MyProject\\lywMDDToolChain\\SourceCodeGeneration\\InputForSTMSourceGen\\\ArchDesign\\ChangeTemprature.wsd")
# seq_parser.focus_on_component("SystemCtrl")
# seq_parser.components.each {|item| puts item }
# puts seq_parser.components.size
# seq_parser.get_all_states.each {|item| puts item }
# seq_parser.get_all_events.each {|item| puts item }
# puts seq_parser.get_event_on("Idle")
# puts seq_parser.get_event_on("Working")
# state, event = "Working", "SetTemperatureResult"
# puts "===S: #{state}, E: #{event} ======="
# puts seq_parser.get_logic_tree_of("SystemCtrl", state, event) {|logic_tree| 
#   puts "-------------------------------------------"
#   logic_tree.generate_code.each {|st| puts st }
#   puts "--------------------------------------------"
# }
# puts "============="
# end

