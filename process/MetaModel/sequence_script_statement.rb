
class ScriptStatement
  attr_reader :statement_str
  attr_reader :type
  attr_reader :contents      # hash table that store elements of the script statement

  TYPE_SEND_MESSAGE     = 1
  TYPE_INTERNAL_CALL_API  = 2
  TYPE_EXTERNAL_CALL_API  = 3
  TYPE_EXTERNAL_RETURN  = 4
  TYPE_STRUCTURE_DEF    = 5
  TYPE_STATE_DEF        = 6
  TYPE_ACTIVATE_DEF   = 7
  TYPE_DEACTIVATE_DEF = 8
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
    # FIXME: B-->> will result in "B-" by the following regex.
    if @statement_str =~ /(\w+)\s*(->>|-->>)\s*(\w+)\s*:(.*)/
      @type = TYPE_SEND_MESSAGE
      @contents[:source_component_name] = $1.strip
      @contents[:line_type] = $2.strip
      @contents[:destination_component_name] = $3.strip
      @contents[:message] = $4.strip
      true
    else
      false
    end
  end

  def definition_of_internal_call_api?()
    #A->A : rslt = SetTemperature() or
    #A->A : SetTemperature()
    if @statement_str =~ /(\w+)\s*->\s*(\w+)\s*:\s*(\w+)\s*=\s*(.*)/ && $1.strip == $2.strip
      @type = TYPE_INTERNAL_CALL_API
      @contents[:return_value] = $3.strip
      @contents[:source_component_name] = $1.strip
      @contents[:destination_component_name] = $1.strip
      @contents[:message] = $4.strip
      true
    elsif @statement_str =~ /(\w+)\s*->\s*(\w+)\s*:(.*)/ && $1.strip == $2.strip
      @type = TYPE_INTERNAL_CALL_API
      @contents[:return_value] = ""
      @contents[:source_component_name] = $1.strip
      @contents[:destination_component_name] = $1.strip
      @contents[:message] = $3.strip
      true
	else
      false
    end
  end   

  def definition_of_external_call_api?()
    #SystemCtrl->ShareOBJ : SetTemperature()
    if @statement_str =~ /(\w+)\s*->\s*(\w+)\s*:(.*)/ && $1.strip != $2.strip
      @type = TYPE_EXTERNAL_CALL_API
      @contents[:source_component_name] = $1.strip
      #@contents[:line_type] = $2.strip
      @contents[:destination_component_name] = $2.strip
      @contents[:message] = $3.strip
      true
    else
      false
    end
  end
  
  def definition_of_external_return?()
    #ShareOBJ->SystemCtrl : OK
    if @statement_str =~ /(\w+)\s*-->\s*(\w+)\s*:(.*)/ && $1.strip != $2.strip
      @type = TYPE_EXTERNAL_RETURN
      @contents[:source_component_name] = $1.strip
      #@contents[:line_type] = $2.strip
      @contents[:destination_component_name] = $2.strip
      @contents[:return_value] = $3.strip
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
      @contents[:states] = $2.strip.split(/\|/).collect {|state| state.strip.upcase }
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
    if (@type == TYPE_SEND_MESSAGE) && (@contents[:destination_component_name] == component_name) && (@contents[:message] =~ /#{event_name}\s*\(/)
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

  def state_def_but_not?(component_name, state_name)
    if (@type == TYPE_STATE_DEF) && (@contents[:component_name] == component_name) && (! @contents[:states].include? state_name)
      true
    else
      false
    end
  end

  def activate_def_of?(component_name = nil)
    if @type == TYPE_ACTIVATE_DEF && @contents[:component_name] == component_name
      true
    else
      false
    end
  end

  def deactivate_def_of?(component_name)
    if @type == TYPE_DEACTIVATE_DEF && @contents[:component_name] == component_name
      true
    else
      false
    end
  end

  def to_s
    @statement_str
  end

end

