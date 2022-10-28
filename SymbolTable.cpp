#include "SymbolTable.h"

SymbolTable* SymbolTable::instance = nullptr;

SymbolTable::SymbolTable()
{
    size = -1;
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

void SymbolTable::addLabel(std::string key, int loc)
{
    if (getLabel(key).getLoc() == -1) {
        map[key] = TableEntry(loc, 0);
    }
    else {
        std::cout << "Error: Label " << key << " already exists" << std::endl;
        exit(EXIT_FAILURE);
    }
}

void SymbolTable::addVar(std::string key, int len)
{
    std::cout << "Adding variable " << key << " with at Loc " << getEntry(key).getLoc() << std::endl;
    if (getEntry(key).getLoc() == -1) {
        addEntry(key, TableEntry(getLoc(), len));
        size += len;
    }

    else {
        std::cout << "Error: Variable " << key << " already exists" << std::endl;
        exit(EXIT_FAILURE);
    }
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

TableEntry SymbolTable::getLabel(std::string key)
{    
    std::map<std::string, TableEntry>::iterator it = map.find(key);
        if (it != map.end()) {
            return it->second;
        }
    return TableEntry(-1, -1);
}

int SymbolTable::getLoc()
{
    return size;
}

void SymbolTable::setScope(int scope)
{
    this->scope = scope;
}

int SymbolTable::getNumVar(int scope)
{
    int numVar = 0;
    std::map<std::string, TableEntry>::iterator it;
    for (it = map.begin(); it != map.end(); it++) {
        if (it->second.getLen() > 0) {
            numVar += it->second.getLen();
        }
    }

    if (scope == 0) {
        return numVar;
    }

    for (it = subMap.begin(); it != subMap.end(); it++) {
        if (it->second.getLen() > 0) {
            numVar += it->second.getLen();
        }
    }
    return numVar;
}

