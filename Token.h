#ifndef TOKEN_H_
#define TOKEN_H_

#include <string>

class Token {
public:
    int i = 0;
    std::string inst;
    std::string op1;
    std::string op2;
    std::string op3;

    Token(std::string line);
    void tokenize(std::string line);
    void tokenize();
    void print_tokens() const;
    void setInstruction(std::string ins);
    void set_op(char* s);
};

#endif /* TOKEN_H_ */