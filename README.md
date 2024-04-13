# csmc223-midterm-project
This repo will host the files used for the Midterm project about the Processor Simulator.

## How to Use

### Writing Instructions in source.txt
1. Open the `source.txt` file in a text editor.
2. Each line in the file represents an instruction to be executed by the program.
3. Write instructions in the following format:
   - `OPCODE ARG1 ARG2`: Each instruction consists of an OpCode followed by one or two arguments.
   - Example: `LOD 01 100`: This instruction loads the value `100` into register `01`.
   - Each line should only have on instruction.
4. Save the changes to the `source.txt` file.

### Running the Program
1. Compile the program using a C++ compiler. For example:
   ```cmd
   g++ -o program_name program_source.cpp
2. Run the compiled program
   ```cmd
   ./program_name
3. The program will read the instructions from source.txt, execute them, and display the results.


## Instructional Set Architecture (ISA)

  
### Instruction Set
The Instruction Set Architecture (ISA) defines the set of instructions that a processor can execute, along with their formats and behavior. In this architecture, the ISA is designed to facilitate the execution of instructions by a hypothetical processor.

**OpCodes:** Each instruction is represented by a unique OpCode, which specifies the operation to be performed.

### Supported Operations:
| Instruction | Format                                   | Description                                                                                         | Example                                       |
|-------------|------------------------------------------|-----------------------------------------------------------------------------------------------------|-----------------------------------------------|
| **EXT 00**  | `EXT 00 00`                              | Terminates the program.                                                                             | -                                             |
| **LOD 01**  | `LOD [REGISTER] [VALUE]`                 | Loads a value into a register.                                                                      | `LOD 01 02`<br>(Loads the value 2 into register R1) |
| **STR 02**  | `STR [REGISTER] [MEMORY_ADDRESS]`        | Stores a value from a register into memory.                                                          | `STR 02 10`<br>(Stores the value from register R2 into memory address 10) |
| **ADD 03**  | `ADD [DESTINATION_REGISTER] [SOURCE_REGISTER]` | Adds two values and stores the result in a register.                                            | `ADD 03 01`<br>(Adds the values in register R1 and R3, storing the result in R3) |
| **SUB 04**  | `SUB [DESTINATION_REGISTER] [SOURCE_REGISTER]` | Subtracts one value from another and stores the result in a register.                            | `SUB 04 02`<br>(Subtracts the value in R2 from the value in R4, storing the result in R4) |
| **MUL 05**  | `MUL [DESTINATION_REGISTER] [SOURCE_REGISTER]` | Multiplies two values and stores the result in a register.                                        | `MUL 05 03`<br>(Multiplies the values in R3 and R5, storing the result in R5) |
| **DIV 06**  | `DIV [DESTINATION_REGISTER] [SOURCE_REGISTER]` | Divides one value by another and stores the quotient in a register.                                | `DIV 06 04`<br>(Divides the value in R4 by the value in R6, storing the quotient in R6) |
| **JMP 07**  | `JMP [ADDRESS] 00`                       | Unconditionally jumps to a specified address in the program.                                        | `JMP 07 00`<br>(Unconditionally jumps to address 07 in the program) |
| **MOD 08**  | `MOD [DIVIDEND_REGISTER] [DIVISOR_REGISTER]` | Computes the remainder of dividing one value by another and stores the result in a register.   | `MOD 15 03 04`<br>(Computes the remainder of dividing the value in R3 by the value in R4, storing the result in R3) |
| **INC 09**  | `INC [REGISTER] 00`                      | Increments the value of a register by 1.                                                            | `INC 01 00`<br>(Increments the value in R1 by 1) |
| **DEC 10**  | `DEC [REGISTER] 00`                      | Decrements the value of a register by 1.                                                            | `DEC 02 00`<br>(Decrements the value in R2 by 1) |
| **SWAP 12** | `SWAP [REGISTER1] [REGISTER2]`           | Swaps the values of two registers.                                                                  | `SWAP 03 04`<br>(Swaps the values in registers R3 and R4) |
| **NOP 13**  | `NOP 00 00`                              | No operation; moves to the next instruction.                                                         | `NOP 00 00`<br>(No operation; moves to the next instruction) |
| **PRT 14**  | `PRT [ARGUMENT] [VALUE/REGISTER]`        | Prints a value or register content to the screen.                                                   | `PRT 01 01`<br>(If the argument is 1, prints the value 1; if the argument is 00, prints the value of R1) |
| **LDM 15**  | `LDM [REGISTER] [MEMORY_ADDRESS]`        | Loads a value from memory into a register.                                                          | `LDM 08 10`<br>(Loads the value from memory address 10 into register R8) |
| **DUP 16**  | `DUP [SOURCE_REGISTER] [DESTINATION_REGISTER]` | Duplicates the value of a register and stores it in another register.                          | `DUP 03 05`<br>(Duplicates the value in R3 and stores it in R5) |
| **MOV 17**  | `MOV [SOURCE_REGISTER] [DESTINATION_REGISTER]` | Moves the value of one register into another register.                                         | `MOV 08 02`<br>(Moves the value of R8 into register R2) |



## Registers

### General-Purpose Registers (R0-R7):
- **Number:** 8 registers
- **Size:** 32-bit

These general-purpose registers will be used to hold data and address values during the execution of instructions. Each register will be 32 bits in size, allowing for the storage of integers, memory addresses, and other data types commonly used in processor operations.

| Register | Size (bits) | Description          |
|----------|-------------|----------------------|
| R1       | 32          | General-Purpose Register |
| R2       | 32          | General-Purpose Register |
| R3       | 32          | General-Purpose Register |
| R4       | 32          | General-Purpose Register |
| R5       | 32          | General-Purpose Register |
| R6       | 32          | General-Purpose Register |
| R7       | 32          | General-Purpose Register |
| R8       | 32          | General-Purpose Register |


## Memory

- **Size:** 64KB
- **Addressable Unit:** Byte

Values/Instructions stored in memory are represented as an 8-digit decimal.

### Memory Layout:
Each memory location stores an 8-digit decimal value, where:
- The first 2 digits signify the operation the CPU must perform.
- The next 3 digits represent the first argument that will be used.
- The remaining 3 digits represent the last argument for the operation.
- At most, each argument can only support 3 digit number, in which the maximum will be 999.
  
**Example:**
For the instruction `LOD 01 01`, it would be represented in memory as `01 001 001`.
In this example:
- The `01` represents the opcode (LOD).
- The first argument is `001`, which means it's a register (R1).
- The last argument is `001`, indicating a value of 1.

So, the meaning of the code is to load the value 1 into register 1.

## Memory Addressing

Memory addresses in this system range from `0x01` to `0xFF`, allowing for a total of 255 memory locations. Each memory address represents a byte of data, and instructions or values are stored sequentially from the lowest address (`0x01`) to the highest address (`0xFF`).

### Address Range:
- **Starting Address:** `0x01`
- **Ending Address:** `0xFF`
- **Total Number of Addresses:** 255

### Memory Organization:
- Memory addresses are used to reference specific locations in the memory space.
- Instructions and data values are stored in consecutive memory locations, with each location storing a single byte of information.
- The memory is byte-addressable, meaning each memory address points to a single byte of data.
- The memory is organized linearly, with the lowest address (`0x01`) at the beginning and the highest address (`0xFF`) at the end.

This addressing scheme allows for efficient access to instructions and data stored in memory during program execution.


## Control Unit

The control unit manages the execution flow of the program and coordinates the processing of instructions. Here's how it operates:

1. **Displaying Default Register Values**: 
   - The program starts by displaying the default values of the registers, all of which are initially set to 0.

2. **Reading Instructions from source.txt**:
   - Instructions are read line by line from the `source.txt` file.
   - Each instruction is then translated into an 8-bit data representation based on the instruction format.

3. **Storing Instructions in Memory**:
   - The translated instructions are stored sequentially in the memory, starting from the first address.
   - Memory addresses range from `0x01` to `0xFF`.

4. **Executing Instructions**:
   - The program begins execution by fetching the instruction stored at the first memory address.
   - After executing the instruction, the control unit updates the state of the registers and memory accordingly.
   - The program counter is also incremented.
   
5. **Displaying Register Memory State**:
   - After executing each instruction, the program displays the state of the register memory, showing any updates made during execution.

6. **Moving to the Next Instruction**:
   - The control unit then moves to the next memory address to fetch and execute the next instruction.
   - This process continues until all instructions in memory have been executed or until the program encounters an exit instruction (`EXT`) or an error condition.

7. **Ending Program Execution**:
   - If there are no more instructions left in memory, the program ends execution.

This control unit ensures the orderly execution of instructions and facilitates the processing of data within the program.

### Sample Instruction set from source file
   ```source.txt
REGISTER [Initial State]
===================
R1 = 000
R2 = 000
R3 = 000
R4 = 000
R5 = 000
R6 = 000
R7 = 000
R8 = 000
===================


FETCH FROM MEMORY:
0x01: 01001010 <- Current Instruction
0x02: 02004001
0x03: 00000000
0x04: 00000000
0x05: 00000000
0x06: 00000000
0x07: 00000000
0x08: 00000000
0x09: 00000000
0x0a: 00000000
0x0b: 00000000
0x0c: 00000000
0x0d: 00000000

DECODING:

LOADING VALUE ==============
LOADED: 10 into register 1
============================


Program Counter: 1
REGISTER [Current State]
===================
R1 = 010
R2 = 000
R3 = 000
R4 = 000
R5 = 000
R6 = 000
R7 = 000
R8 = 000
===================
Executed Instruction: 1001010
Next Instructions: [02004001 00000000 00000000]


FETCH FROM MEMORY:
0x01: 01001010
0x02: 02004001 <- Current Instruction
0x03: 00000000
0x04: 00000000
0x05: 00000000
0x06: 00000000
0x07: 00000000
0x08: 00000000
0x09: 00000000
0x0a: 00000000
0x0b: 00000000
0x0c: 00000000
0x0d: 00000000

DECODING:

STORING VALUE ==============
STORED: 10 in memory location 4
============================


Program Counter: 2
REGISTER [Current State]
===================
R1 = 010
R2 = 000
R3 = 000
R4 = 000
R5 = 000
R6 = 000
R7 = 000
R8 = 000
===================
Executed Instruction: 2004001
Next Instructions: [00000000 00000010 00000000]


FETCH FROM MEMORY:
0x01: 01001010
0x02: 02004001
0x03: 00000000 <- Current Instruction
0x04: 00000010
0x05: 00000000
0x06: 00000000
0x07: 00000000
0x08: 00000000
0x09: 00000000
0x0a: 00000000
0x0b: 00000000
0x0c: 00000000
0x0d: 00000000

DECODING:

EXITING PROGRAM
```






