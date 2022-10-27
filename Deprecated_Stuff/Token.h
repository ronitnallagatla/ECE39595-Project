#ifndef TOKEN_H_
#define TOKEN_H_

#include <string>

class Token {
private:
    int i = 0;
    void set_op(char* s);

public:
    Token(std::string str);
    void print_tokens() const;

    void tokenize(std::string s);
    void tokenize();

    std::string op1 = "/0";
    std::string op2 = "/0";
    std::string op3 = "/0";
    std::string op4 = "/0";
    std::string op5 = "/0";
    std::string op6 = "/0";
    std::string op7 = "/0";
    std::string inst = "/0";

protected:
    void set_instruction(std::string ins);
};


#endif /* TOKEN_H_ */