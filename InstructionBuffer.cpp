#include <iostream>
#include <queue>

#include "InstructionBuffer.h"
#include "Stmt.h"

InstructionBuffer* InstructionBuffer::instance = 0;

InstructionBuffer::InstructionBuffer() { }

InstructionBuffer* InstructionBuffer::getInstance()
{
    if (instance == nullptr) {
        instance = new InstructionBuffer();
    }
    return instance;
}

void InstructionBuffer::add(Stmt* stmt)
{
    buffer.push(stmt);
}

void InstructionBuffer::print()
{
    while (!buffer.empty()) {
        Stmt* stmt = buffer.front();
        buffer.pop();
        stmt->serialize();
    }
}

bool InstructionBuffer::isEmpty()
{
    return buffer.empty();
}
