#ifndef RETURNADDRSTACK_H_
#define RETURNADDRSTACK_H_

#include <stack>

class ReturnAddrStack {
private:
    ReturnAddrStack();
    static ReturnAddrStack* instance;
    std::stack<int> stack;

public:
    static ReturnAddrStack* getInstance();
    void push(int val);
    int pop();
    int top();
};

#endif /* RETURNADDRSTACK_H_ */