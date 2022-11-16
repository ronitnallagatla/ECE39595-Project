#ifndef INSTRUCTIONMEMORY_H_
#define INSTRUCTIONMEMORY_H_

#include "opcodes.h"
#include <memory>
#include <string>
#include <vector>

class InstructionMemory {
private:
    InstructionMemory();
    static InstructionMemory* instance;
    std::vector<std::unique_ptr<Instruction>> instructions;
    int pc;

public:
    static InstructionMemory* getInstance();
    void addInstruction(std::unique_ptr<Instruction> instruction);
    Instruction* getInstruction();
    void setPC(int pc);
    int getPC();
};

#endif /* INSTRUCTIONMEMORY_H_ */