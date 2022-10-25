#include "Stmt.h"
#include "opcodes.h"

#include <iostream>
#include <string>

// Label::Label(std::string label)
// {
// }

Gosublabel::Gosublabel(std::string label)
{
    opcode = OP_ENTER_SUBROUTINE;
    label = label;
}

void Gosublabel::serialize()
{
    std::cout << "Gosublabel" << std::endl;
}

void Start::serialize()
{
    std::cout << "Start" << std::endl;
}

void End::serialize()
{
    std::cout << "End" << std::endl;
}

void Exit::serialize()
{
    std::cout << "Exit" << std::endl;
}

Jump::Jump(std::string label)
{
    opcode = OP_JUMP;
    label = label;
}

void Jump::serialize()
{
    std::cout << "Jump" << std::endl;
}

Jumpzero::Jumpzero(std::string label)
{
    opcode = OP_JUMPZERO;
    label = label;
}

void Jumpzero::serialize()
{
    std::cout << "Jumpzero" << std::endl;
}

Jumpnzero::Jumpnzero(std::string label)
{
    opcode = OP_JUMPNZERO;
    label = label;
}

void Jumpnzero::serialize()
{
    std::cout << "Jumpnzero" << std::endl;
}

Gosub::Gosub(std::string label)
{
    opcode = OP_ENTER_SUBROUTINE;
    label = label;
}

void Gosub::serialize()
{
    std::cout << "Gosub" << std::endl;
}

Return::Return()
{
    opcode = OP_RETURN;
}

void Return::serialize()
{
    std::cout << "Return" << std::endl;
}

Pushscal::Pushscal(std::string var)
{
    opcode = OP_PUSHSCALAR;
    var = var;
}

void Pushscal::serialize()
{
    std::cout << "Pushscal" << std::endl;
}

Pusharr::Pusharr(std::string var, int index)
{
    opcode = OP_PUSHARRAY;
    var = var;
    index = index;
}

void Pusharr::serialize()
{
    std::cout << "Pusharr" << std::endl;
}

Pop::Pop()
{
    opcode = OP_POP;
}

void Pop::serialize()
{
    std::cout << "Pop" << std::endl;
}

Popscal::Popscal(std::string var)
{
    opcode = OP_POPSCALAR;
    var = var;
}

void Popscal::serialize()
{
    std::cout << "Popscal" << std::endl;
}

Poparr::Poparr(std::string var, int index)
{
    opcode = OP_POPARRAY;
    var = var;
    index = index;
}

void Poparr::serialize()
{
    std::cout << "Poparr" << std::endl;
}

Dup::Dup()
{
    opcode = OP_DUP;
}

void Dup::serialize()
{
    std::cout << "Dup" << std::endl;
}

Swap::Swap()
{
    opcode = OP_SWAP;
}

void Swap::serialize()
{
    std::cout << "Swap" << std::endl;
}

Add::Add()
{
    opcode = OP_ADD;
}

void Add::serialize()
{
    std::cout << "Add" << std::endl;
}

Negate::Negate()
{
    opcode = OP_NEGATE;
}

void Negate::serialize()
{
    std::cout << "Negate" << std::endl;
}

Mul::Mul()
{
    opcode = OP_MUL;
}

void Mul::serialize()
{
    std::cout << "Mul" << std::endl;
}

Div::Div()
{
    opcode = OP_DIV;
}

void Div::serialize()
{
    std::cout << "Div" << std::endl;
}

Printtos::Printtos()
{
    opcode = OP_PRINTTOS;
}

void Printtos::serialize()
{
    std::cout << "Printtos" << std::endl;
}

Prints::Prints(std::string str)
{
    opcode = OP_PRINTS;
    str = str;
}

void Prints::serialize()
{
    std::cout << "Prints" << std::endl;
}
