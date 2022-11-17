#include "DataMemory.h"

DataMemory* DataMemory::instance = nullptr;

DataMemory::DataMemory() { }

DataMemory* DataMemory::getInstance()
{
    if (instance == nullptr) {
        instance = new DataMemory();
    }
    return instance;
}

int DataMemory::getMemory(int loc)
{
    return memory[loc];
}

void DataMemory::setMemory(int loc, int val)
{
    memory[loc] = val;
}

int DataMemory::getSize()
{
    return memory.size();
}

void DataMemory::extend(int size)
{
    memory.resize(size);
}