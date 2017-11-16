
class ScriptStatement
  attr_reader :statement_str
  attr_reader :type
  attr_reader :contents      # hash table that store elements of the script statement

  TYPE_SEND_MESSAGE     = 1
  TYPE_CALL_API         = 2
  TYPE_STRUCTURE_DEF    = 3
  TYPE_STATE_DEF        = 4
  TYPE_ACTIVATE_DEF   = 5
  TYPE_DEACTIVATE_DEF = 6
  TYPE_UNKNOW_TYPE      = 90

  def initialize(statement_str)
    @statement_str = statement_str
    @type = TYPE_UNKNOW_TYPE
    @contents = Hash.new
    #self.class_method(/^definition_of_/).each {|test| break if test.call()}
    self.methods.select{
      |item| item.to_s =~ /^definition_of_/
     }.map { |item| method(item) }.each {|pattern_matcher| break if pattern_matcher.call }
  end

  def definition_of_send_message?()
    #puts @statement_str
    # todo: B-->> will result in "B-" by the following regex.
    if @statement_str =~ /(.*)(->>|-->>)(.*):(.*)/
      #puts "!!!!!!matched"
      @type = TYPE_SEND_MESSAGE
      @contents[:source_component_name] = $1.strip
      @contents[:line_type] = $2.strip
      @contents[:destination_component_name] = $3.strip
      @contents[:message] = $4.strip
      #puts @type
      #puts @contents.to_s
      true
    else
      false
    end
  end

  def definition_of_call_api?()
    if @statement_str =~ /(.*)(->|-->)(.*):(.*)/
      @type = TYPE_CALL_API
      @contents[:source_component_name] = $1.strip
      @contents[:line_type] = $2.strip
      @contents[:destination_component_name] = $3.strip
      @contents[:api_call] = $4.strip
      true
    else
      false
    end
  end

  def definition_of_state?()
    #puts @statement_str
    if @statement_str =~ /hnote\s+over\s+(.*):(.*)/
      #puts "!!!!!!matched"
      @type = TYPE_STATE_DEF
      @contents[:component_name] = $1.strip
      @contents[:states] = $2.strip.split(/\| */)
      #puts @type
      #puts @contents[:component_name]
      #puts @contents[:states]
      true
    else
      false
    end
  end

  def definition_of_structure?()
    if @statement_str =~ /\s*(alt|loop|break|opt|else|end)\s+(.*)/
      @type = TYPE_STRUCTURE_DEF
      @contents[:key_word]    = $1
      @contents[:condition] = $2
      true
    else
      false
    end
  end

  
  def definition_of_activate?()
    if @statement_str.strip =~ /^activate\s+(.*)/
      @type = TYPE_ACTIVATE_DEF
      @contents[:component_name] = $1.strip
      true
    else
      false
    end
  end

  def definition_of_deactivate?()
    if @statement_str =~ /deactivate\s+(.*)/
      @type = TYPE_DEACTIVATE_DEF
      @contents[:component_name] = $1.strip
      true
    else
      false
    end
  end

  def event_def_of?(component_name, event_name)
    if (@type == TYPE_SEND_MESSAGE) && (@contents[:destination_component_name] == component_name) && (@contents[:message].include? event_name)
      true
    else
      false
    end

  end

  def state_def_of?(component_name, state_name)
    if (@type == TYPE_STATE_DEF) && (@contents[:component_name] == component_name) && (@contents[:states].include? state_name)
      true
    else
      false
    end
  end

  def activate_def_of?(component_name)
    if (@type == TYPE_ACTIVATE_DEF) && (@contents[:component_name] == component_name)
      true
    else
      false
    end
  end

  def deactivate_def_of?(component_name)
    if (@type == TYPE_DEACTIVATE_DEF) && (@contents[:component_name] == component_name)
      true
    else
      false
    end
  end

  def to_s
    @statement_str
  end

end
