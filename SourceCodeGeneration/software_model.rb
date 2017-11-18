require 'set'
require '.\sequence_parser'

class Event 
  attr_accessor :name, :params

  def initialize(seq_file_line)
    @params = Hash.new # Hash as : field_name => field_value

    if seq_file_line =~ /^(\w+)(\(.*\))?$/ then
      @name = $1
      left_str = $2
      while left_str =~ /((\w+)=([\w"]+)),?(.*)/
        @params[$2] = $3
        left_str = $4
      end
    end
  end

  def merge_params(other_event)
    @params.merge! other_event.params
  end

  def == (other)
    return other != nil && name == other.name
  end

  def eql?(other)
    self == other
  end

end

class STM_ECB
  attr_reader :state_name, :event_name, :logic_tree

  def initialize(state_name, event_name)
    @state_name, @event_name = state_name, event_name
  end

  def update_logic_tree(logic_tree)
    @logic_tree ||= logic_tree
  end

  def generate_code
    @logic_tree&.generate_code
  end

end

class StateMachine

  attr_accessor :module_name, :states, :events, :ecbs

  def initialize(module_name)
    @module_name = module_name
    @states = Set.new 
    @events = Set.new
    @ecbs = []
  end

  def update_ecbs
    @states.each do |s|
      @events.each do |e|
        @ecbs << STM_ECB.new(s, e.name)
      end
    end
  end

  def get_ecb_logic_code(state_name, event_name)
    @ecbs.find {|ecb| ((ecb.state_name == state_name) && (ecb.event_name == event_name))}&.generate_code
  end

end

class SoftwareModel

  attr_accessor :module_name, :state_machine
  attr_accessor :sequence_parsers
  
  def initialize(module_name)
    @state_machine = StateMachine.new(module_name)
    @module_name = module_name
    @sequence_parsers = []
  end

  def add_sequence_paser(seq_paser)
    @sequence_parsers.push seq_paser
  end

  def generate_stm_frame()
    @sequence_parsers.each do |seq_parser|
      seq_parser.focus_on_component @module_name
      seq_parser.get_all_events.map {|e| Event.new(e)}.each do |new_e|
        if ! @state_machine.events.find {|e| e.name == new_e.name }&.merge_params(new_e)
          @state_machine.events << new_e
        end
      end
      @state_machine.states.merge seq_parser.get_all_states
    end
    @state_machine.update_ecbs
  end

  def update_ecb_logic_tree_from_sequence()
    @state_machine.ecbs.each do |ecb|
      sequence_parsers.each do |seq_parser|
        seq_parser.get_logic_tree_of(@module_name, ecb.state_name, ecb.event_name) do |logic_tree|
          ecb.update_logic_tree(logic_tree)
        end
      end
    end
  end

end


