#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

#include "InstructionBuffer.h"
#include "StringBuffer.h"
#include "SymbolTable.h"

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

int main(int argc, char* argv[])
{
}