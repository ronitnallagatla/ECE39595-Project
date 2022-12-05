#include "DataMemory.h"
#include <iostream>

DataMemory* DataMemory::instance = nullptr;

DataMemory::DataMemory() { }

DataMemory* DataMemory::getInstance()
{
    if (instance == nullptr) {
        instance = new DataMemory();
        instance->init();
    }
    return instance;
}

void DataMemory::init()
{
    std::vector<int> memory;
    scope = 0;
    stack.push_back(memory);
}

int DataMemory::getMemory(int loc)
{
    return stack[scope][loc];
}

void DataMemory::setMemory(int loc, int val)
{
    stack[scope][loc] = val;
}

int DataMemory::getSize()
{
    return stack[scope].size();
}

void DataMemory::extend(int size)
{
    stack[scope].resize(size);
}

void DataMemory::add_scope()
{
    scope++;
    std::vector<int> memory;
    stack.push_back(memory);
}

void DataMemory::pop_scope()
{
    if (scope > 0) {
        stack.pop_back();
    }

    else {
        std::cerr << "Error: Cannot pop global scope" << std::endl;
    }

    scope--;
}