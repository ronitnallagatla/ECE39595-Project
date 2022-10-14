#include <map>
#include <string>
#include <iostream>

#include "SymbolTable.h"

SymbolTable::SymbolTable()
{
    definedMap = new std::map<std::string, int>();
    idx = 0;
}

int SymbolTable::getData(std::string key)
{
    if (!mapDefined)
    {
        return -1;
    }

    for (auto const &e : definedMap)
    {
        if (e.first == key)
        {
            return e.second;
        }
    }
}