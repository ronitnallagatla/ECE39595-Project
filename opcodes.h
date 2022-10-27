#ifndef OP_H_
#define OP_H_

#include <iostream>
#include <string>
#include "SymbolTable.h"
#include <vector>

class Instruction {
    public:
        int opcode;
        int value;
        int length;
        std::string instr;
        std::string label_for_symbol_table;
        SymbolTable* symbolTable = SymbolTable::getInstance();
        virtual void get_label_loc(std::vector <Instruction*>& instr_queue) = 0;
        virtual void serialize() = 0;
};

static const int NULL_OP = 0x00000000;

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
/*
When a scalar variable is declared a symbol table entry 
is defined, with the name of var being the key, and the 
data being a double with the memory location (which is the 
same as the instruction buffer location) holding the variable 
(current value of bufferIdx) and the length 
*/
    public:
        int opcode = NULL_OP;
        void serialize();
        void get_label_loc(std::vector <Instruction*>& instr_queue);
};

class declarr : public Instruction {
/*
Declare an array variable, where length is the length of the array.
When an array variable is declared a symbol table entry is defined, 
with the name of var being the key, and the data being a 
double (two-tuple) with the memory location (which is the same as 
the instruction buffer location) holding the variable
 (current value of bufferIdx) and the length being the length specified in
this declaration.
*/
    public:
        int opcode = NULL_OP;
        // std::string instr_text = "declarr";
        // std::string label_for_symbol_table; // Might change to pointer to symbol table
        int length;
        void serialize();
        void get_label_loc(std::vector <Instruction*>& instr_queue);
};


class label : public Instruction {
/*
The name of label being the key, and the data being the memory 
location where the label is (location of the next
statement in the instruction buffer).
*/
    public:
        int opcode = NULL_OP;
        std ::string label_name;
        void serialize();  
        void get_label_loc(std::vector <Instruction*>& instr_queue);
        label (std::string label_name) { this->label_name = label_name; }
};

class gosublabel : public Instruction {
    public:
    int opcode = OP_ENTER_SUBROUTINE;
    void serialize();
    void get_label_loc(std::vector <Instruction*>& instr_queue);
};

class start : public Instruction {
    public:
    int opcode = OP_START_PROGRAM;
    // std::string instr_text = "start";
    void serialize();
    void get_label_loc(std::vector <Instruction*>& instr_queue);

};

class End : public Instruction {
    public:
    int opcode = OP_RETURN;
    // std::string instr_text = "end";
    void serialize();
    void get_label_loc(std::vector <Instruction*>& instr_queue);
};

class Exit : public Instruction {
    public:
    int opcode = OP_EXIT_PROGRAM;
    // std::string instr_text = "exit";
    void serialize();
    void get_label_loc(std::vector <Instruction*>& instr_queue);
};

class jump : public Instruction {
    public:
    int opcode = OP_JUMP;
    void serialize();

    void get_label_loc(std::vector <Instruction*>& instr_queue);
    int label_loc;
};

class jumpzero : public Instruction {
    public:
    int opcode = OP_JUMPZERO;
    void serialize();
    void get_label_loc(std::vector <Instruction*>& instr_queue);
    int label_loc;

    jumpzero (std::string label) { label_for_symbol_table = label; }
};

class jumpnzero : public Instruction {
    public:
    int opcode = OP_JUMPNZERO;
    void serialize();

    void get_label_loc(std::vector <Instruction*>& instr_queue);
    int label_loc;

    jumpnzero (std::string label) { label_for_symbol_table = label; }
};

class gosub : public Instruction {
    public:
    int opcode = OP_GOSUB;
    void serialize();
    gosub (std::string label) { label_for_symbol_table = label; }
    
    void get_label_loc(std::vector <Instruction*>& instr_queue);
    int label_loc;
};

class Return : public Instruction {
    public:
    int opcode = OP_RETURN;
    // std::string instr_text = "return";
    void serialize();
    void get_label_loc(std::vector <Instruction*>& instr_queue);
};

class pushscal : public Instruction {
    public:
    int opcode = OP_PUSHSCALAR;
    // std::string instr_text = "pushscal";
    // std::string label_for_symbol_table;

    pushscal (std::string label) { label_for_symbol_table = label; }

    void serialize();
    void get_label_loc(std::vector <Instruction*>& instr_queue);
};

class pusharr : public Instruction {
    public:
    int opcode = OP_PUSHARRAY;
    // std::string instr_text = "pusharr";
    // Push array doesn't work
    void serialize();
    pusharr (std::string label) { label_for_symbol_table = label; }
    void get_label_loc(std::vector <Instruction*>& instr_queue);
};

class pushi : public Instruction {
    public:
    int opcode = OP_PUSHI;
    // std::string instr_text = "pushi";
    int val;
    void serialize();
    pushi (int val) { this->val = val;}
    void get_label_loc(std::vector <Instruction*>& instr_queue);
};

class pop : public Instruction {
    public:
    int opcode = OP_POP;
    // std::string instr_text = "pop";
    void serialize();
    void get_label_loc(std::vector <Instruction*>& instr_queue);
};

class popscal : public Instruction {
    public:
    int opcode = OP_POPSCALAR;
    // std::string instr_text = "popscalar";
    // std::string label_for_symbol_table;
    void serialize();
    void get_label_loc(std::vector <Instruction*>& instr_queue);
    popscal (std::string label) { label_for_symbol_table = label; }
};

class poparr : public Instruction {
    public:
    int opcode = OP_POPARRAY;
    // std::string instr_text = "poparr";
    // std::string label_for_symbol_table;
    // Pop array doesn't work
    void serialize();
    void get_label_loc(std::vector <Instruction*>& instr_queue);

    poparr (std::string label) { label_for_symbol_table = label; }
};


class dup : public Instruction {
    public:
    int opcode = OP_DUP;
    // std::string instr_text = "dup";
    void serialize();
    void get_label_loc(std::vector <Instruction*>& instr_queue);
};

class Swap : public Instruction {
    public:
    int opcode = OP_SWAP;
    // std::string instr_text = "swap";
    void serialize();
    void get_label_loc(std::vector <Instruction*>& instr_queue);
};

class add : public Instruction {
    public:
    int opcode = OP_ADD;
    // std::string instr_text = "add";
    void serialize();
    void get_label_loc(std::vector <Instruction*>& instr_queue);
};

class Negate : public Instruction {
    public:
    int opcode = OP_NEGATE;
    // std::string instr_text = "negate";
    void serialize();
    void get_label_loc(std::vector <Instruction*>& instr_queue);
};

class mul : public Instruction {
    public:
    int opcode = OP_MUL;
    // std::string instr_text = "mul";
    void serialize();
    void get_label_loc(std::vector <Instruction*>& instr_queue);
};

class Div : public Instruction {
    public:
    int opcode = OP_DIV;
    // std::string instr_text = "div";
    void serialize();
    void get_label_loc(std::vector <Instruction*>& instr_queue);
};

class printtos : public Instruction {
    public:
    int opcode = OP_PRINTTOS;
    // std::string instr_text = "printtos";
    void serialize();
    void get_label_loc(std::vector <Instruction*>& instr_queue);
};

class prints : public Instruction {
    public:
    int opcode = OP_PRINTS;
    // std::string instr_text = "prints";
    std::string print_string;
    void serialize();
    void get_label_loc(std::vector <Instruction*>& instr_queue);
    prints (std::string print_string) { this->print_string = print_string; }
};

#endif /* OP_H_ */