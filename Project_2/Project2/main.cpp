#include <fstream>
#include <iostream>
#include <queue>

#include "SymbolTable.h"
#include "Token.h"
#include "opcodes.h"

Instruction* get_instruction(std::string instr);

int main(int argc, char* argv[])
{
    if (argc != 2) {
        std::cout << "Error: Invalid number of arguments" << std::endl;
        return EXIT_FAILURE;
    }

    std::string instr;
    std::ifstream fptr(argv[1]);
    std::queue <Instruction*> instr_queue;

    while (getline(fptr, instr)) {
        Instruction* instr_ptr = get_instruction(instr);
        if (instr_ptr != nullptr) {
            instr_queue.push(instr_ptr);
        }
    }

    while (!instr_queue.empty()) {
        instr_queue.front()->serialize();
        instr_queue.pop();
    }

    fptr.close();
}

Instruction* get_instruction(std::string instr)
{
    SymbolTable* symbolTable = SymbolTable::getInstance();
    Token t(instr);
    Instruction* ins = nullptr;

    t.tokenize();

    if (t.inst == "declscal") {
        ins = new declscal();
        ins->label_for_symbol_table = t.op1;
        symbolTable->addVar(t.op1, 1);
    }

    else if (t.inst == "declarr") {
        ins = new declarr();
        ins->label_for_symbol_table = t.op1;
        ins->length = stoi(t.op2);
        symbolTable->addVar(t.op1, stoi(t.op2));
    }

    else if (t.inst == "label") {
        symbolTable->addLabel(t.op1, symbolTable->getLoc());
    }

    else if (t.inst == "gosublabel") {
        ins = new gosublabel();
        ins->label_for_symbol_table = t.op1;
        symbolTable->setScope(1);
        symbolTable->addLabel(t.op1, symbolTable->getLoc());
    }

    else if (t.inst == "start") {
        ins = new start();
    }

    else if (t.inst == "end") {
        ins = new End();
    }

    else if (t.inst == "exit") {
        ins = new Exit();
    }

    else if (t.inst == "jump") {
        ins = new jump();
        ins->label_for_symbol_table = t.op1;
    }

    else if (t.inst == "jumpzero") {
        ins = new jumpzero(t.op1);
    }

    else if (t.inst == "jumpnzero") {
        ins = new jumpnzero(t.op1);
    }

    else if (t.inst == "gosub") {
        ins = new gosub(t.op1);
    }

    else if (t.inst == "return") {
        ins = new Return();
    }

    else if (t.inst == "pushscal") {
        ins = new pushscal(t.op1);
    }

    else if (t.inst == "pusharr") {
        ins = new pusharr(t.op1);
    }

    else if (t.inst == "pushi") {
        ins = new pushi(stoi(t.op1));
    }

    else if (t.inst == "pop") {
        ins = new pop();
    }

    else if (t.inst == "popscal") {
        ins = new popscal(t.op1);
    }

    else if (t.inst == "poparr") {
        ins = new poparr(t.op1);
    }

    else if (t.inst == "dup") {
        ins = new dup();
    }

    else if (t.inst == "swap") {
        ins = new Swap();
    }

    else if (t.inst == "add") {
        ins = new add();
    }

    else if (t.inst == "negate") {
        ins = new Negate();
    }

    else if (t.inst == "mul") {
        ins = new mul();
    }

    else if (t.inst == "div") {
        ins = new Div();
    }

    else if (t.inst == "printtos") {
        ins = new printtos();
    }

    else if (t.inst == "prints") {
        ins = new prints(t.op1);
    }

    return ins;
}