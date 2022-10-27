#include "opcodes.h"

void declscal::serialize() { }
void declarr::serialize() { }
void label::serialize() { }
void End::serialize() { }

void label::get_label_loc (std::vector <Instruction*>& instr_queue) {}
void declarr::get_label_loc (std::vector <Instruction*>& instr_queue) {}
void declscal::get_label_loc (std::vector <Instruction*>& instr_queue) {}
void gosublabel::get_label_loc (std::vector <Instruction*>& instr_queue) {}
void start::get_label_loc (std::vector <Instruction*>& instr_queue) {}
void End::get_label_loc (std::vector <Instruction*>& instr_queue) {}
void Exit::get_label_loc (std::vector <Instruction*>& instr_queue) {}
void Return::get_label_loc (std::vector <Instruction*>& instr_queue) {}
void pushscal::get_label_loc (std::vector <Instruction*>& instr_queue) {}
void pusharr::get_label_loc (std::vector <Instruction*>& instr_queue) {}
void pushi::get_label_loc (std::vector <Instruction*>& instr_queue) {}
void pop::get_label_loc (std::vector <Instruction*>& instr_queue) {}
void popscal::get_label_loc (std::vector <Instruction*>& instr_queue) {}
void poparr::get_label_loc (std::vector <Instruction*>& instr_queue) {}
void dup::get_label_loc (std::vector <Instruction*>& instr_queue) {}
void Swap::get_label_loc (std::vector <Instruction*>& instr_queue) {}
void add::get_label_loc (std::vector <Instruction*>& instr_queue) {}
void Negate::get_label_loc (std::vector <Instruction*>& instr_queue) {}
void mul::get_label_loc (std::vector <Instruction*>& instr_queue) {}
void Div::get_label_loc (std::vector <Instruction*>& instr_queue) {}
void printtos::get_label_loc (std::vector <Instruction*>& instr_queue) {}
void prints::get_label_loc (std::vector <Instruction*>& instr_queue) {}


void jumpzero::get_label_loc (std::vector <Instruction*>& instr_queue) {
    int loc = 0;
    int found = 0;
    for (auto instr : instr_queue) {
        if (instr->opcode != NULL_OP) {
            loc++;
        }

        if (instr->label_for_symbol_table == label_for_symbol_table) {
            found = 1;
        }
    }

    std::cout << "DEBUG JumpZero " << label_for_symbol_table << " at location " << loc << std::endl;

    label_loc = (found) ? loc : -100;
}

void jumpnzero::get_label_loc (std::vector <Instruction*>& instr_queue) {
    int loc = 0;
    int found = 0;
    for (auto instr : instr_queue) {
        std::cout << instr->opcode << std::endl;
        if (instr->opcode != NULL_OP) {
            loc++;
        }

        if (instr->label_for_symbol_table == label_for_symbol_table) {
            found = 1;
            std::cout << "FOUND DEBUG" << std::endl;
            break;
        }
    }

    std::cout << "DEBUG JumpNZero " << label_for_symbol_table << " at location " << loc << std::endl;

    label_loc = (found) ? loc : -100;
}

void gosub::get_label_loc (std::vector <Instruction*>& instr_queue) {
    int loc = 0;
    int found = 0;
    for (auto instr : instr_queue) {
        if (instr->opcode != NULL_OP) {
            loc++;
        }

        if (instr->opcode == OP_ENTER_SUBROUTINE) {
            if (instr->label_for_symbol_table == label_for_symbol_table) {
                found = 1;
            }
        }
    }
    std::cout << "DEBUG GoSub " << label_for_symbol_table << " at location " << loc << std::endl;
    label_loc = (found) ? loc : -100;
}

void jump::get_label_loc (std::vector <Instruction*>& instr_queue) {
    int loc = 0;
    int found = 0;
    for (auto instr : instr_queue) {
        if (instr->opcode != NULL_OP) {
            loc++;
        }

        if (instr->label_for_symbol_table == label_for_symbol_table) {
            found = 1;
        }
    }

    std::cout << "DEBUG Jump " << label_for_symbol_table << " at location " << loc << std::endl;

    label_loc = (found) ? loc : -100;
}

void gosublabel::serialize()
{
    // std::cout << "GoSubLabel " << label_for_symbol_table << ", (" <<  (symbolTable->getEntry(label_for_symbol_table)).getLoc() << ")" << std::endl;
    std::cout << "GoSubLabel " << label_for_symbol_table << std::endl;
}

void pushi::serialize()
{
    std::cout << "PushI (" << val << ")" << std::endl;
}

void start::serialize()
{
    // std::cout << "Start " << symbolTable->getNumVar(1) << std::endl;
    std::cout << "Start " << symbolTable->getNumVar(0) << std::endl;
}

void Exit::serialize()
{
    std::cout << "Exit" << std::endl;
}

void jump::serialize()
{
    std::cout << "Jump, " << label_loc << std::endl;
}

void jumpzero::serialize()
{
    std::cout << "Jumpzero, " << label_for_symbol_table << ", (" << label_loc << ")" << std::endl;
}

void jumpnzero::serialize()
{
    std::cout << "JumpNZero, " << label_for_symbol_table << ", (" << label_loc << ")" << std::endl;
}

void gosub::serialize()
{
    // std::cout << "GoSub " << label_for_symbol_table << ", (" << (symbolTable->getEntry(label_for_symbol_table)).getLoc() << ")" << std::endl;
    std::cout << "GoSub " << label_for_symbol_table << " (" << label_loc << ")" << std::endl;
}

void Return::serialize()
{
    std::cout << "Return" << std::endl;
}

void pushscal::serialize()
{
    std::cout << "PushScalar " << label_for_symbol_table << ", (" << (symbolTable->getEntry(label_for_symbol_table)).getLoc() << ")" << std::endl;
}

void pusharr::serialize()
{
    std::cout << "PushArray " << label_for_symbol_table << ", (" << (symbolTable->getEntry(label_for_symbol_table)).getLoc() << ")" << std::endl;
}

void pop::serialize()
{
    std::cout << "Pop" << std::endl;
}

void popscal::serialize()
{
    std::cout << "PopScalar " << label_for_symbol_table << ", (" << (symbolTable->getEntry(label_for_symbol_table)).getLoc() << ")" << std::endl;
}

void poparr::serialize()
{
    std::cout << "PopArray " << label_for_symbol_table << ", (" << (symbolTable->getEntry(label_for_symbol_table)).getLoc() << ")" << std::endl;
}

void dup::serialize()
{
    std::cout << "Dup" << std::endl;
}

void Swap::serialize()
{
    std::cout << "Swap" << std::endl;
}

void add::serialize()
{
    std::cout << "Add" << std::endl;
}

void Negate::serialize()
{
    std::cout << "Negate" << std::endl;
}

void mul::serialize()
{
    std::cout << "Mul" << std::endl;
}

void Div::serialize()
{
    std::cout << "Div" << std::endl;
}

void printtos::serialize()
{
    std::cout << "PrintTOS" << std::endl;
}

void prints::serialize()
{
    std::cout << "Prints " << print_string << std::endl;
}