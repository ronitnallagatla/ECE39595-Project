#include "opcodes.h"

void declscal::serialize() {}
void declarr::serialize() {}
void label::serialize() {}
void End::serialize() {}

void gosublabel::serialize()
{
    std::cout << "GoSubLabel " << label_for_symbol_table << ", (" <<  (symbolTable->getEntry(label_for_symbol_table)).getLoc() << ")" << std::endl;
}

void pushi::serialize()
{
    std::cout << "PushI (" << val << ")" << std::endl;
}

void start::serialize()
{
    std::cout << "Start " << symbolTable->getNumVar(1) << std::endl;
}

void Exit::serialize()
{
    std::cout << "Exit" << std::endl;
}

void jump::serialize()
{
    std::cout << "Jump, " << (symbolTable->getEntry(label_for_symbol_table)).getLoc() << std::endl;
}

void jumpzero::serialize()
{
    std::cout << "Jumpzero, " << label_for_symbol_table << ", (" <<  (symbolTable->getEntry(label_for_symbol_table)).getLoc() << ")" << std::endl;
}

void jumpnzero::serialize()
{
    std::cout << "JumpNZero, " << label_for_symbol_table << ", (" <<  (symbolTable->getEntry(label_for_symbol_table)).getLoc() << ")" << std::endl;
}

void gosub::serialize()
{
    std::cout << "GoSub " << label_for_symbol_table << ", (" <<  (symbolTable->getEntry(label_for_symbol_table)).getLoc() << ")" << std::endl;
}

void Return::serialize()
{
    std::cout << "Return" << std::endl;
}

void pushscal::serialize()
{
    std::cout << "PushScalar " << label_for_symbol_table << ", (" <<  (symbolTable->getEntry(label_for_symbol_table)).getLoc() << ")" << std::endl;
}

void pusharr::serialize()
{
    std::cout << "PushArray " << label_for_symbol_table << ", (" <<  (symbolTable->getEntry(label_for_symbol_table)).getLoc() << ")" << std::endl;
}

void pop::serialize()
{
    std::cout << "Pop" << std::endl;
}

void popscal::serialize()
{
    std::cout << "PopScalar " << label_for_symbol_table << ", (" <<  (symbolTable->getEntry(label_for_symbol_table)).getLoc() << ")" << std::endl;
}

void poparr::serialize()
{
    std::cout << "PopArray " << label_for_symbol_table << ", (" <<  (symbolTable->getEntry(label_for_symbol_table)).getLoc() << ")" << std::endl;
}

void dup::serialize()
{
    std::cout << "Dup" << std::endl;
}

void Swap::serialize()
{
    std::cout << "Swap" << std::endl;
}

void add::serialize()
{
    std::cout << "Add" << std::endl;
}

void Negate::serialize()
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
    std::cout << "Prints " << print_string << std::endl;
}