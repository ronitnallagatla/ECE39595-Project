
#include "SymbolTable.h"

#include <iostream>
#include <map>
#include <string>

SymbolTable* SymbolTable::instance = nullptr;

SymbolTable::SymbolTable()
{
    size = 0;
}

SymbolTable* SymbolTable::getInstance()
{
    if (instance == nullptr) {
        instance = new SymbolTable();
    }
    return instance;
}

/*
void SymbolTable::addEntry(std::string key, double loc, double len)
{
    map[key] = std::make_pair(loc, len);
    size++;
}

void SymbolTable::addSubEntry(std::string key, double loc, double len)
{
    subMap[key] = std::make_pair(loc, len);
}

std::pair<double, double> SymbolTable::getEntry(std::string key)
{
    return map[key];
}

std::pair<double, double> SymbolTable::getSubEntry(std::string key)
{
    return subMap[key];
}

int SymbolTable::getSize()
{
    return size;
}

int SymbolTable::getSubSize()
{
    return subMap.size();
}

*/