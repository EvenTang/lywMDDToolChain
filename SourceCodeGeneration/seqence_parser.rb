require 'set'

class SequenceParser

  attr_accessor :seq_file_name, :seq_file_content
  attr_accessor :components
  attr_accessor :focused_component

  def initialize(file_name)
    @seq_file_name = file_name
    @seq_file_content = File.new(@seq_file_name).readlines
    @components = get_all_components
    @focused_component = ""
  end

  def get_all_states
    states = Set.new
    if @focused_component != ""
      @seq_file_content.each do |line|
        if new_states = find_states_for_component(line, @focused_component)
          states.merge new_states
        end
      end
    end
    states
  end

  def get_all_events
    events = Set.new
    if @focused_component != ""
      @seq_file_content.each do |line|
        if new_event = find_event_for_component(line, @focused_component)
          events << new_event
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

  # @ get event on specified state
  #
  # Specific state could appears several times on one sequence
  # order is used to specify witch
  # 
  def get_event_on(state, order = 1)
    events = []    
    if @focused_component == "" || order < 1
      events
    end

    is_matched = false
    @seq_file_content.each do |line|
      if found_states = find_states_for_component(line, @focused_component)
        return events if is_matched
        if found_states.include? state
          order -= 1
          is_matched = true if order == 0
        end
      end
    
      if is_matched && found_event = find_event_for_component(line, @focused_component)
        events << found_event
      end
    end
    events
  end
  
  def cancel_focusing_on_component()
    @focused_component = ""
  end

  private 
  def get_all_components()
    @components = Set.new
    @seq_file_content.each do |line|
      if line =~ /(\w*)\s*(-->|->|->>|-->>)\s*(\w*)\s*:/
        @components.merge [$1, $3]
      end
    end
    @components
  end

  # @brief Given a line and component name, match states in the line match plantUML syntax
  # @return array of state strings
  def find_states_for_component(line, component_name)
    if line =~ /hnote\s*over\s*#{component_name}\s*:\s*(.*)\s*/
      return $1.strip.split(/, */)
    end
    nil
  end

  # @brief Given a line and component name, match event in the line match plantUML syntax
  # @return string of event
  def find_event_for_component(line, component_name)
    if line =~ /.*(->>|-->>)\s*#{component_name}\s*:\s*(.*)\s*/
      return $2
    end
    nil
  end


end


seq_parser = SequenceParser.new("D:\\05 MyProject\\lywMDDToolChain\\SourceCodeGeneration\\InputForSTMSourceGen\\ChangeTemprature.wsd")
#seq_parser.components.each {|item| puts item }
#puts seq_parser.components.size
seq_parser.focus_on_component("SystemCtrl")
#seq_parser.get_all_states.each {|item| puts item }
#seq_parser.get_all_events.each {|item| puts item }
puts seq_parser.get_event_on("Idle")
puts seq_parser.get_event_on("Working")

