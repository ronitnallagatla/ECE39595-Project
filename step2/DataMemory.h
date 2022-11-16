#ifndef DATAMEMORY_H_
#define DATAMEMORY_H_

#include <vector>

class DataMemory {
private:
    DataMemory();
    static DataMemory* instance;
    std::vector<int> memory;

public:
    static DataMemory* getInstance();
    void store(int loc, int val);
    int load(int loc);
    int getSize();
    void extend(int size);
};

#endif /* DATAMEMORY_H_ */