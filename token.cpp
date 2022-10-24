#ifndef _TOKEN_H_
#define _TOKEN_H_

#include "Instruction.h"
#include <cstring>
#include <iostream>

class Token {
private:
    int i = 0;
    void set_op(char* s);

public:
    Token(std::string str);
    void print_tokens() const;

    void tokenize(std::string s);
    void tokenize();

    std::string op1 = "/0";
    std::string op2 = "/0";
    std::string op3 = "/0";
    std::string op4 = "/0";
    std::string op5 = "/0";
    std::string op6 = "/0";
    std::string op7 = "/0";
    std::string inst = "/0";

protected:
    void set_instruction(std::string ins);
};

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

    else if (i == 4) {
        op4 = str;
    }

    else if (i == 5) {
        op5 = str;
    }

    else if (i == 6) {
        op6 = str;
    }

    else {
        op7 = str;
    }
}

void Token::print_tokens() const
{
    std::cout << "op1: " << op1 << std::endl;
    std::cout << "op2: " << op2 << std::endl;
    std::cout << "op3: " << op3 << std::endl;
    std::cout << "op4: " << op4 << std::endl;
    std::cout << "op5: " << op5 << std::endl;
    std::cout << "op6: " << op6 << std::endl;
    std::cout << "op7: " << op7 << std::endl;
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
    ptr = strtok(str, " , ");

    while (ptr != NULL) {
        set_op(ptr);
        ptr = strtok(NULL, " , ");
    }
}

#endif

// /* Uncomment to test tokenizer
int main()
{
    std::string st = "JumpZero, FIBL0, (18)";
    std::string st2 = "PushScalar A, (0)";
    std::string st3 = "Prints 2+6=";

    Token t1(st);
    Token t2(st2);
    Token t3(st3);

    t1.tokenize();
    t2.tokenize();
    t3.tokenize();

    t1.print_tokens();
    t2.print_tokens();
    t3.print_tokens();
    return 0;
}
// */