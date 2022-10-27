#ifndef INSTRUCTIONBUFFER_H_
#define INSTRUCTIONBUFFER_H_

#include "Stmt.h"
#include "opcodes.h"
#include <queue>

class InstructionBuffer {
private:
    static InstructionBuffer* instance;
    InstructionBuffer();
    std::queue<Instruction*> buffer;

public:
    static InstructionBuffer* getInstance();
    void add(Instruction* stmt);
    int size();
    // Stmt* get(int i);
    Instruction* get();
    void print();
    bool isEmpty();
};

#endif /* INSTRUCTIONBUFFER_H_ */