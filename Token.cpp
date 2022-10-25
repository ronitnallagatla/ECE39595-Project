#include "Token.h"
#include <cstring>
#include <iostream>
#include <string>

// Token::Token(std::string inst, std::string op1, std::string op2, std::string op3, std::string op4, std::string op5, std::string op6, std::string op7)
// {
//     this->inst = inst;
//     this->op1 = op1;
//     this->op2 = op2;
// }

Token::Token(std::string line)
{
    tokenize(line);
}

std::string Token::getInst()
{
    return inst;
}

std::string Token::getOp1()
{
    return op1;
}

std::string Token::getOp2()
{
    return op2;
}

void Token::printTokens() const
{
    std::cout << "Opcode: " << inst << std::endl;
    std::cout << "Operand 1: " << op1 << std::endl;
    std::cout << "Operand 2: " << op2 << std::endl;
}

void Token::tokenize(std::string s)
{
    setInstruction(s);
    tokenize();
}

void Token::tokenize()
{
    char *ptr, *str;
    str = &inst[0];
    ptr = strtok(str, " , ");

    while (ptr != NULL) {
        setOp(ptr);
        ptr = strtok(NULL, " , ");
    }
}

void Token::setOp(char* s)
{
    std::string str(s);

    i++;

    op1 = (i == 1) ? str : op1;

    op2 = (i == 2) ? str : op2;
}