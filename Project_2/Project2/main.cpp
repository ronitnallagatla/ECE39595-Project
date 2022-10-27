#include <fstream>
#include <iostream>
#include <queue>

#include "InstructionBuffer.h"
#include "StringBuffer.h"
#include "SymbolTable.h"
#include "Token.h"
#include "opcodes.h"
#include "SymbolTable.h"
#include "StringBuffer.h"

Instruction* get_instruction(std::string instr);

int main(int argc, char* argv[])
{
    if (argc != 2) {
        std::cout << "Error: Invalid number of arguments" << std::endl;
        return EXIT_FAILURE;
    }

    std::string instr;
    std::ifstream fptr(argv[1]);
    std::queue<Instruction*> instr_queue;
    
    while (getline(fptr, instr)) {
        Instruction* instr_ptr = get_instruction(instr);
        instr_queue.push(instr_ptr);
    }    

    while (!instr_queue.empty()) {
        instr_queue.front()->serialize();
        instr_queue.pop();
    }

    fptr.close();
}

Instruction* get_instruction(std::string instr)
{
    SymbolTable* sym_table = SymbolTable::getInstance();
    Token t(instr);
    Instruction* ins = nullptr;
    ins->varCount = 0;

    SymbolTable* symbolTable = SymbolTable::getInstance();
    StringBuffer* stringBuffer = StringBuffer::getInstance();
    InstructionBuffer* instructionBuffer = InstructionBuffer::getInstance();

    t.tokenize();

    int loc;
    int len;

    if (t.inst == "declscal") {
        ins = new declscal();
        ins->label_for_symbol_table = t.op1;

        loc = symbolTable->getSize(0);
        len = 1;

        symbolTable->addEntry(t.op1, loc, len, 0);


        std::pair <int, int> p
    }

    else if (t.inst == "declarr") {
        ins = new declarr();
        ins->label_for_symbol_table = t.op1;
        ins->length = stoi(t.op2);

        loc = symbolTable->getSize(0);
        len = stoi(t.op2);

        symbolTable->addEntry(t.op1, loc, len, 0);

    }

    else if (t.inst == "label") {
        ins = new label();
        ins->label_for_symbol_table = t.op1;

        loc = ins->varCount;
        len = 0;

        symbolTable->addEntry(t.op1, loc, len, 1);
    }

    else if (t.inst == "gosublabel") {
        ins = new gosublabel();
        ins->label_for_symbol_table = t.op1;

        loc = ins->varCount;
        len = 0;

        symbolTable->addEntry(t.op1, loc, len, 0);
        symbolTable->addEntry(t.op1, loc, len, 1);

        instructionBuffer->add(ins);
    }

    else if (t.inst == "start") {
        ins = new start();

        instructionBuffer->add(ins);
        ins->varCount += 1;
    }

    else if (t.inst == "end") {
        ins = new end();

    }

    else if (t.inst == "exit") {
        ins = new Exit();

        instructionBuffer->add(ins);
        ins->varCount += 1;

    }

    else if (t.inst == "jump") {
        ins = new jump();
        ins->label_for_symbol_table = t.op1;

        instructionBuffer->add(ins);
        ins->varCount += 1;
    }

    else if (t.inst == "jumpzero") {
        ins = new jumpzero();
        ins->label_for_symbol_table = t.op1;

        instructionBuffer->add(ins);
        ins->varCount += 1;
    }

    else if (t.inst == "jumpnzero") {
        ins = new jumpnzero();
        ins->label_for_symbol_table = t.op1;

        instructionBuffer->add(ins);
        ins->varCount += 1;
    }

    else if (t.inst == "gosub") {
        ins = new gosub();
        ins->label_for_symbol_table = t.op1;

        instructionBuffer->add(ins);
        ins->varCount += 1;
    }

    else if (t.inst == "return") {
        ins = new Return();

    }

    else if (t.inst == "pushscal") {
        ins = new pushscal();
        ins->label_for_symbol_table = t.op1;

        std::pair<double, double> entry = symbolTable->getEntry(t.op1, 0);
        instructionBuffer->add(ins);
        ins->varCount += 1;

    }

    else if (t.inst == "pusharr") {
        ins = new pusharr();
        ins->label_for_symbol_table = t.op1;

        std::pair<double, double> entry = symbolTable->getEntry(t.op1, 0);
        instructionBuffer->add(ins);
        ins->varCount += 1;
    }

    else if (t.inst == "pushi") {
        ins = new pushi();
        ins->value = stoi(t.op1);

        instructionBuffer->add(ins);
        ins->varCount += 1;


        ins = new pushi(stoi(t.op1));
    }

    else if (t.inst == "pop") {
        ins = new pop();

        instructionBuffer->add(ins);
        ins->varCount += 1;
    }

    else if (t.inst == "popscal") {
        ins = new popscal();
        ins->label_for_symbol_table = t.op1;

        std::pair<double, double> entry = symbolTable->getEntry(t.op1, 0);

        instructionBuffer->add(ins);
        ins->varCount += 1;

    }

    else if (t.inst == "poparr") {
        ins = new poparr();
        ins->label_for_symbol_table = t.op1;

        std::pair<double, double> entry = symbolTable->getEntry(t.op1, 0);

        instructionBuffer->add(ins);
        ins->varCount += 1;

    }

    else if (t.inst == "dup") {
        ins = new dup();

        instructionBuffer->add(ins);
        ins->varCount += 1;
    }

    else if (t.inst == "swap") {
        ins = new swap();

        instructionBuffer->add(ins);
        ins->varCount += 1;
    }

    else if (t.inst == "add") {
        ins = new add();

        instructionBuffer->add(ins);
        ins->varCount += 1;
    }

    else if (t.inst == "negate") {
        ins = new negate();

        instructionBuffer->add(ins);
        ins->varCount += 1;
    }

    else if (t.inst == "mul") {
        ins = new mul();

        instructionBuffer->add(ins);
        ins->varCount += 1;
    }

    else if (t.inst == "div") {
        ins = new Div();

        instructionBuffer->add(ins);
        ins->varCount += 1;
    }

    else if (t.inst == "printtos") {
        ins = new printtos();

        instructionBuffer->add(ins);
        ins->varCount += 1;
    }

    else if (t.inst == "prints") {

        StringBuffer* stringBuffer = stringBuffer::getInstance();

        ins = new prints();

        instructionBuffer->add(ins);

        return ins;
    }