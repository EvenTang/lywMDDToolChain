require 'find'
require 'erb'
require File.expand_path('../MetaModel/sequence_parser', __FILE__)

puts "Start generating ComponentDiagram!"

input_dir = "../production/SequenceDiagram/ArchDesign/"
output_dir = "../production/ComponentDiagram/GeneratedFile/"

all_components = []

Find.find(input_dir) do |path|
  if path.to_s =~ /(.*)\.wsd$/
    components = SequenceParser.new(path).components
    components.each do |compo|
      all_components.push compo unless all_components.include? compo
    end
  end
end

erb_template_list = Dir["./ErbFile/component_diagram.wsd.erb"]

erb_template_list.each do | temp_file |
  if temp_file =~ /\.\/ErbFile\/(.+)\.erb/
    new_file_name = output_dir + $1
    f = File.new(new_file_name, "w") 
    puts "Generating #{new_file_name}"
    File.open(temp_file) { |fh| 
    erb_engine = ERB.new( fh.read ) 
    f.print erb_engine.result( binding )
  }
  end
end