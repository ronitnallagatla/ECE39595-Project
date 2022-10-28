#ifndef INSTRUCTIONBUFFER_H_
#define INSTRUCTIONBUFFER_H_

#include "Stmt.h"
#include <queue>

class InstructionBuffer {
private:
    static InstructionBuffer* instance;
    InstructionBuffer();
    std::queue<Stmt*> buffer;

public:
    static InstructionBuffer* getInstance();
    void add(Stmt* stmt);
    void print();
    bool isEmpty();
};

#endif /* INSTRUCTIONBUFFER_H_ */

/*
#include "InstructionBuffer.h"
InstructionBuffer* instance = InstructBuffer::getInstance();
instance->add(new pushscal("x"));

 InstructBuffer::getInstance()->add(new pushscal("x"));

*/