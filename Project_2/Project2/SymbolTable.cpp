
#include "SymbolTable.h"

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

void SymbolTable::addEntry(std::string key, double location, double len)
{
    map[key] = std::make_pair(location, len);
    size += len;
}

int SymbolTable::getSize()
{
    return size;
}

std::pair<double, double> SymbolTable::getEntry(std::string key)
{
    return map[key];
}