#include <iostream>
#include <string>

#include "Instruction.h"

Instruction::Instruction()
{
    op = 0;
    op1 = 0;
    op2 = 0;
    jumpaddr = 0;
}

Instruction::Instruction(int _opcode, int _op1, int _op2, int _jump)
{
    op = _opcode;
    op1 = _op1;
    op2 = _op2;
    jumpaddr = _jump;
}

int Instruction::getOpcode() const
{
    return op;
}

int Instruction::getOp1() const
{
    return op1;
}

int Instruction::getOp2() const
{
    return op2;
}

int Instruction::getJump() const
{
    return jumpaddr;
}

void Instruction::setOpcode(int _opcode)
{
    op = _opcode;
}

void Instruction::setOp1(int _op1)
{
    op1 = _op1;
}

void Instruction::setOp2(int _op2)
{
    op2 = _op2;
}

void Instruction::setJump(int _jump)
{
    jumpaddr = _jump;
}

void Instruction::print_instruction()
{
    std::cout << "Opcode: " << op << std::endl;
    std::cout << "Op1: " << op1 << std::endl;
    std::cout << "Op2: " << op2 << std::endl;
    std::cout << "Jump: " << jumpaddr << std::endl;
}