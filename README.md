# CPU16 Emulator

       16 bits
|++++|++++|++++|++++|

## Instruction Formats
               4    4   4    4
* R-Type => |++++|++++|++++|++++|
              Op  Src1 Src2 Dst 

               4    4   4    4
* I-Type => |++++|++++|++++|++++|
              Op  Src1  Dst Imm.

               4        12
* J-Type => |++++|++++++++++++|
              Op   Jump Addr.


### R-Type

1000 -> Signal of R-Type

* Add => |1000|++++|++++|++++|
* Sub => |1001|++++|++++|++++|
* Mul => |1010|++++|++++|++++|
* Div => |1011|++++|++++|++++|

### I-Type

0100 -> Signal of I-Type

* Load =>  |0100|++++|++++|++++|
* Store => |0101|++++|++++|++++|

### J-Type

0010 -> Signal of J-Type

* X =>  |0010|++++|++++|++++|
* X =>  |0011|++++|++++|++++|
