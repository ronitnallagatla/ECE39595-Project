#include "Token.h"
#include <cstring>
#include <iostream>
#include <string>

Token::Token(std::string str)
{
    Token::inst = str;
}

void Token::setInstruction(std::string ins)
{
    Token::inst = ins;
}

void Token::set_op(char* s)
{
    std::string str(s);
    i++;
    
    if (i == 1) {
        inst = str;
    }

    else if (i == 2) {
        op1 = str;
    }

    else if (i == 3) {
        op2 = str;
    }

    else {
        op3 = str;
    }
}

void Token::print_tokens() const
{
    std::cout << "Opcode: " << inst << std::endl;
    std::cout << "Operand 1: " << op1 << std::endl;
    std::cout << "Operand 2: " << op2 << std::endl;
    std::cout << "Operand 3: " << op3 << std::endl;
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
        set_op(ptr);
        ptr = strtok(NULL, ", ");
    }
}