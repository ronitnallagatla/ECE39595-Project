#ifndef OP_H_
#define OP_H_

#include <iostream>
#include <string>

class Instruction {
public:
    int opcode;
    std::string instr;
    virtual void execute_instruction() = 0;
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


class gosublabel : public Instruction {
public:
    int opcode = OP_ENTER_SUBROUTINE;
    int sub_scope_size;
    gosublabel(int i);
    void execute_instruction();
};


class start : public Instruction {
public:
    int opcode = OP_START_PROGRAM;
    int start_val;
    void execute_instruction();
};


class Exit : public Instruction {
public:
    std::string instr = "Exit";
    int opcode = OP_EXIT_PROGRAM;
    void execute_instruction();
};


class jump : public Instruction {
public:
    int opcode = OP_JUMP;
    int jump_val;
    std::string instr = "Jump " + std::to_string(jump_val);
    
    jump (int i);
    void execute_instruction();
};


class jumpzero : public Instruction {
public:
    int opcode = OP_JUMPZERO;
    int jump_pc;

    std::string instr = "JumpZero " + std::to_string(jump_pc);
    
    jumpzero(int i);
    void execute_instruction();
};

class jumpnzero : public Instruction {
public:
    int opcode = OP_JUMPNZERO;
    int jump_pc;

    std::string instr = "JumpNZero " + std::to_string(jump_pc);

    jumpnzero(int i);
    void execute_instruction();
};


class gosub : public Instruction {
public:
    int opcode = OP_GOSUB;
    int gosub_jump_index;

    std::string instr = "GoSub " + std::to_string(gosub_jump_index);

    gosub(int i);
    void execute_instruction();
};


class Return : public Instruction {
public:
    int opcode = OP_RETURN;

    std::string instr = "Return";
    void execute_instruction();
};


class pushscal : public Instruction {
public:
    int opcode = OP_PUSHSCALAR;
    int index;
    pushscal(std::string label, int idx);
    void execute_instruction();
};


class pusharr : public Instruction {
public:
    int opcode = OP_PUSHARRAY;
    int index;
    pusharr(std::string label, int idx);
    void execute_instruction();
};

class pushi : public Instruction {
public:
    int opcode = OP_PUSHI;
    int val;
    pushi(int v);
    void execute_instruction();
};


class pop : public Instruction {
public:
    int opcode = OP_POP;
    void execute_instruction();
};

class popscal : public Instruction {
public:
    int opcode = OP_POPSCALAR;
    int index;
    popscal(std::string label, int idx);
    void execute_instruction();
};


class poparr : public Instruction {
public:
    int opcode = OP_POPARRAY;
    int index;
    
        poparr(std::string label, int idx);
    void execute_instruction();
};

class dup : public Instruction {
public:
    int opcode = OP_DUP;
    void execute_instruction();
};


class Swap : public Instruction {
public:
    int opcode = OP_SWAP;
    void execute_instruction();
};


class add : public Instruction {
public:
    int opcode = OP_ADD;
    void execute_instruction();
};

class Negate : public Instruction {
public:
    int opcode = OP_NEGATE;
    void execute_instruction();
};


class mul : public Instruction {
public:
    int opcode = OP_MUL;
    void execute_instruction();
};


class Div : public Instruction {
public:
    int opcode = OP_DIV;
    void execute_instruction();
};

class printtos : public Instruction {
public:
    int opcode = OP_PRINTTOS;
    void execute_instruction();
};


class prints : public Instruction {
public:
    int opcode = OP_PRINTS;
    int index_in_str_buff;
    prints(int index);
    void execute_instruction();
};

#endif /* OP_H_ */