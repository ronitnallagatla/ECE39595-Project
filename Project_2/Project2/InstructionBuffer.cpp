#include <iostream>
#include <queue>

#include "InstructionBuffer.h"
#include "opcodes.h"

InstructionBuffer* InstructionBuffer::instance = nullptr;

InstructionBuffer::InstructionBuffer() { }

InstructionBuffer* InstructionBuffer::getInstance()
{
    if (instance == nullptr) {
        instance = new InstructionBuffer();
    }
    return instance;
}

void InstructionBuffer::add(Instruction* stmt)
{
    buffer.push(stmt);
}

void InstructionBuffer::print()
{
    while (!buffer.empty()) {
        Instruction* stmt = buffer.front();
        buffer.pop();
        stmt->serialize();
    }
}

bool InstructionBuffer::isEmpty()
{
    return buffer.empty();
}
