require 'set'
require '.\sequence_parser'
require '.\stm_model'

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


