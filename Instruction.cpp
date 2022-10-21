#include <iostream>
#include <string>

#include "Instruction.h"

Instruction::Instruction()
{
    op = "";
    op1 = "";
    op2 = "";
    jumpaddr = "";
}

Instruction::Instruction(std::string _opcode, std::string _op1, std::string _op2, std::string _jump)
{
    op = _opcode;
    op1 = _op1;
    op2 = _op2;
    jumpaddr = _jump;
}

std::string Instruction::getOpcode() const
{
    return op;
}

std::string Instruction::getOp1() const
{
    return op1;
}

std::string Instruction::getOp2() const
{
    return op2;
}

std::string Instruction::getJump() const
{
    return jumpaddr;
}

void Instruction::setOpcode(std::string _opcode)
{
    op = _opcode;
}

void Instruction::setOp1(std::string _op1)
{
    op1 = _op1;
}

void Instruction::setOp2(std::string _op2)
{
    op2 = _op2;
}

void Instruction::setJump(std::string _jump)
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