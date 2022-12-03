#include "ReturnAddrStack.h"

ReturnAddrStack* ReturnAddrStack::instance = nullptr;

ReturnAddrStack::ReturnAddrStack() { }

ReturnAddrStack* ReturnAddrStack::getInstance()
{
    if (instance == nullptr) {
        instance = new ReturnAddrStack();
    }
    return instance;
}

void ReturnAddrStack::push(int val)
{
    stack.push(val);
}

int ReturnAddrStack::pop()
{
    int val = stack.top();
    stack.pop();
    return val;
}

int ReturnAddrStack::top()
{
    return stack.top();
}