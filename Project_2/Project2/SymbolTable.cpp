#include "SymbolTable.h"

#include <iostream>
#include <map>
#include <string>

SymbolTable* SymbolTable::instance = nullptr;

SymbolTable::SymbolTable()
{
    size = 0;
    subSize = 0;
}

SymbolTable* SymbolTable::getInstance()
{
    if (instance == nullptr) {
        instance = new SymbolTable();
    }
    return instance;
}

// void SymbolTable::addEntry(std::string key, double loc, double len)
// {
//     map[key] = std::make_pair(loc, len);
//     size++;
// }

void SymbolTable::addEntry(std::string key, double loc, double len, int where)
{
    if (where == 0) {
        map[key] = std::make_pair(loc, len);
        size++;
    } else {
        subMap[key] = std::make_pair(loc, len);
        subSize++;
    }
}

// void SymbolTable::addSubEntry(std::string key, double loc, double len)
// {
//     subMap[key] = std::make_pair(loc, len);
// }

// std::pair<double, double> SymbolTable::getEntry(std::string key)
// {
//     return map[key];
// }

std::pair<double, double> SymbolTable::getEntry(std::string key, int where)
{
    if (where == 0) {
        return map[key];
    } else {
        return subMap[key];
    }
}

// std::pair<double, double> SymbolTable::getSubEntry(std::string key)
// {
//     return subMap[key];
// }

// int SymbolTable::getSize()
// {
//     return size;
// }

int SymbolTable::getSize(int which)
{
    if (which == 0) {
        return size;
    } else {
        return subSize;
    }
}

// int SymbolTable::getSubSize()
// {
//     return subMap.size();
// }
