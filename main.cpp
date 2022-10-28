#include <fstream>
#include <iostream>
#include <queue>

#include "SymbolTable.h"
#include "Token.h"
#include "opcodes.h"

Instruction* get_instruction(std::string instr, std::vector <Instruction*>& instr_queue);

int main(int argc, char* argv[])
{
    if (argc != 2) {
        std::cout << "Error: Invalid number of arguments" << std::endl;
        return EXIT_FAILURE;
    }

    std::string instr;
    std::ifstream fptr(argv[1]);
    std::vector <Instruction*> instr_queue;

    while (getline(fptr, instr)) {
        Instruction* instr_ptr = get_instruction(instr, instr_queue);
        if (instr_ptr != nullptr) {
            instr_queue.push_back(instr_ptr);
        }
    }

    for (auto instr : instr_queue) {
        /*
        if instruction is label | jump | gosub | jumpzero | jumpnzero
        
        read the label
        
        if (instr->opcode == OP_ENTER_SUBROUTINE) {
            gosub* gosub_instr = dynamic_cast<gosub*>(instr);
            gosub_instr->get_label_loc(instr_queue);
        }
        else if (instr->opcode == OP_JUMPZERO) {
            jumpzero* jumpzero_instr = dynamic_cast<jumpzero*>(instr);
            jumpzero_instr->get_label_loc(instr_queue);
        }
        else if (instr->opcode == OP_JUMPNZERO) {
            jumpnzero* jumpnzero_instr = dynamic_cast<jumpnzero*>(instr);
            jumpnzero_instr->get_label_loc(instr_queue);
        }
        else if (instr->opcode == OP_JUMP) {
            jump* jump_instr = dynamic_cast<jump*>(instr);
            jump_instr->get_label_loc(instr_queue);
        }

        */
        instr->get_label_loc(instr_queue);
        

       // if ((instr->opcode == OP_JUMP) || (instr->opcode == OP_GOSUB) || (instr->opcode == OP_JUMPZERO) || (instr->opcode == OP_JUMPNZERO)) {
       //     instr->get_label_loc(instr_queue);
       // }

    }

    
    for (auto instr : instr_queue) {
        instr->serialize();
    }
    
    fptr.close();
}

Instruction* get_instruction(std::string instr, std::vector <Instruction*>& instr_queue)
{
    SymbolTable* symbolTable = SymbolTable::getInstance();
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

        //instr_queue.front();

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
        symbolTable->addVar(t.op1, 0);
    }

    else if (t.inst == "jumpzero") {
        ins = new jumpzero(t.op1);
        symbolTable->addVar(t.op1, 0);
    }

    else if (t.inst == "jumpnzero") {
        ins = new jumpnzero(t.op1);
        symbolTable->addVar(t.op1, 0);
    }

    else if (t.inst == "gosub") {
        ins = new gosub(t.op1);
        symbolTable->setScope(1);
        symbolTable->addVar(t.op1, 0);
    }

    else if (t.inst == "return") {
        ins = new Return();
        symbolTable->setScope (0);
    }

    else if (t.inst == "pushscal") {
        ins = new pushscal(t.op1, (symbolTable->getEntry(t.op1)).getLoc());
        symbolTable->addVar(t.op1, 1);
    }

    else if (t.inst == "pusharr") {
        ins = new pusharr(t.op1, (symbolTable->getEntry(t.op1)).getLoc());
        symbolTable->addVar(t.op1, 1);
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
        ins = new prints(t.op1);
    }

    return ins;
}