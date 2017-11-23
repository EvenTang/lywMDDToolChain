require 'find'
require './component_parser'
require './sequence_parser'

puts "Start Checking!"

com_parser = ComponentParser.new(".\\InputForSTMSourceGen\\ArchDesign\\com_Components.wsd")

Find.find(".\\InputForSTMSourceGen\\") do |path|
  if path.to_s =~ /(.*)\.wsd$/
    components = SequenceParser.new(path).components
    components.each do |compo|
      puts "!!!!!!Exist invalid component #{compo} in #{path}" if !com_parser.component_def_of?(compo)
    end
  end
end