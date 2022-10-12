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
* Subi            => |1010|++++|++++|++++|
* Addi            => |1011|++++|++++|++++|
* Branch-On-Equal => |1100|++++|++++|++++|

### J-Type

0010 -> Signal of J-Type

* jmp =>  |0010|++++++++++++|
* X   =>  |0011|++++++++++++|

