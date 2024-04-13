# csmc223-midterm-project
This repo will host the files used for the Midterm project about the Processor Simulator.


## Instructional Set Architecture (ISA)

  
### Instruction Set
The Instruction Set Architecture (ISA) defines the set of instructions that a processor can execute, along with their formats and behavior. In this architecture, the ISA is designed to facilitate the execution of instructions by a hypothetical processor.

**OpCodes:** Each instruction is represented by a unique OpCode, which specifies the operation to be performed.

### Supported Operations:
#### **EXT 00 - Exit**
- **Format:** `EXT 00 00`
- Terminates the program.
  
#### **LOD 01 - Load**
- **Format:** `LOD [REGISTER] [VALUE]`
- Example: `LOD 01 02`
  - Loads the value 2 into register R1.
  
#### **STR 02 - Store**
- **Format:** `STR [REGISTER] [MEMORY_ADDRESS]`
- Example: `STR 02 10`
  - Stores the value from register R2 into memory address 10.
  
#### **ADD 03 - Add**
- **Format:** `ADD [DESTINATION_REGISTER] [SOURCE_REGISTER]`
- Example: `ADD 03 01`
  - Adds the values in register R1 and R3, storing the result in R3.
  
#### **SUB 04 - Subtract**
- **Format:** `SUB [DESTINATION_REGISTER] [SOURCE_REGISTER]`
- Example: `SUB 04 02`
  - Subtracts the value in R2 from the value in R4, storing the result in R4.
  
#### **MUL 05 - Multiply**
- **Format:** `MUL [DESTINATION_REGISTER] [SOURCE_REGISTER]`
- Example: `MUL 05 03`
  - Multiplies the values in R3 and R5, storing the result in R5.

#### **DIV 06 - Divide**
- **Format:** `DIV [DESTINATION_REGISTER] [SOURCE_REGISTER]`
- Example: `DIV 06 04`
  - Divides the value in R4 by the value in R6, storing the quotient in R6.

#### **JMP 07 - Jump**
- **Format:** `JMP [ADDRESS] 00`
- Example: `JMP 07 00`
  - Unconditionally jumps to address 07 in the program.

#### **MOD 08 - Modulo**
- **Format:** `MOD [DIVIDEND_REGISTER] [DIVISOR_REGISTER]`
- Example: `MOD 15 03 04`
  - Computes the remainder of dividing the value in R3 by the value in R4, storing the result in R3.

#### **INC 09 - Increment**
- **Format:** `INC [REGISTER] 00`
- Example: `INC 01 00`
  - Increments the value in R1 by 1.

#### **DEC 10 - Decrement**
- **Format:** `DEC [REGISTER] 00`
- Example: `DEC 02 00`
  - Decrements the value in R2 by 1.

#### **SWAP 12 - Swap**
- **Format:** `SWAP [REGISTER1] [REGISTER2]`
- Example: `SWAP 03 04`
  - Swaps the values in registers R3 and R4.

#### **NOP 13 - No Operation**
- **Format:** `NOP 00 00`
- Example: `NOP 00 00`
  - Does nothing and moves to the next instruction.

#### **PRT 14 - Print**
- **Format:** `PRT [ARGUMENT] [VALUE/REGISTER]`
- Example: `PRT 01 01`
  - If the argument is 1, prints the value 1; if the argument is 00, prints the value of R1.

#### **LDM 15 - Load from Memory**
- **Format:** `LDM [REGISTER] [MEMORY_ADDRESS]`
- Example: `LDM 08 10`
  - Loads the value from memory address 10 into register R8.

#### **DUP 16 - Duplicate Value**
- **Format:** `DUP [SOURCE_REGISTER] [DESTINATION_REGISTER]`
- Example: `DUP 03 05`
  - Duplicates the value in R3 and stores it in R5.

#### **MOV 17 - Move Value**
- **Format:** `MOV [VALUE] [REGISTER]`
- Example: `MOV 10 02`
  - Moves the value 10 into register R2.


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
- The last argument is `101`, indicating a value of 1.

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








