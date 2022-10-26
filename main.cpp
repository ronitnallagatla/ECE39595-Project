#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

#include "Instruction.h"
#include "Parser.h"
#include "Token.h"
#include "opcodes.h"

#include "InstructionBuffer.h"
#include "StringBuffer.h"
#include "SymbolTable.h"

/* COMMENT OUT TO GET WORKING TOKENIZER
int main(int argc, char* argv[])
{
    if (argc != 2) {
        std::cout << "Error: Invalid number of arguments" << std::endl;
        return EXIT_FAILURE;
    }

    std::string instr;
    std::ifstream fptr(argv[1]);

    while (getline(fptr, instr)) {
        Token t (instr);
        t.tokenize();
        t.print_tokens();
    }

    fptr.close();
}
*/

int main(int argc, char* argv[])
{
    /*  open input file
        if file opens successfully, send the file to parser func that begins parsing

        parser func will make new data structs */

    if (argc != 2) {
        std::cout << "Error: Invalid number of arguments" << std::endl;
        return EXIT_FAILURE;
    }

    // Moved file opening to parser.
    // Could not get it to work here.

    std::fstream inFile(argv[1]);

    if (!inFile.is_open()) {
        std::cout << "Failed to open input file " << argv[1] << std::endl;
        return EXIT_FAILURE;
    }

    // Parser* parser = Parser::getInstance();
    // // parser->Parse(inFile);
    // parser->Parse(argv[1]);

    SymbolTable* symbolTable = SymbolTable::getInstance();
    InstructionBuffer* instructionBuffer = InstructionBuffer::getInstance();
    StringBuffer* stringBuffer = StringBuffer::getInstance();

    Parser* parser = Parser::getInstance(symbolTable, instructionBuffer, stringBuffer);

    parser->Parse(argv[1]);

    // SymbolTable* symbolTable;
    // symbolTable = symbolTable->getInstance();

    // InstructionBuffer* instructionBuffer;
    // instructionBuffer = instructionBuffer->getInstance();

    // StringBuffer* stringBuffer;
    // stringBuffer = stringBuffer->getInstance();

    // Parser* parser;
    // parser = parser->getInstance(symbolTable, instructionBuffer, stringBuffer);

    // Parser* parser = Parser::getInstance(symbolTable, instructionBuffer, stringBuffer);
    // parser->Parse(argv[1]);
}