#include "StringBuffer.h"
#include <iostream>
#include <fstream>

StringBuffer* StringBuffer::instance = nullptr;

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

std::string StringBuffer::get(int i) {
    return buffer[i];
}

int StringBuffer::getSize() {
    return buffer.size();
}

void StringBuffer::serialize(std::ofstream& outFile)
{
    for (auto str : buffer) {
        outFile << str << std::endl;
    }
}