#ifndef SYMBOLTABLE_H_
#define SYMBOLTABLE_H_

#include <map>
#include <string>

#include "TableEntry.h"

class SymbolTable {
private:
    static SymbolTable* instance;
    // std::map<std::string, int> definedMap;
    // std::map<std::pair<int, std::string>, TableEntry> definedMap;
    std::map<std::string, TableEntry> definedMap;
    std::map<std::string, TableEntry> subMap;
    int idx;
    SymbolTable();

public:
    // int getData(std::string key);
    // std::map<std::string, TableEntry> getDefinedMap();
    // std::pair<std::string, TableEntry> getEntry(int key);
    TableEntry getEntry(std::string key);
    TableEntry getSubEntry(std::string key);
    static SymbolTable* getInstance();
};

#endif /* SYMBOLTABLE_H_ */