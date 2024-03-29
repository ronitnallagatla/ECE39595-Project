#ifndef SYMBOLTABLE_H_
#define SYMBOLTABLE_H_

#include "TableEntry.h"
#include <iostream>
#include <map>
#include <string>

class SymbolTable {
private:
    SymbolTable();
    static SymbolTable* instance;
    int size;
    int scope;
    int seen_end = 0;
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
    TableEntry getLabel(std::string key);
    int getLoc();
    void setScope(int scope);
    int getNumVar(int scope);
    int err_check = 1;

    void setEnd() { seen_end = 1; }
    int getEnd() { return seen_end; }
};

#endif /* SYMBOLTABLE_H_ */
