#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

#include "FileIO.h"
#include "InstructionBuffer.h"
#include "Parser.h"
#include "StringBuffer.h"
#include "SymbolTable.h"
#include "Token.h"

// #include "Instruction.h"

// using namespace std;

// int main () {
//   string instr = "";
//   ifstream fptr ("OutputAndTestCases/OutputAndTestCases/TestCases10_08_22/1PushI");
//   if (fptr.is_open())
//   {
//     queue <Instruction*> instr_queue;
//     std::string opcode, op1, op2, jumpaddr;
//     while ( getline (fptr, instr) )
//     {
//       tie (opcode, op1, op2, jumpaddr) = parse_text (instr);
//       instr_queue.push (new Instruction (opcode, op1, op2, jumpaddr));
//      }
//     fptr.close();
//   }

//   else cout << "Unable to open file";

//   return 0;
// }

// tuple <string, string, string, string> parse_text (string instr) {
//   string opcode, op1, op2, jumpaddr;
//   return make_tuple (opcode, op1, op2, jumpaddr);
// }

// int main(int argc, char* argv[])
// {
//     std::ifstream inFile(argv[1]);

//     if (!inFile.is_open()) {
//         std::cout << "Failed to open input file " << argv[1] << std::endl;
//         return -1;
//     }

//     std::string prefix = std::string(argv[1]);
//     std::string outFileName = prefix + ".out";

//     std::ofstream outFile(outFileName, std::ios::out | std::ios::binary);
// }

Parser::Parser()
{
    symbolTable = SymbolTable::getInstance();
    instructionBuffer = InstructionBuffer::getInstance();
    stringBuffer = StringBuffer::getInstance();
}

// void Parser::Parse(std::ifstream& inFile)
void Parser::Parse(std::ifstream& fptr)
{
    // go through file, get each line
    // tokenize each line (op, op1, op2, jumpaddr)
    // parse each token
    // add to instruction buffer
    // add to symbol table
    // add to string buffer
    std::string instr;

    while (getline(fptr, instr)) {
        // std::cout << instr << std::endl;
        Token t(instr);
        t.tokenize();
        t.printTokens();
    }

    int numInst = 0;

    std::string line;
}

void Parser::makeInstruction(std::string op)
{
    Stmt* stmt = nullptr;
    int val;

    if (op == "start") {
        stmt = new Start();
    }

    else if (op == "end") {
        stmt = new End();
    }

    else if (op == "exit") {
        stmt = new Exit();
    }

    else if (op == "pushi") {
        val = tokens->getVal();
        stmt = new Pushi();
    }

    else if (op == "add") {
        stmt = new Add();
    }

    else if (op == "printtos") {
    }

    // else if (op == "return") {
    //     stmt = new Return();
    // }
}
