require 'set'
require '.\sequence_parser'
require '.\class_diagram_parser'
require '.\stm_model'


class STMInnerAPI

  attr_reader :apis

  def initialize
    @apis = []
  end

  def add_api_operations (api)
    @apis << api
    @apis.flatten!
  end
end

class SoftwareModel

  attr_accessor :module_name, :state_machine
  attr_accessor :sequence_parsers
  attr_reader   :class_diagram
  attr_reader   :stm_apis
  
  def initialize(module_name)
    @state_machine = StateMachine.new(module_name)
    @module_name = module_name
    @sequence_parsers = []
    @stm_apis = STMInnerAPI.new
    @class_diagram = ModuleClass.new(module_name)
  end

  def add_sequence_paser(seq_paser)
    @sequence_parsers.push seq_paser
  end

  def generate_stm_frame
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

  def update_ecb_logic_tree_from_sequence
    @state_machine.ecbs.each do |ecb|
      sequence_parsers.each do |seq_parser|
        seq_parser.get_logic_tree_of(@module_name, ecb.state_name, ecb.event_name) do |logic_tree|
          ecb.update_logic_tree(logic_tree)
        end
      end
    end
  end

  def update_all_stm_apis
    apis = @state_machine.ecbs.inject([]) do |ops, ecb|
      ops << ecb.logic_tree&.all_internal_call_operations
    end
    @stm_apis.add_api_operations apis.flatten.compact
  end

  def update_class_diagram_by_seq
    @sequence_parsers.each do |seq_parser|
      seq_parser.focus_on_component @module_name
      seq_parser.get_all_events.each do |event_statement|
        @class_diagram.generate_send_msg_method_from_seq(event_statement)
      end
    end
    @class_diagram.clean_up
  end

end


