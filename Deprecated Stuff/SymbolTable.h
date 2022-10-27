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
    std::map<int, TableEntry> definedMap;
    int idx;
    SymbolTable();

public:
    // int getData(std::string key);
    std::map<int, TableEntry> getDefinedMap();
    std::pair<int, TableEntry> getEntry(int key);
    TableEntry getEntry(std::string key);
    static SymbolTable* getInstance();
};

#endif /* SYMBOLTABLE_H_ */