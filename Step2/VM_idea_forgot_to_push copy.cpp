#include <iostream>
#include <fstream>
#include <Token.h>

int main (int argc, char** argv) {
    std::cout << "Hello World!" << std::endl;
    return 0;
}

void operate (std::string instr) {
  Token t = Token(instr);

  //std::stack is an object available in the standard library
  Stack* stack = Stack::getInstance(); // Make stack singleton

  if (t.inst == "Add") {
    stack.push(stack.pop() + stack.pop()); // Implement Push/Pop functions for stack
  }

  if (t.inst == "Mul") {
    stack.push(stack.pop() * stack.pop());
  }

  if (t.inst == "Div") {
    stack.push(stack.pop() / stack.pop());
  }

  if (t.inst == "Negate") {
    stack.push(-stack.pop());
  }

  if (t.inst == "Swap") {
    int temp = stack.pop();
    stack.push(stack.pop());
    stack.push(temp);
  }

  if (t.inst == "Dup") {
    stack.push(stack.top());
  }

  if (t.inst == "Pop") {
    stack.pop();
  }

  if (t.inst == "PushScalar") {
    stack.push(t.op1);
  }

  if (t.inst == "PushArray") {
    stack.push(t.op1[t.op2]);
  }
}