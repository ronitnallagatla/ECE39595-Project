#include <iostream>

#include "InstructionMemory.h"
#include "opcodes.h"

InstructionMemory* InstructionMemory::instance = nullptr;

InstructionMemory::InstructionMemory() { }

InstructionMemory* InstructionMemory::getInstance()
{
    if (instance == nullptr) {
        instance = new InstructionMemory();
    }
    return instance;
}

void InstructionMemory::addInstruction(Instruction* instruction)
{
    instructions.push_back(instruction);
}

Instruction* InstructionMemory::getInstruction(int instr)
{
    if (instr < instructions.size()) {
        return instructions[instr];
    }
    std::cerr << "Attempt to read invalid instruction at " << instr << std::endl;
    return nullptr;
}

Instruction* InstructionMemory::getInstruction()
{
    return instructions[pc];
}

void InstructionMemory::setPC(int pc)
{
    this->pc = pc;
}

int InstructionMemory::getPC()
{
    return pc + 1;
}

int InstructionMemory::getSize()
{
    return instructions.size();
}