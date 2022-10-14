#ifndef SYMBOLTABLE_H_
#define SYMBOLTABLE_H_

#include <string>
#include <map>

class SymbolTable
{
private:
    std::map<std::string, int> definedMap;
    static int idx;
    static bool mapDefined;

    SymbolTable();

public:
    static int getData(std::string key);
};
#endif /* SYMBOLTABLE_H_ */