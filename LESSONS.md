# LESSONS

* Need to build things gradually instead of coding a ton of functionality and testing it at the end.
	- This happens because I have a vague idea of an implementation, but have not defined it concretely.
	- I would need to spend some time thinking about it.
	* POSSIBLE SOLUTION: Once the implementation has been described, coome up with steps/tasks that will gradually build the system.

* When making tests, I am noticing how cumbersome the parameters are for each operator.
	- The current CMAKE project structure is not the best, but I plan to dissect it later on to better understand it.
* There are two important concepts when compiling:
	- Linking of binary libraries.
	- Inclusion of path directories in the project.
	- By understanding how to provide accessibility to the required libraries and paths, can I then implement a decent CMAKE project structure.
* All this will take times.

* Initially the CPU was in charge of executing the instructions, but then I realized that by doing so the instructions would be tied to the CPU.
	- This meant that the inclusion of operators would be tied to the CPU.
	- This is how it is done internally, but I thought of Abstracting it out.
	- In this case, the CPU is just the registers, PC, and the current instruction.
	- The Emulator is what allows the execution of the CPU.
	- It is mostly done from an architecture perspective.
	- I could have had the CPU do the decoding, but then this meant that the CPU would have to utilized the OperatorTable and be in charge of managing all the operators.
	- Although this may how it is, I thought it best to seperate them so that the Emulator would be in charge of this.
	- This is why initially the Cpu had an execute function. Only after I thought of a way to avoid the if/else for decoding, did I think it best to seperate the functionality and have the Emulator be in charge of the decoding. Allowing the CPU to only focus on the storage.
	- I suppose it can be said that the Emulator implements the micro-architecture of the CPU.
	- The word CPU is just used to refer to the registers, program-counter, and the current-instruction.
	- I suppose the use of CPU is incorrect in this project, as the CPU is the agglomeration of all the components together.
	- What would be the appropriate name for what I term 'Cpu' in this project?
	- It has registers, program counter, and current instruction. It can fetch the next instruction and increment. 
	- It does tasks of the CPU, but it does not decode. That is left to the operator where it updates the given components based on the given instruction.
	- It only stores data. I guess the term CPU is not really needed. In fact, the class CPU can be cut up into components: Registers, ProgramCounter, CurrentInstruction.
	- The Emulator would need to juggle these components. For the sake of encapsulation I named them CPU, but I now realize the name is inadequate.
	- I will keep it for now, but I may think of another way of organizing that the current 'Cpu' contains and its functionality.
