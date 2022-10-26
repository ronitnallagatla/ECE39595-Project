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

SymbolTable::SymbolTable()
{
    idx = 0;
}

std::map<int, TableEntry> SymbolTable::getDefinedMap()
{
    return definedMap;
}

std::pair<int, TableEntry> SymbolTable::getEntry(int key)
{
    return std::make_pair(key, definedMap[key]);
}

TableEntry SymbolTable::getEntry(std::string key)
{
    return definedMap[std::stoi(key)];
}
