# csmc223-midterm-project
This repo will host the files used for the Midterm project about the Processor Simulator.


## Instructional Set Architecture (ISA)


**EXT 00 - Exit:** Terminates the program.
*Format:* `EXT 00 00`
 - This instruction does not take any argument but halts the program execution.



**LOD 01 - Load:** Loads a value from memory into a register.
*Format:* `LOD [REGISTER] [VALUE]`
- Example: `LOD 01 02`
- This instruction stores the value 2 into R1.



**STR 02 - Store:** Stores a value from a register into memory.
**Format:** `STR [REGISTER] [MEMORY_ADDRESS]`
- Example: `STR 02 10`
- This instruction stores the value from R2 into memory address 10.



ADD 03 - Add: Adds two values and stores the result in a register.
Format: ADD [DESTINATION_REGISTER] [SOURCE_REGISTER]
Example: ADD 03 01
This instruction adds the values in R1 and R3 and stores the result in R3.
SUB 04 - Subtract: Subtracts one value from another and stores the result in a register.

Format: SUB [DESTINATION_REGISTER] [SOURCE_REGISTER]
Example: SUB 04 02
This instruction subtracts the value in R2 from the value in R4 and stores the result in R4.
MUL 05 - Multiply: Multiplies two values and stores the result in a register.

Format: MUL [DESTINATION_REGISTER] [SOURCE_REGISTER]
Example: MUL 05 03
This instruction multiplies the values in R3 and R5 and stores the result in R5.
DIV 06 - Divide: Divides one value by another and stores the quotient in a register.

Format: DIV [DESTINATION_REGISTER] [SOURCE_REGISTER]
Example: DIV 06 04
This instruction divides the value in R4 by the value in R6 and stores the quotient in R6.
JMP 07 - Jump: Unconditionally jumps to a specified address in the program.

Format: JMP [ADDRESS] 00
Example: JMP 07 00
This instruction jumps to address 07 in the program.
MOD 08 - Modulo: Computes the remainder of dividing one value by another and stores the result in a register.

Format: MOD [DIVIDEND_REGISTER] [DIVISOR_REGISTER]
Example: MOD 15 03 04
This instruction computes the remainder of dividing the value in R3 by the value in R4 and stores the result in R3.
INC 09 - Increment: Increments the value of a register by 1.

Format: INC [REGISTER] 00
Example: INC 01 00
This instruction increments the value in R1 by 1.
DEC 10 - Decrement: Decrements the value of a register by 1.

Format: DEC [REGISTER] 00
Example: DEC 02 00
This instruction decrements the value in R2 by 1.
SWAP 12 - Swap: Swaps the values of two registers.

Format: SWAP [REGISTER1] [REGISTER2]
Example: SWAP 03 04
This instruction swaps the values in R3 and R4.
NOP 13 - No Operation: Does nothing and moves to the next instruction.

Format: NOP 00 00
Example: NOP 00 00
This instruction has no effect and simply moves to the next instruction.
PRT 14 - Print: Print a value or register content to the screen.

Format: PRT [ARGUMENT] [VALUE/REGISTER]
Example: PRT 01 01
If the argument is 1, it prints the value 1; if the argument is 00, it prints the value of R1.
Registers
General-Purpose Registers (R0-R7):

Number: 8 registers
Size: 32-bit
Register	Size (bits)	Description
R0	32	General-Purpose Register
R1	32	General-Purpose Register
R2	32	General-Purpose Register
R3	32	General-Purpose Register
R4	32	General-Purpose Register
R5	32	General-Purpose Register
R6	32	General-Purpose Register
R7	32	General-Purpose Register
These general-purpose registers hold data and address values during instruction execution.

Memory
Size: 64KB
Addressable Unit: Byte
Memory layout:

Each memory location stores an 8-digit decimal value.
The first 2 digits signify the operation to be performed.
The next 3 digits represent the first argument, where the first digit indicates whether it's a value (1) or register (0).
The remaining 3 digits represent the last argument, following the same logic.
Control Unit
The program begins by displaying the default register values, followed by reading instructions from source.txt, decoding them, loading into memory, and executing. After execution, the memory is displayed again, and the program moves to the next instruction.






