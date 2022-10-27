#ifndef INSTRUCTIONBUFFER_H_
#define INSTRUCTIONBUFFER_H_

#include "Instruction.h"
#include "opcodes.h"
#include <queue>

class InstructionBuffer {
private:
    static InstructionBuffer* instance;
    InstructionBuffer();
    // std::queue<Instruction*> buffer;
    std::vector<Instruction*> buffer;

public:
    static InstructionBuffer* getInstance();
    void add(Instruction* stmt);
    void print();
    // bool isEmpty();
};

#endif /* INSTRUCTIONBUFFER_H_ */