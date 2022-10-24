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

* When writing the TokenizeLine function, I realized it was best to implement a class that did this behaviour.
	- The motive was when deciding which vector to put in the error/token.
	- It also made the code a lot more readable.
	- C++ promotes the use of classes instead of functions that return a tuple or something.
	- Doing so cleans up the code. As noticed by returning only a TokenLine instead of a pair of stuff.

* Polymorphism. I tried to use the Base pointer as a form of polymorphism to call the correct function.
	- This seemed to work in the Tokenizer, but I am starting to believe it did not.
	- The idea was that the compiler would be able to acquire the derived class by passing it the base pointer.
	- This does not seem to work as I thought at first.
	- Will need to spend more time investigating this case.
	```
	void func(Base *);
	void func(Dev *);
	Dev *d;
	Base b = d;

	func(b);

	// Ideally, the func(Dev *) would be called, but in fact func(Base *) is called.
	// I want to see if I can acquire the latter behaviout. I need to learn more about C++'s polymorphism.
	```
