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

### Emulator16
The **Emulator16** provides a set of possible operations that the cpu can execute.
These operators are stored in a **OperatorTable**.

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



# Functionality to Add

Much of the functionality is still a work in progress.

* [ ] Parse a text file with instructions to translate them to uint16_t, in order to add them to the InstructionMemory.
* [ ] Implement the *run* function in Emulator to emulate the repeated execution of instructions.

* [ ] (Improve/organize use of CMake)
