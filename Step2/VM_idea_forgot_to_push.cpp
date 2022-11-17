#include <fstream>
#include <iostream>

#include "DataMemory.h"
#include "InstructionMemory.h"
#include "RuntimeStack.h"
#include "StringBuffer.h"
#include "Token.h"
#include "opcodes.h"

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

    stringBuffer->printDebug();

    return EXIT_SUCCESS;
}

void operate(std::string instr)
{
    Token t = Token(instr);

    // std::stack is an object available in the standard library
    //  Stack* stack = Stack::getInstance(); // Make stack singleton
    RuntimeStack* stack = RuntimeStack::getInstance();

    if (t.inst == "Add") {
        stack->push(stack->pop() + stack->pop()); // Implement Push/Pop functions for stack
    }

    if (t.inst == "Mul") {
        stack->push(stack->pop() * stack->pop());
    }

    if (t.inst == "Div") {
        stack->push(stack->pop() / stack->pop());
    }

    if (t.inst == "Negate") {
        stack->push(-stack->pop());
    }

    if (t.inst == "Swap") {
        int temp = stack->pop();
        stack->push(stack->pop());
        stack->push(temp);
    }

    if (t.inst == "Dup") {
        stack->push(stack->top());
    }

    if (t.inst == "Pop") {
        stack->pop();
    }

    // if (t.inst == "PushScalar") {
    //     stack->push(t.op1);
    // }

    // if (t.inst == "PushArray") {
    //     stack->push(t.op1[t.op2]);
    // }
}