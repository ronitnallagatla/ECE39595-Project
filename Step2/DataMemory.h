#ifndef DATAMEMORY_H_
#define DATAMEMORY_H_

#include <stack>
#include <vector>

class DataMemory {
private:
    DataMemory();
    static DataMemory* instance;
    std::vector<int> memory;
    std::stack<int> stack;

public:
    static DataMemory* getInstance();
    void setMemory(int loc, int val);
    int getMemory(int loc);
    int getSize();
    void extend(int size);
    void allocate(int size);
};

#endif /* DATAMEMORY_H_ */