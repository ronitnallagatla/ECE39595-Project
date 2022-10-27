#ifndef SYMBOLTABLE_H_
#define SYMBOLTABLE_H_

#include <map>
#include <string>

#include "TableEntry.h"

class SymbolTable {
private:
    SymbolTable();
    static SymbolTable* instance;
    int size;
    //std::map<std::string, std::pair<double, double>> map;
    //std::map<std::string, std::pair<double, double>> subMap;

public:
    SymbolTable* getInstance();
    // void addEntry(std::string key, double loc, double len);
    // void addSubEntry(std::string key, double loc, double len);
    // std::pair<double, double> getEntry(std::string key);
    // std::pair<double, double> getSubEntry(std::string key);
    // int getSize();
    // int getSubSize();
};
#endif /* SYMBOLTABLE_H_ */

