
class ScriptStatement
  attr_reader :statement_str
  attr_reader :type
  attr_reader :contents      # hash table that store elements of the script statement

  TYPE_SEND_MESSAGE     = 1
  TYPE_INTERNAL_CALL_API  = 2
  TYPE_EXTERNAL_CALL_API  = 3
  TYPE_STRUCTURE_DEF    = 4
  TYPE_STATE_DEF        = 5
  TYPE_ACTIVATE_DEF   = 6
  TYPE_DEACTIVATE_DEF = 7
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
    # FIXME: B-->> will result in "B-" by the following regex.
    if @statement_str =~ /(\w+)\s*(->>|-->>)\s*(\w+)\s*:(.*)/
      #puts "!!!!!!matched"
      @type = TYPE_SEND_MESSAGE
      @contents[:source_component_name] = $1.strip
      @contents[:line_type] = $2.strip
      @contents[:destination_component_name] = $3.strip
      @contents[:message] = $4.strip
      # puts @type
      # puts @contents.to_s
      true
    else
      false
    end
  end

  def definition_of_internal_call_api?()
    #SystemCtrl->SystemCtrl : SetTemperature() or
    #SystemCtrl->SystemCtrl : rslt = SetTemperature()
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
      false
    end
  end   

  def definition_of_external_call_api?()
    #SystemCtrl->ShareOBJ : SetTemperature()
    if @statement_str =~ /(\w+)\s*(->|-->)\s*(\w+)\s*:(.*)/ && $1.strip != $3.strip
      @type = TYPE_EXTERNAL_CALL_API
      @contents[:source_component_name] = $1.strip
      @contents[:line_type] = $2.strip
      @contents[:destination_component_name] = $3.strip
      @contents[:message] = $4.strip
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


#=============================================================================================
# PlantUML has its syntax for sequence like
#      A-->B:do something
# ScriptStatment knows PlantUML syntax tokens like "A", "-->", "B", "do something" only
# In mdd, we defined "do something" in a more specific format, like:
#              MessageName "(" ParamName "=" ParamValue [","  ParamName "=" ParamValue ]* ")"
#    This is another level syntax that can be improved/change in different senario
#  The following is classes to parse this "specific level syntax tokens"
#=============================================================================================

# @brief Send messaage statement parser
class SendMessageStatParser

  attr_reader :message_name
  attr_reader :params        # Hash { ParamName : ParamValue }

  def initialize(send_msg_stat)
    @params = Hash.new
    analyze(send_msg_stat)
  end

  def analyze(send_msg_stat)
    if statement =~ /(\w+)(\(.*\))?/ then
      @message_name = $1
      left_str = $2
      while left_str =~ /((\w+)=([\w"]+)),?(.*)/
        @params[$2] = $3
        left_str = $4
      end
    end
  end

end

class InternalCallStatParser

  attr_reader :message_name
  attr_reader :params        # Hash { ParamName : ParamValue }

  def initialize(send_msg_stat)
    @params = Hash.new
    analyze(send_msg_stat)
  end

  def analyze(send_msg_stat)
    if statement =~ /(\w+)(\(.*\))?/ then
      @message_name = $1
      left_str = $2
      while left_str =~ /((\w+)=([\w"]+)),?(.*)/
        @params[$2] = $3
        left_str = $4
      end
    end
  end

end

class ExternalCallStatParser
  
    attr_reader :message_name
    attr_reader :params        # Hash { ParamName : ParamValue }
  
    def initialize(send_msg_stat)
      @params = Hash.new
      analyze(send_msg_stat)
    end
  
    def analyze(send_msg_stat)
      if statement =~ /(\w+)(\(.*\))?/ then
        @message_name = $1
        left_str = $2
        while left_str =~ /((\w+)=([\w"]+)),?(.*)/
          @params[$2] = $3
          left_str = $4
        end
      end
    end
  
  end
  


