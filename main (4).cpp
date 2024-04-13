#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <unordered_map>
#include <vector>

namespace std {

    // Define the number of registers
    const int NUM_REGISTERS = 8;

    // Define the size of each register
    const int REGISTER_SIZE = 32;

    // Define the opcode values
    enum OpCode {
        EXT = 0,
        LOD,
        STR,
        ADD,
        SUB,
        MUL,
        DIV,
        JMP,
        MOD,
        INC,
        DEC,
        SWAP,
        NOP,
        PRT,
        LDM, // Load from memory
        DUP, // Duplicate
        MOV  // Move value
    };

    // Define the instruction format
    struct Instruction {
        OpCode opcode;
        int arg1;
        int arg2;
    };

    // Decode instruction from string
    Instruction decodeInstruction(const std::string& instruction) {
        Instruction decodedInstruction;

        std::stringstream ss(instruction);
        std::string opcodeStr, arg1Str, arg2Str;
        ss >> opcodeStr >> arg1Str >> arg2Str;

        // Convert opcode string to enum value
        std::unordered_map<std::string, OpCode> opcodeMap = {
            {"EXT", EXT},
            {"LOD", LOD},
            {"STR", STR},
            {"ADD", ADD},
            {"SUB", SUB},
            {"MUL", MUL},
            {"DIV", DIV},
            {"JMP", JMP},
            {"MOD", MOD},
            {"INC", INC},
            {"DEC", DEC},
            {"SWAP", SWAP},
            {"NOP", NOP},
            {"PRT", PRT},
            {"LDM", LDM}, // Load from memory
            {"DUP", DUP}, // Duplicate
            {"MOV", MOV}  // Move value
        };
        decodedInstruction.opcode = opcodeMap[opcodeStr];

        // Convert argument strings to integers
        decodedInstruction.arg1 = std::stoi(arg1Str);
        decodedInstruction.arg2 = std::stoi(arg2Str);

        return decodedInstruction;
    }

    // Convert instruction to memory format
    int instructionToMemory(const Instruction& instruction) {
        int memoryInstruction = (instruction.opcode * 1000000) + (instruction.arg1 * 1000) + instruction.arg2;
        return memoryInstruction;
    }

    // Execute instruction
    void executeInstruction(const Instruction& instruction, std::vector<int>& memory, int& instructionAddress, int* registers) {
        std::cout << std::endl << "DECODING:" << std::endl;
        switch (instruction.opcode) {
            case EXT:
                std::cout << std::endl << "EXITING PROGRAM" << std::endl;
                exit(0);
            case LOD:
                std::cout << std::endl << "LOADING VALUE ==============" << std::endl;
                std::cout << "LOADED: " << instruction.arg2 << " into register " << instruction.arg1 << std::endl;
                std::cout << "============================" << std::endl;
                registers[instruction.arg1 - 1] = instruction.arg2;
                break;
            case STR:
                memory[instruction.arg1 - 1] = registers[instruction.arg2 - 1];
                std::cout << std::endl << "STORING VALUE ==============" << std::endl;
                std::cout << "STORED: " << registers[instruction.arg2 - 1] << " in memory location " << instruction.arg1 << std::endl;
                std::cout << "============================" << std::endl;
                break;
            case ADD:
                std::cout << std::endl << "ADDING VALUES ==============" << std::endl;
                std::cout << "ADDED: " << registers[instruction.arg1 - 1] << " and " << registers[instruction.arg2 - 1] << std::endl;
                std::cout << "============================" << std::endl;
                registers[instruction.arg1 - 1] += registers[instruction.arg2 - 1];
                break;
            case SUB:
                std::cout << std::endl << "SUBTRACTING VALUES ==============" << std::endl;
                std::cout << "SUBTRACTED: " << registers[instruction.arg1 - 1] << " and " << registers[instruction.arg2 - 1] << std::endl;
                std::cout << "============================" << std::endl;
                registers[instruction.arg1 - 1] -= registers[instruction.arg2 - 1];
                break;
            case MUL:
                std::cout << std::endl << "MULTIPLYING VALUES ==============" << std::endl;
                std::cout << "MULTIPLIED: " << registers[instruction.arg1 - 1] << " and " << registers[instruction.arg2 - 1] << std::endl;
                std::cout << "============================" << std::endl;
                registers[instruction.arg1 - 1] *= registers[instruction.arg2 - 1];
                break;
            case DIV:
                std::cout << std::endl << "DIVIDING VALUES ==============" << std::endl;
                std::cout << "DIVIDED: " << registers[instruction.arg1 - 1] << " by " << registers[instruction.arg2 - 1] << std::endl;
                std::cout << "============================" << std::endl;
                if (registers[instruction.arg2 - 1] != 0)
                    registers[instruction.arg1 - 1] /= registers[instruction.arg2 - 1];
                break;
            case JMP:
                std::cout << std::endl << "JUMP COMMAND ==============" << std::endl;
                std::cout << "JUMPED to address: " << instruction.arg1 << std::endl;
                std::cout << "============================" << std::endl;
                instructionAddress = instruction.arg1 - 2;
                break;
            case MOD:
                std::cout << std::endl << "TAKING MODULO ==============" << std::endl;
                std::cout << "MODULO: " << registers[instruction.arg1 - 1] << " by " << registers[instruction.arg2 - 1] << std::endl;
                std::cout << "============================" << std::endl;
                registers[instruction.arg1 - 1] %= registers[instruction.arg2 - 1];
                break;
            case INC:
                std::cout << std::endl << "INCREMENTING VALUE ==============" << std::endl;
                std::cout << "INCREMENTED: " << registers[instruction.arg1 - 1] << std::endl;
                std::cout << "============================" << std::endl;
                registers[instruction.arg1 - 1]++;
                break;
            case DEC:
                std::cout << std::endl << "DECREMENTING VALUE ==============" << std::endl;
                std::cout << "DECREMENTED: " << registers[instruction.arg1 - 1] << std::endl;
                std::cout << "============================" << std::endl;
                registers[instruction.arg1 - 1]--;
                break;
            case SWAP:
                std::cout << std::endl << "SWAPPING VALUES ==============" << std::endl;
                std::cout << "SWAPPED: " << registers[instruction.arg1 - 1] << " and " << registers[instruction.arg2 - 1] << std::endl;
                std::cout << "============================" << std::endl;
                std::swap(registers[instruction.arg1 - 1], registers[instruction.arg2 - 1]);
                break;
            case NOP:
                std::cout << std::endl << "============================" << std::endl;
                std::cout <<  "NO OPERATION" << std::endl;
                std::cout << "============================" << std::endl;
                break;
            case PRT:
                if (instruction.arg1 == 0) {
                    std::cout << std::endl << "PRINT COMMAND ==============" << std::endl;
                    std::cout << "PRINT:" << registers[instruction.arg2 - 1] << std::endl;
                    std::cout << "============================" << std::endl;
                }
                else {
                    std::cout << std::endl << "PRINT COMMAND ==============" << std::endl;
                    std::cout <<  "PRINT:" <<  instruction.arg2 << std::endl;
                    std::cout << "============================" << std::endl;
                }
                break;
            case LDM:
                std::cout << std::endl << "LOADING VALUE FROM MEMORY ==============" << std::endl;
                std::cout << "LOADED: " << memory[instruction.arg2 - 1] << " into register " << instruction.arg1 << std::endl;
                std::cout << "========================================" << std::endl;
                registers[instruction.arg1 - 1] = memory[instruction.arg2 - 1];
                break;
            case DUP:
                std::cout << std::endl << "DUPLICATING VALUE ==============" << std::endl;
                std::cout << "DUPLICATED: " << registers[instruction.arg1 - 1] << " into register " << instruction.arg2 << std::endl;
                std::cout << "================================" << std::endl;
                registers[instruction.arg2 - 1] = registers[instruction.arg1 - 1];
                break;
            case MOV:
                std::cout << std::endl << "MOVING VALUE ==============" << std::endl;
                std::cout << "MOVED: " << registers[instruction.arg1 - 1] << " into register " << instruction.arg2 << std::endl;
                std::cout << "============================" << std::endl;
                registers[instruction.arg2 - 1] = registers[instruction.arg1 - 1];
                registers[instruction.arg1 - 1] = 0;
                break;
            default:
                std::cerr << "Unknown opcode" << std::endl;
        }
    }

    // Print the current state of the registers
    void printRegisters(int* registers) {
        std::cout << "REGISTER [Current State]" << std::endl;
        std::cout << "===================" << std::endl;
        for (int i = 0; i < NUM_REGISTERS; ++i) {
            std::cout << std::setw(2) << std::setfill('R') << i + 1 << " = ";
            std::cout << std::setw(3) << std::setfill('0') << registers[i] << std::endl;
        }
        std::cout << "===================" << std::endl;
    }

    // Print the current state of the memory
    void printMemory(const std::vector<int>& memory, int numInstructions, int currentInstruction) {
        std::cout << "FETCH FROM MEMORY:" << std::endl;
        for (int i = 0; i < numInstructions + 10; ++i) {
            std::cout << "0x" << std::hex << std::setw(2) << std::setfill('0') << i + 1 << ": ";
            std::cout << std::setw(8) << std::setfill('0') << std::dec << memory[i];
            if (i == currentInstruction)
                std::cout << " <- Current Instruction";
            std::cout << std::endl;
        }
    }

    int main() {
        // Define the maximum number of instructions
        const int MAX_INSTRUCTIONS = 100;

        // Define the memory to store instructions
        std::vector<int> memory(MAX_INSTRUCTIONS, 0);

        // Define the registers
        int registers[NUM_REGISTERS] = {0};

        // Display initial state of registers
        std::cout << "REGISTER [Initial State]" << std::endl;
        std::cout << "===================" << std::endl;
        for (int i = 0; i < NUM_REGISTERS; ++i) {
            std::cout << std::setw(2) << std::setfill('R') << i + 1 << " = ";
            std::cout << std::setw(3) << std::setfill('0') << registers[i] << std::endl;
        }
        std::cout << "===================" << std::endl;

        // Read instructions from source.txt
        std::ifstream sourceFile("source.txt");
        if (!sourceFile.is_open()) {
            std::cerr << "Unable to open source file" << std::endl;
            return 1;
        }

        std::string line;
        int numInstructions = 0;

        // Convert instructions to memory
        while (std::getline(sourceFile, line) && numInstructions < MAX_INSTRUCTIONS) {
            Instruction decodedInstruction = decodeInstruction(line);
            memory[numInstructions] = instructionToMemory(decodedInstruction);
            ++numInstructions;
        }

        sourceFile.close();

        // Execute instructions
        int instructionAddress = 0;
        int programCounter = 1;
        while (instructionAddress < numInstructions) {
            
            int currentInstruction = memory[instructionAddress];
            Instruction decodedInstruction;
            decodedInstruction.opcode = static_cast<OpCode>(currentInstruction / 1000000);
            decodedInstruction.arg1 = (currentInstruction / 1000) % 1000;
            decodedInstruction.arg2 = currentInstruction % 1000;

            std::cout << std::endl << endl;
            printMemory(memory, numInstructions, instructionAddress);

            executeInstruction(decodedInstruction, memory, instructionAddress, registers);
            std::cout << std::endl << endl;
            
            std::cout << "Program Counter: " << programCounter << std::endl;
            printRegisters(registers);
            std::cout << "Executed Instruction: " << memory[instructionAddress] << endl << "Next Instructions: [";
            for (int i = 1; i < 4; ++i) {
                std::cout << std::setw(8) << std::setfill('0') << std::dec << memory[instructionAddress + i];
                if (i < 3) std::cout << " ";
            }

            std::cout << "]" << std::endl;

            ++instructionAddress;
            programCounter++;
        }

        return 0;
    }

} // namespace std

int main() {
    return std::main();
}
