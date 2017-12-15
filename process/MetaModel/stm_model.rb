
class Event 
  attr_accessor :name, :params

  def initialize(seq_file_line)
    @params = Hash.new # Hash as : field_name => field_value

    if seq_file_line =~ /(\w+)(\(.*\))?/ then
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
