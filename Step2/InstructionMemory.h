#ifndef INSTRUCTIONMEMORY_H_
#define INSTRUCTIONMEMORY_H_

#include <memory>
#include <string>
#include <vector>

#include "opcodes.h"

class InstructionMemory {
private:
    InstructionMemory();
    static InstructionMemory* instance;
    std::vector <Instruction*> instructions;
    int pc;

public:
    static InstructionMemory* getInstance();
    Instruction* getInstruction(int instr);
    void addInstruction(Instruction* instruction);
    Instruction* getInstruction();
    void setPC(int pc);
    int getPC();
    int return_index;
    int getSize();
};

#endif /* INSTRUCTIONMEMORY_H_ */