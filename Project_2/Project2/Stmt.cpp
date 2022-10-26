#include "opcodes.h"
#include <iostream>

void gosublabel::serialize()
{
    std::cout << "gosublabel" << std::endl;
}

void label::serialize()
{
    std::cout << "label" << std::endl;
}

void pushi::serialize()
{
    std::cout << "pushi" << std::endl;
}

void declscal::serialize()
{
    std::cout << "declscal" << std::endl;
}

void declarr::serialize()
{
    std::cout << "declarr" << std::endl;
}

void start::serialize()
{
    std::cout << "start" << std::endl;
}

void end::serialize()
{
    std::cout << "end" << std::endl;
}

void Exit::serialize()
{
    std::cout << "exit" << std::endl;
}

void jump::serialize()
{
    std::cout << "jump" << std::endl;
}

void jumpzero::serialize()
{
    std::cout << "jumpzero" << std::endl;
}

void jumpnzero::serialize()
{
    std::cout << "jumpnzero" << std::endl;
}

void gosub::serialize()
{
    std::cout << "gosub" << std::endl;
}

void Return::serialize()
{
    std::cout << "return" << std::endl;
}

void pushscal::serialize()
{
    std::cout << "pushscal" << std::endl;
}

void pusharr::serialize()
{
    std::cout << "pusharr" << std::endl;
}

void pop::serialize()
{
    std::cout << "pop" << std::endl;
}

void popscal::serialize()
{
    std::cout << "popscal" << std::endl;
}

void poparr::serialize()
{
    std::cout << "poparr" << std::endl;
}

void dup::serialize()
{
    std::cout << "dup" << std::endl;
}

void swap::serialize()
{
    std::cout << "swap" << std::endl;
}

void add::serialize()
{
    std::cout << "add" << std::endl;
}

void negate::serialize()
{
    std::cout << "negate" << std::endl;
}

void mul::serialize()
{
    std::cout << "mul" << std::endl;
}

void Div::serialize()
{
    std::cout << "div" << std::endl;
}

void printtos::serialize()
{
    std::cout << "printtos" << std::endl;
}

void prints::serialize()
{
    std::cout << "prints" << std::endl;
}