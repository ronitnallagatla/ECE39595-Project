#include <fstream>
#include <iostream>

#include "FileIO.h"

FileIO* FileIO::instance = 0;

FileIO::FileIO() { }

FileIO* FileIO::getInstance()
{
    if (instance == nullptr) {
        instance = new FileIO();
    }
    return instance;
}

void FileIO::openInputFile(std::string fileName)
{
    input.open(fileName);
}

void FileIO::openOutputFile(std::string fileName)
{
    output.open(fileName);
}

std::string FileIO::readLine()
{
    std::string line;
    std::getline(input, line);
    return line;
}

void FileIO::writeLine(std::string line)
{
    output << line << std::endl;
}

void FileIO::closeInputFile()
{
    input.close();
}

void FileIO::closeOutputFile()
{
    output.close();
}
