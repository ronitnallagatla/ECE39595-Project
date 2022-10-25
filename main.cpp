#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

#include "Instruction.h"
#include "Parser.h"
#include "opcodes.h"
#include "token.cpp"

// int main(int argc, char** argv)
// {
//     std::ifstream fptr(argv[1]);

//     if (!fptr.is_open()) {
//         std::cout << "Error opening file" << std::endl;
//         return EXIT_FAILURE;
//     }

//     std::string instr;
//     std::queue <Instruction> instr_queue;

//     while (getline(fptr, instr)) {
//         std::cout << instr << std::endl;
//         instr_queue.push (get_instruction (instr));
//     }

//     fptr.close();

//     return EXIT_SUCCESS;
// }

// Instruction get_instruction (std::string ins) {
//     Instruction instr;
//     Token t (ins);
//     t.tokenize();

//     if (t.op1 == "start") {
//         instr.setOpcode(OP_START_PROGRAM);

//     return instr;
// }

int main(int argc, char* argv[])
{
    /*  open input file
        if file opens successfully, send the file to parser func that begins parsing

        parser func will make new data structs */

    if (argc != 2) {
        std::cout << "Error: Invalid number of arguments" << std::endl;
        return EXIT_FAILURE;
    }

    std::ifstream inFile(argv[1]);

    if (!inFile.is_open()) {
        std::cout << "Failed to open input file " << argv[1] << std::endl;
        return EXIT_FAILURE;
    }

    Parser* parser = Parser::getInstance();

    parser->parse(inFile&);
}