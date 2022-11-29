#include "opcodes.h"
#include <fstream>
#include <iostream>

#include "DataMemory.h"
#include "InstructionMemory.h"
#include "ReturnAddrStack.h"
#include "RuntimeStack.h"
#include "StringBuffer.h"

void start::execute_instruction() { }

void poparr::execute_instruction() { }
// void popscal::execute_instruction() { }

// void pushscal::execute_instruction()
// {
//     RuntimeStack* st = RuntimeStack::getInstance();
// }

void pusharr ::execute_instruction()
{
    RuntimeStack* st = RuntimeStack::getInstance();
}

/////////////////////////////////////////// WORKING EXECUTE_INSTRUCTIONS  ///////////////////////////////////////////

void Exit::execute_instruction()
{
    exit(0);
}

void pushi::execute_instruction()
{
    RuntimeStack* st = RuntimeStack::getInstance();
    st->push(val);
}

void gosub::execute_instruction()
{
    InstructionMemory* instrMem = InstructionMemory::getInstance();
    ReturnAddrStack* returnStack = ReturnAddrStack::getInstance();

    returnStack->push(instrMem->getPC()); // Push the next instruction to the return stack
                                          // so that we can return to it after the subroutine
                                          // keeping in mind getPC() returns PC (no increment)

    instrMem->setPC(gosub_jump_index);
}

void Return::execute_instruction()
{
    InstructionMemory* instrMem = InstructionMemory::getInstance();
    ReturnAddrStack* ret_adr = ReturnAddrStack::getInstance();

    int ret_adr_val = ret_adr->pop();
    instrMem->setPC(ret_adr_val);
}

void pop::execute_instruction()
{
    RuntimeStack* st = RuntimeStack::getInstance();
    st->pop();
}

void pushscal::execute_instruction()
{
    RuntimeStack* st = RuntimeStack::getInstance();
    DataMemory* dataMem = DataMemory::getInstance();

    st->push(dataMem->getMemory(index));
}

void popscal::execute_instruction()
{
    RuntimeStack* st = RuntimeStack::getInstance();
    DataMemory* dataMem = DataMemory::getInstance();

    dataMem->setMemory(index, st->pop());
}

void dup::execute_instruction()
{
    RuntimeStack* st = RuntimeStack::getInstance();
    st->push(st->top());
}

void Swap::execute_instruction()
{
    RuntimeStack* st = RuntimeStack::getInstance();
    int temp = st->pop();
    int temp2 = st->pop();
    st->push(temp);
    st->push(temp2);
};

void add::execute_instruction()
{
    RuntimeStack* st = RuntimeStack::getInstance();
    st->push(st->pop() + st->pop());
}

void Negate::execute_instruction()
{
    RuntimeStack* st = RuntimeStack::getInstance();
    st->push(st->pop() * -1);
}

void mul::execute_instruction()
{
    RuntimeStack* st = RuntimeStack::getInstance();
    st->push(st->pop() * st->pop());
}

void Div::execute_instruction()
{
    RuntimeStack* st = RuntimeStack::getInstance();
    st->push(st->pop() / st->pop());
}

void printtos::execute_instruction()
{
    RuntimeStack* st = RuntimeStack::getInstance();
    std::cout << st->pop() << std::endl;
}

void prints::execute_instruction()
{
    StringBuffer* sb = StringBuffer::getInstance();
    std::cout << sb->get(index_in_str_buff) << std::endl;
};

void jump::execute_instruction()
{
    InstructionMemory* instrMem = InstructionMemory::getInstance();
    instrMem->setPC(jump_val);
}

void jumpzero::execute_instruction()
{
    RuntimeStack* st = RuntimeStack::getInstance();
    InstructionMemory* instrMem = InstructionMemory::getInstance();

    if (st->pop() == 0) {
        instrMem->setPC(jump_pc);
    }
}

void jumpnzero::execute_instruction()
{
    RuntimeStack* st = RuntimeStack::getInstance();
    InstructionMemory* instrMem = InstructionMemory::getInstance();

    if (st->pop() != 0) {
        instrMem->setPC(jump_pc);
    }
}

void gosublabel::execute_instruction()
{
    DataMemory* dm = DataMemory::getInstance();

    // ALOCATE MEMORY FOR THE SUBROUTINE

    int size_to_be_allocated = sub_scope_size;

    dm->extend(size_to_be_allocated);
}

////////////////////////////////////  WORKING  CONSTRUCTORS    ////////////////////////////////////

// Decrement by 2 because the PC will be incremented by 1 in the main loop
// and since Start is not actually in the instruction memory, what should be
// instruction 1 is actually instruction 0

jump::jump(int i) { jump_val = i - 2; }
jumpnzero::jumpnzero(int i) { jump_pc = i - 2; }
jumpzero::jumpzero(int i) { jump_pc = i - 2; }
gosub::gosub(int i) { gosub_jump_index = i - 2; }

gosublabel::gosublabel(int i) { sub_scope_size = i; }

pushi::pushi(int v) { this->val = v; }

prints::prints(int index)
{
    this->index_in_str_buff = index;
}

/////////////////////////////////////////// NOT WORKING CONSTRUCTORS  ///////////////////////////////////////////

// popscal::popscal(std::string label, int idx)
// {
//     this->index = idx + 1;
// }

popscal::popscal(int idx)
{
    this->index = idx;
}

poparr::poparr(std::string label, int idx)
{
    this->index = idx + 1;
}

// pushscal::pushscal(std::string label, int idx) {
//     index = idx + 1;
// }

pushscal::pushscal(int idx)
{
    this->index = idx;
}

pusharr::pusharr(std::string label, int idx)
{
    index = idx + 1;
}
