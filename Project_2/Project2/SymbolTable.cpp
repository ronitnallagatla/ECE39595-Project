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

void SymbolTable::addEntry(std::string key, TableEntry entry)
{
    if (scope == 0) {
        map[key] = entry;
    } else {
        subMap[key] = entry;
    }
}

// void SymbolTable::addSubEntry(std::string key, TableEntry entry)
// {
//     subMap[key] = entry;
//     size++;
// }

void SymbolTable::addLabel(std::string key, int loc)
{
    addEntry(key, TableEntry(loc, 0));
}

void SymbolTable::addVar(std::string key, int len)
{
    addEntry(key, TableEntry(getLoc(), len));
    size += len;
}

TableEntry SymbolTable::getEntry(std::string key)
{
    if (scope == 0) {
        std::map<std::string, TableEntry>::iterator it = map.find(key);
        if (it != map.end()) {
            return it->second;
        }
    } else {
        std::map<std::string, TableEntry>::iterator it = subMap.find(key);
        if (it != subMap.end()) {
            return it->second;
        }
    }

    return TableEntry(-1, -1);
}

// TableEntry SymbolTable::getSubEntry(std::string key)
// {
//     std::map<std::string, TableEntry>::iterator it = subMap.find(key);
//     if (it != subMap.end()) {
//         return it->second;
//     }
//     return TableEntry(-1, -1);
// }

int SymbolTable::getLoc()
{
    return size;
}

void SymbolTable::setScope(int scope)
{
    this->scope = scope;
}

int SymbolTable::getNumVar()
{
    int numVar = 0;

    std::map<std::string, TableEntry>::iterator it;
    for (it = map.begin(); it != map.end(); it++) {
        if (it->second.getLen() > 0) {
            numVar++;
        }
    }

    for (it = subMap.begin(); it != subMap.end(); it++) {
        if (it->second.getLen() > 0) {
            numVar++;
        }
    }

    return numVar;
}
