#include "SymbolTable.h"

#include <iostream>
#include <map>
#include <string>

// SymbolTable* SymbolTable::instance = 0;

// SymbolTable::SymbolTable()
// {
//     idx = 0;
// }

// SymbolTable* SymbolTable::getInstance()
// {
//     if (instance == nullptr) {
//         instance = new SymbolTable();
//     }
//     return instance;
// }

// int SymbolTable::getData(std::string key)
// {
//     if (definedMap.find(key) == definedMap.end()) {
//         definedMap[key] = idx++;
//     }
//     return definedMap[key];
// }

// SymbolTable::SymbolTable()
// {
//     idx = 0;
// }

// std::map<int, TableEntry> SymbolTable::getDefinedMap()
// {
//     return definedMap;
// }

// std::pair<int, TableEntry> SymbolTable::getEntry(int key)
// {
//     return std::make_pair(key, definedMap[key]);
// }

// TableEntry SymbolTable::getEntry(std::string key)
// {
//     return definedMap[std::stoi(key)];
// }

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
