#ifndef OP_H_
#define OP_H_
#include <iostream>
#include <string>
#include "SymbolTable.h"

class Instruction {
    public:
        int opcode;
        int value;
        int length;
        std::string instr;
        std::string label_for_symbol_table;
        SymbolTable* symbolTable = SymbolTable::getInstance();
        virtual void serialize() = 0;
};

static const int OP_JUMP = 0x00000010;
static const int OP_JUMPZERO = 0x00000011;
static const int OP_JUMPNZERO = 0x00000012;
static const int OP_GOSUB = 0x00000013;
static const int OP_RETURN = 0x00000014;
static const int OP_ENTER_SUBROUTINE = 0x00000015;
static const int OP_EXIT_SUBROUTINE = 0x00000016;
static const int OP_START_PROGRAM = 0x00000017;
static const int OP_EXIT_PROGRAM = 0x00000018;
static const int OP_PUSHSCALAR = 0x00000020;
static const int OP_PUSHARRAY = 0x00000021;
static const int OP_PUSHI = 0x00000022;
static const int OP_POPSCALAR = 0x00000030;
static const int OP_POPARRAY = 0x00000031;
static const int OP_POP = 0x00000032;
static const int OP_DUP = 0x00000040;
static const int OP_SWAP = 0x00000041;
static const int OP_ADD = 0x00000050;
static const int OP_NEGATE = 0x00000051;
static const int OP_MUL = 0x00000052;
static const int OP_DIV = 0x00000053;
static const int OP_PRINTS = 0x00000060;
static const int OP_PRINTTOS = 0x00000061;

class declscal : public Instruction {
    public:
        void serialize();
};

class declarr : public Instruction {
    public:
        int length;
        void serialize();
};

class label : public Instruction {
    public:
        void serialize();  
};

class gosublabel : public Instruction {
    public:
    int opcode = OP_ENTER_SUBROUTINE;
    void serialize();
};

class start : public Instruction {
    public:
    int opcode = OP_START_PROGRAM;
    int start_val;
    void serialize();
    void set_start (int val) { start_val = val; }
};

class End : public Instruction {
    public:
    int opcode = OP_RETURN;
    void serialize();
};

class Exit : public Instruction {
    public:
    int opcode = OP_EXIT_PROGRAM;
    void serialize();
};

class jump : public Instruction {
    public:
    int opcode = OP_JUMP;
    void serialize();
};

class jumpzero : public Instruction {
    public:
    int opcode = OP_JUMPZERO;
    void serialize();

    jumpzero (std::string label) { label_for_symbol_table = label; }
};

class jumpnzero : public Instruction {
    public:
    int opcode = OP_JUMPNZERO;
    void serialize();

    jumpnzero (std::string label) { label_for_symbol_table = label; }
};

class gosub : public Instruction {
    public:
    int opcode = OP_GOSUB;
    void serialize();
    gosub (std::string label) { label_for_symbol_table = label; }
};

class Return : public Instruction {
    public:
    int opcode = OP_RETURN;
    void serialize();
};

class pushscal : public Instruction {
    public:
    int opcode = OP_PUSHSCALAR;
    int index;
    pushscal (std::string label, int idx) { label_for_symbol_table = label; index = idx + 1; }
    void serialize();
};

class pusharr : public Instruction {
    public:
    int opcode = OP_PUSHARRAY;
    int index;
    void serialize();
    pusharr (std::string label, int idx) { label_for_symbol_table = label; index = idx + 1;}
};

class pushi : public Instruction {
    public:
    int opcode = OP_PUSHI;
    int val;
    void serialize();
    pushi (int val) { this->val = val;}
};

class pop : public Instruction {
    public:
    int opcode = OP_POP;
    void serialize();
};

class popscal : public Instruction {
    public:
    int opcode = OP_POPSCALAR;
    int index;
    void serialize();
    popscal (std::string label, int idx) { label_for_symbol_table = label; index = idx + 1;}
};

class poparr : public Instruction {
    public:
    int opcode = OP_POPARRAY;
    int index;
    void serialize();

    poparr (std::string label, int idx) { label_for_symbol_table = label; index = idx + 1;}
};


class dup : public Instruction {
    public:
    int opcode = OP_DUP;
    void serialize();
};

class Swap : public Instruction {
    public:
    int opcode = OP_SWAP;
    void serialize();
};

class add : public Instruction {
    public:
    int opcode = OP_ADD;
    void serialize();
};

class Negate : public Instruction {
    public:
    int opcode = OP_NEGATE;
    void serialize();
};

class mul : public Instruction {
    public:
    int opcode = OP_MUL;
    void serialize();
};

class Div : public Instruction {
    public:
    int opcode = OP_DIV;
    void serialize();
};

class printtos : public Instruction {
    public:
    int opcode = OP_PRINTTOS;
    void serialize();
};

class prints : public Instruction {
    public:
    int opcode = OP_PRINTS;
    std::string print_string;
    void serialize();
    prints (std::string print_string) { this->print_string = print_string; }
};

#endif /* OP_H_ */