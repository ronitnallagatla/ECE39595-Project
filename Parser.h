#ifndef PARSER_H_
#define PARSER_H_

#include "InstructionBuffer.h"
#include "Stmt.h"
#include "StringBuffer.h"
#include "SymbolTable.h"
#include <string>
#include <vector>

class Parser {
private:
    static Parser* instance;
    Parser();
    std::vector<std::string> tokens;
    SymbolTable* symbolTable;
    InstructionBuffer* instructionBuffer;
    StringBuffer* stringBuffer;

public:
    static Parser* getInstance();
    void parse(std::vector<std::string> tokens);
    void print();
};

#endif /* PARSER_H_ */