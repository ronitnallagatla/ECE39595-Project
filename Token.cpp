#include "Token.h"
#include <cstring>
#include <iostream>

Token::Token(std::string str)
{
    Token::inst = str;
}

void Token::setInstruction(std::string ins)
{
    Token::inst = ins;
}

void Token::setOp(char* s)
{
    std::string str(s);
    i++;

    if (i == 1) {
        op1 = str;
    }

    else if (i == 2) {
        op2 = str;
    }

    // else if (i == 3) {
    //     op3 = str;
    // }

    // else {
    //     op4 = str;
    // }
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
    ptr = strtok(str, ", ");

    while (ptr != NULL) {
        setOp(ptr);
        ptr = strtok(NULL, ", ");
    }
}