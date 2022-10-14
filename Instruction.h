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
        Instruction (std::string _opcode, std::string _op1, std::string _op2, std::string _jump);
        void setOpcode(std::string _opcode);
        void setOp1(std::string _op1);
        void setOp2(std::string _op2);
        void setJump(std::string _jump);
        void print_instruction();
        std::string getOpcode();
        std::string getOp1();
        std::string getOp2();
        std::string getJump();
    private:
        std::string op;
        std::string op1;
        std::string op2;
        std::string jumpaddr;;
};

#endif