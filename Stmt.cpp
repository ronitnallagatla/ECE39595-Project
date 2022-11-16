#include "opcodes.h"
#include <fstream>

void declscal::serialize (std::ofstream& outFile, int bin) { }
void declarr::serialize (std::ofstream& outFile, int bin) { }
void label::serialize (std::ofstream& outFile, int bin) { }
void End::serialize (std::ofstream& outFile, int bin) { }


void gosublabel::serialize(std::ofstream& outFile, int bin)
// If bin == 1, Output binary file - I.e. Opcode plus some other shit that I'm not sure about (SEE VM ACTIONS IN PROJECT DOCUMENTATIOn)
{
    if (bin) {
        outFile << opcode << std::endl;
    } else {
        outFile << "GoSubLabel " << label_for_symbol_table << std::endl;
    }
    
}

void pushi::serialize (std::ofstream& outFile, int bin)
{
    if (bin) {
    // If bin == 1, Output binary file - I.e. Opcode plus some other shit that I'm not sure about (SEE VM ACTIONS IN PROJECT DOCUMENTATIOn)
        outFile << opcode << std::endl;
        outFile << value << std::endl;
    } else {
        outFile << "PushI (" << val << ")" << std::endl;
    }
}


//CHECK THE VM ACTIONS Document to make sure that the opcode is correct 
void start::serialize (std::ofstream& outFile, int bin)
{
    outFile << "Start " << symbolTable->getNumVar(0) << std::endl;
}

void Exit::serialize (std::ofstream& outFile, int bin)
{
    outFile << "Exit" << std::endl;
}

void jump::serialize (std::ofstream& outFile, int bin)
{
    outFile << "Jump, " << (symbolTable->getLabel(label_for_symbol_table)).getLoc() << std::endl;
}

void jumpzero::serialize (std::ofstream& outFile, int bin)
{
    outFile << "Jumpzero, " << label_for_symbol_table << ", (" << (symbolTable->getLabel(label_for_symbol_table)).getLoc() << ")" << std::endl;
}

void jumpnzero::serialize (std::ofstream& outFile, int bin)
{
    outFile << "JumpNZero, " << label_for_symbol_table << ", (" << (symbolTable->getLabel(label_for_symbol_table)).getLoc() << ")" << std::endl;
}

void gosub::serialize (std::ofstream& outFile, int bin)
{
    outFile << "GoSub " << label_for_symbol_table << ", (" << (symbolTable->getLabel(label_for_symbol_table)).getLoc() << ")" << std::endl;
}

void Return::serialize (std::ofstream& outFile, int bin)
{
    outFile << "Return" << std::endl;
}

void pushscal::serialize (std::ofstream& outFile, int bin)
{
    outFile << "PushScalar " << label_for_symbol_table << ", (" << index << ")" << std::endl;
}

void pusharr::serialize (std::ofstream& outFile, int bin)
{
    outFile << "PushArray " << label_for_symbol_table << ", (" << index << ")" << std::endl;
}

void pop::serialize (std::ofstream& outFile, int bin)
{
    outFile << "Pop" << std::endl;
}

void popscal::serialize (std::ofstream& outFile, int bin)
{
    outFile << "PopScalar " << label_for_symbol_table << ", (" << index << ")" << std::endl;
}

void poparr::serialize (std::ofstream& outFile, int bin)
{
    outFile << "PopArray " << label_for_symbol_table << ", (" << index << ")" << std::endl;
}

void dup::serialize (std::ofstream& outFile, int bin)
{
    outFile << "Dup" << std::endl;
}

void Swap::serialize (std::ofstream& outFile, int bin)
{
    outFile << "Swap" << std::endl;
}

void add::serialize (std::ofstream& outFile, int bin)
{
    outFile << "Add" << std::endl;
}

void Negate::serialize (std::ofstream& outFile, int bin)
{
    outFile << "Negate" << std::endl;
}

void mul::serialize (std::ofstream& outFile, int bin)
{
    outFile << "Mul" << std::endl;
}

void Div::serialize (std::ofstream& outFile, int bin)
{
    outFile << "Div" << std::endl;
}

void printtos::serialize (std::ofstream& outFile, int bin)
{
    outFile << "PrintTOS" << std::endl;
}

void prints::serialize (std::ofstream& outFile, int bin)
{
    outFile << "Prints " << index_in_str_buff << std::endl;
}