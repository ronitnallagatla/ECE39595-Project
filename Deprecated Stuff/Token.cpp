#include <cstring>
#include <iostream>
#include "Token.h"

Token::Token(std::string str)
{
    Token::inst = str;
}

void Token::set_instruction(std::string ins)
{
    Token::inst = ins;
}

void Token::set_op(char* s)
{
    std::string str(s);
    i++;
    
    if (i == 1) {
        op1 = str;
    }

    else if (i == 2) {
        op2 = str;
    }

    else if (i == 3) {
        op3 = str;
    }

    else {
        op4 = str;
    }
}

void Token::print_tokens() const
{
    std::cout << "Opcode: " << op1 << std::endl;
    std::cout << "Operand 1: " << op2 << std::endl;
    std::cout << "Operand 2: " << op3 << std::endl;
    std::cout << "Operand 3: " << op4 << std::endl;
}

void Token::tokenize(std::string s)
{
    set_instruction(s);
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