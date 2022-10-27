#ifndef PARSER_H_
#define PARSER_H_

#include "InstructionBuffer.h"
#include "Stmt.h"
#include "StringBuffer.h"
#include "SymbolTable.h"
#include "Token.h"
#include <string>
#include <vector>

class Parser {
private:
    static Parser* instance;
    Parser();
    // Moved Parse to public. Also changed input arg
    //void Parse(std::ifstream& inFile);
    void makeInstruction(Token t);
    std::vector<std::string> tokens;
    SymbolTable* symbolTable;
    InstructionBuffer* instructionBuffer;
    StringBuffer* stringBuffer;

public:
    static Parser* getInstance();
    void parse(std::vector<std::string> tokens);
    void Parse(std::string inFile);
    void print();
};

#endif /* PARSER_H_ */