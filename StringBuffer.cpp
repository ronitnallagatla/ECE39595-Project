#include "StringBuffer.h"

#include <iostream>

StringBuffer* StringBuffer::instance = 0;

StringBuffer::StringBuffer() { }

StringBuffer* StringBuffer::getInstance()
{
    if (instance == nullptr) {
        instance = new StringBuffer();
    }
    return instance;
}

void StringBuffer::add(std::string str)
{
    buffer.push_back(str);
}

void StringBuffer::print()
{
    for (auto str : buffer) {
        std::cout << str << std::endl;
    }
}
