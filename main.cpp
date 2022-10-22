#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <queue>
#include <map>

#include "Instruction.h"
#include "token.cpp"
#include "opcodes.h"

int main(int argc, char** argv)
{
    std::ifstream fptr(argv[1]);

    if (!fptr.is_open()) {
        std::cout << "Error opening file" << std::endl;
        return EXIT_FAILURE;
    }

    std::string instr;
    std::queue <Instruction> instr_queue;

    while (getline(fptr, instr)) {
        std::cout << instr << std::endl;
        instr_queue.push (get_instruction (instr));
    }

    fptr.close();

    return EXIT_SUCCESS;
}


Instruction get_instruction (std::string ins) {
    Instruction instr;
    Token t (ins);
    t.tokenize();

    if (t.op1 == "start") {
        instr.setOpcode(OP_START_PROGRAM);
        


    return instr;
}