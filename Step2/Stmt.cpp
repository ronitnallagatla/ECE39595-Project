#include "opcodes.h"
#include <fstream>
#include <iostream>

#include "InstructionMemory.h"
#include "RuntimeStack.h"
#include "StringBuffer.h"



void poparr::execute_instruction () {}
void popscal::execute_instruction () {}

void Exit::execute_instruction () { 
    exit (0);
}


void start::execute_instruction () {}

void jump::execute_instruction () {
    InstructionMemory* instrMem = InstructionMemory::getInstance();
    instrMem->setPC(jump_val);
}

void jumpzero::execute_instruction () {
    RuntimeStack* st = RuntimeStack::getInstance();
    InstructionMemory* instrMem = InstructionMemory::getInstance();

    if (st->top() == 0) {
        instrMem->setPC(jump_pc);
    }
}

void jumpnzero::execute_instruction () {
    RuntimeStack* st = RuntimeStack::getInstance();
    InstructionMemory* instrMem = InstructionMemory::getInstance();

    if (st->top() != 0) {
        instrMem->setPC(jump_pc);
    }
}


void gosub::execute_instruction () {
    InstructionMemory* instrMem = InstructionMemory::getInstance();
    instrMem->setPC(gosub_jump_index);
}


void pushscal::execute_instruction () {
    RuntimeStack* st = RuntimeStack::getInstance();
}

void Return::execute_instruction () {
    InstructionMemory* instrMem = InstructionMemory::getInstance();
    instrMem->setPC(instrMem->return_index);
}



void pusharr ::execute_instruction () {
    RuntimeStack* st = RuntimeStack::getInstance();
}


void pushi::execute_instruction () {
    RuntimeStack* st = RuntimeStack::getInstance();
    st->push(val);
}


void pop::execute_instruction () {
    RuntimeStack* st = RuntimeStack::getInstance();
    st->pop();
}


void dup::execute_instruction () {
    RuntimeStack* st = RuntimeStack::getInstance();
    st->push(st->top());
}




void Swap::execute_instruction () {
    RuntimeStack* st = RuntimeStack::getInstance();
    int temp = st->pop();
    int temp2 = st->pop();
    st->push(temp);
    st->push(temp2);
};




void add::execute_instruction () {
    RuntimeStack* st = RuntimeStack::getInstance();
    st->push (st->pop() + st->pop());
}




void Negate::execute_instruction () {
    RuntimeStack* st = RuntimeStack::getInstance();
    st->push (st->pop() * -1);
}



void mul::execute_instruction () {
    RuntimeStack* st = RuntimeStack::getInstance();
    st->push (st->pop() * st->pop());
}




void Div::execute_instruction () {
    RuntimeStack* st = RuntimeStack::getInstance();
    st->push (st->pop() / st->pop());
}


void printtos::execute_instruction () {
    RuntimeStack* st = RuntimeStack::getInstance();
    std::cout << st->pop() << std::endl;
}



void prints::execute_instruction () {
    StringBuffer* sb = StringBuffer::getInstance();
    std::cout << sb->get(index_in_str_buff) << std::endl;
};

popscal::popscal (std::string label, int idx) {
    this->label_for_symbol_table = label;
    this->index = idx + 1;
}

poparr::poparr (std::string label, int idx) {
    this->label_for_symbol_table = label;
    this->index = idx + 1;
}

prints::prints(std::string p_str, int index) {
    this->print_string = p_str;
    this->index_in_str_buff = index;
}

prints::prints() {}

pushscal::pushscal(std::string label, int idx)
{
    label_for_symbol_table = label;
    index = idx + 1;
}


pusharr::pusharr(std::string label, int idx) {
    label_for_symbol_table = label;
    index = idx + 1;
}

jumpnzero::jumpnzero(int i) { jump_pc = i; }

pushi::pushi(int v) { this->val = v; }

gosub::gosub(int i) { gosub_jump_index = i; }