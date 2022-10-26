#include "opcodes.h"
#include <iostream>

void gosublabel::serialize()
{
    std::cout << "GoSubLabel" << std::endl;
}

void label::serialize()
{
    std::cout << "Label" << std::endl;
}

void pushi::serialize()
{
    std::cout << "PushI" << std::endl;
}

void declscal::serialize()
{
    std::cout << "DeclScalar" << std::endl;
}

void declarr::serialize()
{
    std::cout << "DeclArray" << std::endl;
}

void start::serialize()
{
    std::cout << "Start" << std::endl;
}

void end::serialize()
{
    std::cout << "End" << std::endl;
}

void Exit::serialize()
{
    std::cout << "Exit" << std::endl;
}

void jump::serialize()
{
    std::cout << "Jump" << std::endl;
}

void jumpzero::serialize()
{
    std::cout << "Jumpzero" << std::endl;
}

void jumpnzero::serialize()
{
    std::cout << "JumpNZero" << std::endl;
}

void gosub::serialize()
{
    std::cout << "GoSub" << std::endl;
}

void Return::serialize()
{
    std::cout << "Return" << std::endl;
}

void pushscal::serialize()
{
    std::cout << "PushScalar" << std::endl;
}

void pusharr::serialize()
{
    std::cout << "PushArray" << std::endl;
}

void pop::serialize()
{
    std::cout << "Pop" << std::endl;
}

void popscal::serialize()
{
    std::cout << "PopScalar" << std::endl;
}

void poparr::serialize()
{
    std::cout << "PopArray" << std::endl;
}

void dup::serialize()
{
    std::cout << "Dup" << std::endl;
}

void swap::serialize()
{
    std::cout << "Swap" << std::endl;
}

void add::serialize()
{
    std::cout << "Add" << std::endl;
}

void negate::serialize()
{
    std::cout << "Negate" << std::endl;
}

void mul::serialize()
{
    std::cout << "Mul" << std::endl;
}

void Div::serialize()
{
    std::cout << "Div" << std::endl;
}

void printtos::serialize()
{
    std::cout << "PrintTOS" << std::endl;
}

void prints::serialize()
{
    std::cout << "Prints" << std::endl;
}