#ifndef OP_H_
#define OP_H_
#include <iostream>
#include <string>

class Instruction {
public:
    int opcode;
    int value;
    int length;
    int varCount;
    std::string instr;
    std::string label_for_symbol_table;
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
    /*
    When a scalar variable is declared a symbol table entry
    is defined, with the name of var being the key, and the
    data being a double with the memory location (which is the
    same as the instruction buffer location) holding the variable
    (current value of bufferIdx) and the length
    */
public:
    std::string instr_text = "declscal";
    std::string label_for_symbol_table; // Might change to pointer to symbol table
    void serialize();
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
    std::string instr_text = "declarr";
    std::string label_for_symbol_table; // Might change to pointer to symbol table
    int length;
    void serialize();
};

class label : public Instruction {
    /*
    The name of label being the key, and the data being the memory
    location where the label is (location of the next
    statement in the instruction buffer).
    */
public:
    std::string instr_text = "label";
    std::string label_for_symbol_table; // Might change to pointer to symbol table

    void serialize();
};

class gosublabel : public Instruction {
    public:
    int opcode = OP_ENTER_SUBROUTINE;
    std::string instr_text = "enter_subroutine";
    // Change to second level symbol table
    void serialize();
};

class start : public Instruction {
public:
    int opcode = OP_START_PROGRAM;
    std::string instr_text = "start";
    void serialize();

};

class end : public Instruction {
public:
    int opcode = OP_RETURN;
    std::string instr_text = "end";
    void serialize();
};

class Exit : public Instruction {
public:
    int opcode = OP_EXIT_PROGRAM;
    std::string instr_text = "exit";
    void serialize();
};

class jump : public Instruction {
public:
    int opcode = OP_JUMP;
    std::string instr_text = "jump";
    std::string label_for_symbol_table; // Might change to pointer to symbol table
    void serialize();
};

class jumpzero : public Instruction {
public:
    int opcode = OP_JUMPZERO;
    std::string instr_text = "jumpzero";
    std::string label_for_symbol_table; // Might change to pointer to symbol table
    void serialize();
};

class jumpnzero : public Instruction {
public:
    int opcode = OP_JUMPNZERO;
    std::string instr_text = "jumpnzero";
    std::string label_for_symbol_table; // Might change to pointer to symbol table
    void serialize();
};

class gosub : public Instruction {
public:
    int opcode = OP_GOSUB;
    std::string instr_text = "gosub";
    std::string label_for_symbol_table; // Might change to pointer to symbol table
    void serialize();
};

class Return : public Instruction {
public:
    int opcode = OP_RETURN;
    std::string instr_text = "return";
    void serialize();
};

class pushscal : public Instruction {
public:
    int opcode = OP_PUSHSCALAR;
    std::string instr_text = "pushscal";
    std::string label_for_symbol_table; // Might change to pointer to symbol table

    // Push Scalar Does not want
    std::string label_for_symbol_table;

    void serialize();
};

class pusharr : public Instruction {
public:
    int opcode = OP_PUSHARRAY;
    std::string instr_text = "pusharr";
    // Push array doesn't work
    void serialize();
};

class pushi : public Instruction {
public:
    int opcode = OP_PUSHI;
    std::string instr_text = "pushi";
    int val;
    void serialize();
    pushi (int val) { this->val = val;}
};

class pop : public Instruction {
public:
    int opcode = OP_POP;
    std::string instr_text = "pop";
    void serialize();
};

class popscal : public Instruction {
public:
    int opcode = OP_POPSCALAR;
    std::string instr_text = "popscalar";
    std::string label_for_symbol_table; // Might change to pointer to symbol table
    // Pop Scalar doesn't work
    void serialize();
};

class poparr : public Instruction {
public:
    int opcode = OP_POPARRAY;
    std::string instr_text = "poparr";
    std::string label_for_symbol_table;
    // Pop array doesn't work
    void serialize();
};

class dup : public Instruction {
public:
    int opcode = OP_DUP;
    std::string instr_text = "dup";
    void serialize();
};

class swap : public Instruction {
public:
    int opcode = OP_SWAP;
    std::string instr_text = "swap";
    void serialize();
};

class add : public Instruction {
public:
    int opcode = OP_ADD;
    std::string instr_text = "add";
    void serialize();
};

class negate : public Instruction {
public:
    int opcode = OP_NEGATE;
    std::string instr_text = "negate";
    void serialize();
};

class mul : public Instruction {
public:
    int opcode = OP_MUL;
    std::string instr_text = "mul";
    void serialize();
};

class Div : public Instruction {
public:
    int opcode = OP_DIV;
    std::string instr_text = "div";
    void serialize();
};

class printtos : public Instruction {
public:
    int opcode = OP_PRINTTOS;
    std::string instr_text = "printtos";

    // string buffer shit
    void serialize();
};

class prints : public Instruction {
public:
    int opcode = OP_PRINTS;
    std::string instr_text = "prints";
    void serialize();
};

// void Instruction::serialize() {
//     std::cout << instr_text << std::endl;
// }

#endif /* OP_H_ */