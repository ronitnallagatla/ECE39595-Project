#ifndef RUNTIMESTACK_H_
#define RUNTIMESTACK_H_

#include <stack>
#include <string>

class RuntimeStack {
private:
    RuntimeStack();
    static RuntimeStack* instance;
    std::stack<int> stack;

public:
    static RuntimeStack* getInstance();
    void push(int val);
    int pop();
    int top();
    int size();
    void serialize();
};

#endif /* RUNTIMESTACK_H_ */