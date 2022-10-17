#include "SymbolTable.h"

#include <iostream>
#include <map>
#include <string>

SymbolTable* SymbolTable::instance = 0;

SymbolTable::SymbolTable()
{
    idx = 0;
}

SymbolTable* SymbolTable::getInstance()
{
    if (instance == nullptr) {
        instance = new SymbolTable();
    }
    return instance;
}

int SymbolTable::getData(std::string key)
{
    if (definedMap.find(key) == definedMap.end()) {
        definedMap[key] = idx++;
    }
    return definedMap[key];
}
