#include <fstream>
#include <iostream>

#include "DataMemory.h"
#include "InstructionMemory.h"
#include "RuntimeStack.h"
#include "StringBuffer.h"
#include "Token.h"
#include "opcodes.h"

void operate(std::string instr);

int main(int argc, char** argv)
{

    if (argc != 2) {
        std::cout << "Error: Invalid number of arguments" << std::endl;
        return EXIT_FAILURE;
    }

    std::ifstream fptr(argv[1]);
    std::string instrline;

    InstructionMemory* instrMem = InstructionMemory::getInstance();
    DataMemory* dataMem = DataMemory::getInstance();
    RuntimeStack* runtimeStack = RuntimeStack::getInstance();
    StringBuffer* stringBuffer = StringBuffer::getInstance();

    while (getline(fptr, instrline)) {
        Token instr(instrline);
        instr.tokenize();
        if (instr.inst == "Start") {
            break;
        }
        stringBuffer->add(instrline);
    }


    while (getline(fptr, instrline)) {
        operate(instrline);
    }

    
    int i = 0;

    for (i = 0; i < instrMem->getSize(); i++) {
        Instruction* ins = instrMem -> getInstruction (i);
        ins -> execute_instruction();
    }

    return EXIT_SUCCESS;
}

void operate(std::string instr)
{
    Token t = Token(instr);
    StringBuffer* str_buff = StringBuffer::getInstance();
    InstructionMemory* instr_mem = InstructionMemory::getInstance();
    Instruction* ins = nullptr;
    t.tokenize();

    if (t.inst == "Add") {
        ins = new add();
    }

    if (t.inst == "Mul") {
        ins = new mul();
    }

    if (t.inst == "Div") {
        ins = new Div();
    }

    if (t.inst == "Negate") {
        ins = new Negate();
    }

    if (t.inst == "Swap") {
        ins = new Swap();
    }

    if (t.inst == "Dup") {
        ins = new dup();
    }

    if (t.inst == "Pop") {
        ins = new pop();
    }

    if (t.inst == "Prints") {
        ins = new prints();
        ins -> index_in_str_buff = stoi(t.op1);
    }

    if (t.inst == "PrintTOS") {
        ins = new printtos();
    }

    if (t.inst == "PushI") {
        ins = new pushi(stoi(t.op1));
    }

    if (t.inst == "Exit") {
        ins = new Exit();
    }

    if (ins != nullptr) {
        instr_mem->addInstruction(ins);
    } else {
        std::cout << "\nError: Invalid instruction -> "  << t.inst << std::endl;
    }

}