#ifndef TOKEN_H_
#define TOKEN_H_

#include <string>

class Token {
private:
    int i = 0;
    std::string inst;
    std::string op1;
    std::string op2;

public:
    // Token(std::string inst, std::string op1, std::string op2, std::string op3, std::string op4, std::string op5, std::string op6, std::string op7);
    Token(std::string line);
    void tokenize(std::string line);
    void tokenize();
    void printTokens() const;
    void setInstruction(std::string ins);
    void setOp(char* s);
    std::string getInst();
    std::string getOp1();
    std::string getOp2();
};