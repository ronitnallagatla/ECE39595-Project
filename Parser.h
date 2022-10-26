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
    Parser(SymbolTable* symbolTable, InstructionBuffer* instructionBuffer,
        StringBuffer* stringBuffer);
    // Moved Parse to public. Also changed input arg
    // void Parse(std::ifstream& inFile);
    std::vector<std::string> tokens;
    SymbolTable* symbolTable;
    InstructionBuffer* instructionBuffer;
    StringBuffer* stringBuffer;
    void Parse(std::string inFile);
    void makeInstruction(std::string inst, std::string op1, std::string op2);
    void makeInstruction(Token token);
    void print();

public:
    static Parser* getInstance();
    static Parser* getInstance(SymbolTable* symbolTable, InstructionBuffer* instructionBuffer,
        StringBuffer* stringBuffer);
    // void parse(std::vector<std::string> tokens);
    // // void Parse(std::string& inFile);
    // void Parse(std::string inFile);
    // void makeInstruction(Token t);
    // void print();
};

#endif /* PARSER_H_ */