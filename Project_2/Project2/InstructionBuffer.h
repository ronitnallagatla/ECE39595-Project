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
    int size();
    // Stmt* get(int i);
    Stmt* get();
    void print();
    bool isEmpty();
};

#endif /* INSTRUCTIONBUFFER_H_ */