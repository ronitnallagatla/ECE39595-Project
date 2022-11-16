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

void DataMemory::store(int loc, int val)
{
    memory[loc] = val;
}

int DataMemory::load(int loc)
{
    return memory[loc];
}

int DataMemory::getSize()
{
    return memory.size();
}

void DataMemory::extend(int size)
{
    memory.resize(size);
}