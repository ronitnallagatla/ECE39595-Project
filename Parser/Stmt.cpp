#include "opcodes.h"
#include <fstream>

void declscal::serialize (std::ofstream& outFile) { }
void declarr::serialize (std::ofstream& outFile) { }
void label::serialize (std::ofstream& outFile) { }
void End::serialize (std::ofstream& outFile) { }


void gosublabel::serialize(std::ofstream& outFile)
{
    outFile << "GoSubLabel " << label_for_symbol_table << std::endl;    
}

void pushi::serialize (std::ofstream& outFile)
{
    outFile << "PushI " << val << std::endl;
}

void start::serialize (std::ofstream& outFile)
{
    outFile << "Start " << symbolTable->getNumVar(0) << std::endl;
}

void Exit::serialize (std::ofstream& outFile)
{
    outFile << "Exit" << std::endl;
}

void jump::serialize (std::ofstream& outFile)
{
    outFile << "Jump " << (symbolTable->getLabel(label_for_symbol_table)).getLoc() << std::endl;
}

void jumpzero::serialize (std::ofstream& outFile)
{
    outFile << "Jumpzero " << label_for_symbol_table  << " " << (symbolTable->getLabel(label_for_symbol_table)).getLoc() << std::endl;
}

void jumpnzero::serialize (std::ofstream& outFile)
{
    outFile << "JumpNZero " << label_for_symbol_table << " " << (symbolTable->getLabel(label_for_symbol_table)).getLoc() << std::endl;
}

void gosub::serialize (std::ofstream& outFile)
{
    outFile << "GoSub " << label_for_symbol_table  << " " <<  (symbolTable->getLabel(label_for_symbol_table)).getLoc() << std::endl;
}

void Return::serialize (std::ofstream& outFile)
{
    outFile << "Return" << std::endl;
}

void pushscal::serialize (std::ofstream& outFile)
{
    outFile << "PushScalar " << index << std::endl;
}

void pusharr::serialize (std::ofstream& outFile)
{
    outFile << "PushArray " << index << std::endl;
}

void pop::serialize (std::ofstream& outFile)
{
    outFile << "Pop" << std::endl;
}

void popscal::serialize (std::ofstream& outFile)
{
    outFile << "PopScalar " << index << std::endl;
}

void poparr::serialize (std::ofstream& outFile)
{
    outFile << "PopArray " << index << std::endl;
}

void dup::serialize (std::ofstream& outFile)
{
    outFile << "Dup" << std::endl;
}

void Swap::serialize (std::ofstream& outFile)
{
    outFile << "Swap" << std::endl;
}

void add::serialize (std::ofstream& outFile)
{
    outFile << "Add" << std::endl;
}

void Negate::serialize (std::ofstream& outFile)
{
    outFile << "Negate" << std::endl;
}

void mul::serialize (std::ofstream& outFile)
{
    outFile << "Mul" << std::endl;
}

void Div::serialize (std::ofstream& outFile)
{
    outFile << "Div" << std::endl;
}

void printtos::serialize (std::ofstream& outFile)
{
    outFile << "PrintTOS" << std::endl;
}

void prints::serialize (std::ofstream& outFile)
{
    outFile << "Prints " << index_in_str_buff << std::endl;
}