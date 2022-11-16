#include "RuntimeStack.h"
#include <iostream>

RuntimeStack* RuntimeStack::instance = nullptr;

RuntimeStack::RuntimeStack() { }

RuntimeStack* RuntimeStack::getInstance()
{
    if (instance == nullptr) {
        instance = new RuntimeStack();
    }
    return instance;
}

void RuntimeStack::push(int val)
{
    stack.push(val);
}

int RuntimeStack::pop()
{
    int val = stack.top();
    stack.pop();
    return val;
}

int RuntimeStack::top()
{
    return stack.top();
}

int RuntimeStack::size()
{
    return stack.size();
}

void RuntimeStack::serialize()
{
    std::stack<int> temp = stack;
    while (!temp.empty()) {
        std::cout << temp.top() << std::endl;
        temp.pop();
    }
}