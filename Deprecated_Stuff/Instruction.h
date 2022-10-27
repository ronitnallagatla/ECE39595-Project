#ifndef INSTR_H
#define INSTR_H

#include <string>

class Statement {
    public:
        Statement ();
};

class Instruction : public Statement {
    public:
        Instruction ();
        Instruction (int _opcode, int _op1, int _op2, int _jump);
        void setOpcode(int _opcode);
        void setOp1(int _op1);
        void setOp2(int _op2);
        void setJump(int _jump);
        void print_instruction();
        int getOpcode() const;
        int getOp1() const;
        int getOp2() const;
        int getJump() const;
    private:
        int op;
        int op1;
        int op2;
        int jumpaddr;;
};

#endif