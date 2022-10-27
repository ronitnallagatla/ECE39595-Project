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
    std::map<std::string, std::pair<double, double>> map;

public:
    SymbolTable* getInstance();
    void addEntry(std::string key, double loc, double len);
    int getSize();
    std::pair<double, double> getEntry(std::string key);
    
};

#endif /* SYMBOLTABLE_H_ */

