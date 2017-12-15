

generated_dir = "../production/SequenceDiagram/GeneratedFile/"
editable_dir = "../production/ClassDiagram/EditableFile/"

generated_file_list = Dir[generated_dir+ "*.wsd"]
editable_file_list = Dir[editable_dir+ "*.wsd"]

erb_template_list.each do | temp_file |
  puts temp_file
  new_file_name = output_dir + $1
  f = File.new(new_file_name, "w") 
  puts "Generating #{new_file_name}"

end