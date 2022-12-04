#ifndef DATAMEMORY_H_
#define DATAMEMORY_H_

#include <stack>
#include <vector>

class DataMemory {
private:
    DataMemory();
    void init();

    static DataMemory* instance;
    std::vector<std::vector<int>> stack;

public:
    int scope = 0;
    static DataMemory* getInstance();
    void setMemory(int loc, int val);
    int getMemory(int loc);
    int getSize();
    void extend(int size);
    void allocate(int size);
    void add_scope();
    void pop_scope();
};

#endif /* DATAMEMORY_H_ */