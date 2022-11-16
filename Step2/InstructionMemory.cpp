#include <iostream>

#include "InstructionMemory.h"

InstructionMemory* InstructionMemory::instance = nullptr;

InstructionMemory::InstructionMemory() { }

InstructionMemory* InstructionMemory::getInstance()
{
    if (instance == nullptr) {
        instance = new InstructionMemory();
    }
    return instance;
}

void InstructionMemory::addInstruction(std::unique_ptr<Instruction> instruction)
{
    instructions.push_back(std::move(instruction));
}

Instruction* InstructionMemory::getInstruction()
{
    return instructions[pc].get();
}

void InstructionMemory::setPC(int pc)
{
    this->pc = pc;
}

int InstructionMemory::getPC()
{
    return pc;
}
