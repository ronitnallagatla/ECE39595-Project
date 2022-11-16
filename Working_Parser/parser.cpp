#include <fstream>
#include <iostream>
#include <queue>

#include "StringBuffer.h"
#include "SymbolTable.h"
#include "Token.h"
#include "opcodes.h"

Instruction* get_instruction(std::string instr, std::vector<Instruction*>& instr_queue);

int main(int argc, char* argv[])
{
    if (argc != 2) {
        std::cout << "Error: Invalid number of arguments" << std::endl;
        return EXIT_FAILURE;
    }

    std::string instr;
    std::ifstream fptr(argv[1]);

    std::string prefix = std::string(argv[1]);
    std::string outFile = prefix + ".pout";
    std::ofstream out(outFile);

    std::vector<Instruction*> instr_queue;
    SymbolTable* symbolTable = SymbolTable::getInstance();
    StringBuffer* stringBuffer = StringBuffer::getInstance();

    while (getline(fptr, instr)) {
        if ((symbolTable->getEnd()) == 1) {
            out << "Error: Code after End" << std::endl;
            return EXIT_FAILURE;
        }

        Instruction* instr_ptr = get_instruction(instr, instr_queue);
        if (instr_ptr != nullptr) {
            instr_queue.push_back(instr_ptr);
        }
    }

    if (symbolTable->getEnd() == 0) {
        out << "Error: Missing END statement" << std::endl;
        return EXIT_FAILURE;
    }

    // Modified string buffer to work with new parser instructions
    stringBuffer->serialize(out);
    for (auto instr : instr_queue) {
        // 0 in serialize means text, 1 means binary
        instr->serialize(out); // Outputs text to .pout file
    }

    fptr.close();
}

Instruction* get_instruction(std::string instr, std::vector<Instruction*>& instr_queue)
{
    SymbolTable* symbolTable = SymbolTable::getInstance();
    StringBuffer* stringBuffer = StringBuffer::getInstance();

    int inst_buff_size = instr_queue.size();
    Token t(instr);
    Instruction* ins = nullptr;

    t.tokenize();

    if (t.inst == "declscal") {
        symbolTable->addVar(t.op1, 1);
    }

    else if (t.inst == "declarr") {
        symbolTable->addVar(t.op1, stoi(t.op2));
    }

    else if (t.inst == "label") {
        symbolTable->addLabel(t.op1, inst_buff_size);
    }

    else if (t.inst == "gosublabel") {
        ins = new gosublabel();
        ins->label_for_symbol_table = t.op1;
        symbolTable->addLabel(t.op1, inst_buff_size);
        symbolTable->setScope(1);
    }

    else if (t.inst == "start") {
        ins = new start();
    }

    else if (t.inst == "end") {
        symbolTable->setEnd();
    }

    else if (t.inst == "exit") {
        ins = new Exit();
    }

    else if (t.inst == "jump") {
        ins = new jump();
        ins->label_for_symbol_table = t.op1;
        symbolTable->addVar(t.op1, 0);
    }

    else if (t.inst == "jumpzero") {
        ins = new jumpzero(t.op1);
        symbolTable->err_check = 0;
        symbolTable->addVar(t.op1, 0);
    }

    else if (t.inst == "jumpnzero") {
        ins = new jumpnzero(t.op1);
        symbolTable->err_check = 0;
        symbolTable->addVar(t.op1, 0);
    }

    else if (t.inst == "gosub") {
        ins = new gosub(t.op1);
        symbolTable->setScope(1);
        symbolTable->err_check = 0;
        symbolTable->addVar(t.op1, 0);
    }

    else if (t.inst == "return") {
        ins = new Return();
        symbolTable->setScope(0);
    }

    else if (t.inst == "pushscal") {
        ins = new pushscal(t.op1, (symbolTable->getEntry(t.op1)).getLoc());
    }

    else if (t.inst == "pusharr") {
        ins = new pusharr(t.op1, (symbolTable->getEntry(t.op1)).getLoc());
    }

    else if (t.inst == "pushi") {
        ins = new pushi(stoi(t.op1));
    }

    else if (t.inst == "pop") {
        ins = new pop();
    }

    else if (t.inst == "popscal") {
        ins = new popscal(t.op1, (symbolTable->getEntry(t.op1)).getLoc());
    }

    else if (t.inst == "poparr") {
        ins = new poparr(t.op1, (symbolTable->getEntry(t.op1)).getLoc());
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
        ins = new prints(t.op1, stringBuffer->getSize());
        stringBuffer->add(t.op1);
    }

    return ins;
}