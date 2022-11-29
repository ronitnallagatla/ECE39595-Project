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

    if (!fptr.is_open()) {
        std::cout << "Error: Could not open file" << std::endl;
        return EXIT_FAILURE;
    }

    std::string instrline;

    InstructionMemory* instrMem = InstructionMemory::getInstance();
    DataMemory* dataMem = DataMemory::getInstance();
    RuntimeStack* runtimeStack = RuntimeStack::getInstance();
    StringBuffer* stringBuffer = StringBuffer::getInstance();

    int start_scope_size = 0;

    while (getline(fptr, instrline)) {
        Token instr(instrline);
        instr.tokenize();
        if (instr.inst == "Start") {
            start_scope_size = stoi(instr.op1);
            dataMem->extend(start_scope_size);
            break;
        }
        stringBuffer->add(instrline);
    }

    while (getline(fptr, instrline)) {
        operate(instrline);
    }

    int i = 0;

    instrMem->setPC(-1);

    while (1) {
        Instruction* ins = instrMem->getInstruction();
        ins->execute_instruction();
        i++;
    }

    return EXIT_SUCCESS;
}

void operate(std::string instr)
{
    Token t = Token(instr);
    StringBuffer* str_buff = StringBuffer::getInstance();
    InstructionMemory* instr_mem = InstructionMemory::getInstance();
    RuntimeStack* runtime_stack = RuntimeStack::getInstance();
    Instruction* ins = nullptr;
    t.tokenize();

    if (t.inst == "Add") {
        ins = new add();
    }

    else if (t.inst == "Mul") {
        ins = new mul();
    }

    else if (t.inst == "Div") {
        ins = new Div();
    }

    else if (t.inst == "Negate") {
        ins = new Negate();
    }

    else if (t.inst == "Swap") {
        ins = new Swap();
    }

    else if (t.inst == "Dup") {
        ins = new dup();
    }

    else if (t.inst == "Pop") {
        ins = new pop();
    }

    else if (t.inst == "Prints") {
        ins = new prints(stoi(t.op1));
    }

    else if (t.inst == "PrintTOS") {
        ins = new printtos();
    }

    else if (t.inst == "PushI") {
        ins = new pushi(stoi(t.op1));
    }

    else if (t.inst == "Exit") {
        ins = new Exit();
    }

    else if (t.inst == "JumpZero") {
        ins = new jumpzero(stoi(t.op1));
    }

    else if (t.inst == "JumpNZero") {
        ins = new jumpnzero(stoi(t.op1));
    }

    else if (t.inst == "Jump") {
        ins = new jump(stoi(t.op1));
    }

    else if (t.inst == "GoSub") {
        ins = new gosub(stoi(t.op1));
    }

    else if (t.inst == "Return") {
        ins = new Return();
    }

    else if (t.inst == "GoSubLabel") {
        int num_vars_in_new_scope = stoi(t.op1);
        // Allocate space for these variables in the data memory
        // Will be done in Gosublabel::execute_instruction()
        ins = new gosublabel(num_vars_in_new_scope);
    }

    else if (t.inst == "PopArray") {

        ins = new poparr(stoi(t.op1));

    }

    else if (t.inst == "PushScalar") {
        // The value at the location in data memory given by opnd is pushed onto the runtime stack.
        // This should be the location of a scalar variable.

        ins = new pushscal(stoi(t.op1));

    }

    else if (t.inst == "PushArray") {

        ins = new pusharr(stoi(t.op1));
    }

    else if (t.inst == "PopScalar") {

        // The value at the top of the runtime stack is removed and stored into the data memory at location opnd.

        ins = new popscal(stoi(t.op1));
    }

    else {
        std::cout << "Error: Invalid instruction - " << t.inst << std::endl;
    }

    if (ins != nullptr) {
        instr_mem->addInstruction(ins);
    } else {
        std::cout << "\nError: Invalid instruction -> " << t.inst << std::endl;
    }
}