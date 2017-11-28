# lywMDDToolChain

Release plan for V1.2:
- [ ] Generate State Chart based on the information of sequence (events/states)
- [ ] Create a STM generator. (High priority)
- [ ] Add proto file analyzer to a complete .proto analysis so that API file can be generated completely.

Release plan for V1.3

- [ ] Make things configurable, like folder, file extension and so on. (By using YAML)

Release plan for V2.0

- [ ] Create component diagram and classify components (STM¡¢SERVICE¡¢LIB¡¢OTHER ¡­¡­ ), run different ruby file base on this classification.
- [ ] Add the function to check consistency between component diagram and sequence diagrams
- [ ] Read uninitialized state from component diagram
- [ ] Add the function to analysis start state which includes multi states, like as "state1|state2"
- [ ] add ruby command line options:
      -Input  dir1,dir2,dir3...                  input file directory
      -Output dir                                     output file directory
      -Module comp1,comp2...             component need to be analyzed
- [ ] Modify STM generator to generate 100% STM code
- [ ] Add exception handling code into task main file

Release plan for future ( I don't know when )

- [ ] Create a exchange data file(may be xml) for ERBCodeGenerator/SequenceAnalyzer
- [ ] Change all parsers to context-free grammars parser (Low priority) 
- [ ] Create Python (or something else that is easy to be used as a simulation tool) simulation model
- [ ] Analysis return value for inner API ( format: return=InnerAPI(key1=value1,key2=value2) )


