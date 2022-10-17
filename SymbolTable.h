#ifndef SYMBOLTABLE_H_
#define SYMBOLTABLE_H_

#include <map>
#include <string>

class SymbolTable {
private:
    static SymbolTable* instance;
    std::map<std::string, int> definedMap;
    int idx;
    SymbolTable();

public:
    int getData(std::string key);
    static SymbolTable* getInstance();
};

#endif;