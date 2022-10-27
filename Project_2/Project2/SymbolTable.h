#ifndef SYMBOLTABLE_H_
#define SYMBOLTABLE_H_

#include <string>
#include <iostream>
#include <map>
#include "TableEntry.h"

class SymbolTable {
private:
    SymbolTable();
    static SymbolTable* instance;
    int size;
    int scope;
    std::map<std::string, TableEntry> map;
    std::map<std::string, TableEntry> subMap;

public:
    static SymbolTable* getInstance();
    void addEntry(std::string key, TableEntry entry);
    void addLabel(std::string key, int loc);
    void addVar(std::string key, int len);
    void addSubEntry(std::string key, TableEntry entry);
    TableEntry getEntry(std::string key);
    TableEntry getSubEntry(std::string key);
    int getLoc();
    void setScope(int scope);
    int getNumVar();
};

#endif /* SYMBOLTABLE_H_ */
