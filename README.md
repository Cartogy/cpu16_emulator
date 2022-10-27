# CPU16 Emulator

       16 bits
|++++|++++|++++|++++|

## Instruction Formats
               4    4   4    4
* R-Type => |++++|++++|++++|++++|
              Op  Src1 Src2 Dst 

               4    4   4    4
* I-Type => |++++|++++|++++|++++|
              Op  Reg1 Reg2 Imm.

               4        12
* J-Type => |++++|++++++++++++|
              Op   Jump Addr.

## Special registers
* zero      -> Contains the zero value in register: 0.

### R-Type

1000 -> Signal of R-Type

* Add => |0100|++++|++++|++++|
* Sub => |0101|++++|++++|++++|
* Mul => |0110|++++|++++|++++|
* Div => |0111|++++|++++|++++|

### I-Type

0100 -> Signal of I-Type

* Load            => |1000|++++|++++|++++|
* Store           => |1001|++++|++++|++++|
* Addi            => |1010|++++|++++|++++|
* Subi            => |1011|++++|++++|++++|
* Branch-On-Equal => |1100|++++|++++|++++|

### J-Type

0010 -> Signal of J-Type

* jmp =>  |0010|++++++++++++|
* X   =>  |0011|++++++++++++|

# Architecture

The central component is the **Emulator** that connects all the components required to emulate a Von Neumann Architecture CPU.



## Emulator

The Emulator is an *abstract class*. For every new CPU and the specified Instruction Set, a new class (e.g., Emulator16) will have to be defined.
This has been done with the **Emulator16** class

![Emulator Diagram](Emulator.drawio.png)

### Emulator16
The **Emulator16** provides a set of possible operations that the cpu can execute.
These operators are stored in a **OperatorTable**.

![Emulator Diagram](Emulator16.drawio.png)

## OperatorTable
An **OperatorTable** is a *map* to all the possible operations that the cpu can execute.
The map stores **Operator**s which are *abstract classes*.

The motive for the OperatorTable and the Operator objects is to avoid
the use of *if/else* to decide which operator to apply on the cpu and its registers.

### Operator
The **Operator** is an abstract class.
The derived class would provide the actual operation.
For example: OpAdd would implement the function *func* to apply the add operation.

## CPU

The CPU contains the:
* Program Counter
* Registers
* Current Instruction

Before executing, the CPU must fetch the next instruction from the **InstructionMemory**.

## InstructionMemory

The **InstructionMemory** stores all the available instructions for the CPU to execute.


## Compiler

The compiler is responsible for translating the assembly source code into the machine code.
It does so by implementing three components:
* Tokenizer
* parser
* MachineCodeGenerator

### Tokenizer

The Tokenizer has the following type:

$$Tokenizer: filePath \to [TokenLine] $$

The *TokenLine* is a set of **Tokens** the represent a line in source assembly code.

### Parser

The Parser has the following type:

$$Parser: [TokenLine] \to [ParserNode]$$

that ensures the *grammar* of the code is followed.
As the assembly code has an instruction per line, a *parser node* represents the specific instruction in a line.

### Machine Code Generator

The Machine Code Generator has the following type:

$$MachineCodeGenerator: [ParserNode] \to [MachineCode]$$

that maps the ParserNode to the corresponding *machine code*.
For this specific instance, the *MachineCode* is in a *uint16_t* format.

With these three components, we can chain them together as follows:

$$MachineCodeGenerator(Parser(Tokenizer(\text{``file-path"})))$$

With a list of machine code instructions, we can add these instructions to the **InstructionMemory**.
This is demonstrated in the **Emulator** implementation.

The benefit of this functional approach is that we are able to isolate each component in order to test their functionality; isolating the bugs to their respective components.
