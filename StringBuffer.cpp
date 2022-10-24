#include "StringBuffer.h"
#include "FileIO.h"

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

// void StringBuffer::print()
// {
//     for (auto str : buffer) {
//         std::cout << str << std::endl;
//     }
// }

void StringBuffer::serialize(std::ofstream& outFile)
{
    int length = buffer.size();
    outFile.write((char*)&length, sizeof(int));
    for (int i = 0; i < length; i++) {
        int strLength = buffer[i].size();
        outFile.write((char*)(&strLength), sizeof(int));
        outFile.write(buffer[i].c_str(), strLength);
    }
}