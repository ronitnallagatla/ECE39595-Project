#ifndef SYMBOLTABLE_H_
#define SYMBOLTABLE_H_

#include <map>
#include <string>

#include "TableEntry.h"

// class SymbolTable {
// private:
//     // static SymbolTable* instance;
//     // std::map<std::string, int> definedMap;
//     // std::map<std::pair<int, std::string>, TableEntry> definedMap;
//     std::map<int, TableEntry> definedMap;
//     int idx;
//     // SymbolTable();

// public:
//     SymbolTable();
//     // int getData(std::string key);
//     std::map<int, TableEntry> getDefinedMap();
//     std::pair<int, TableEntry> getEntry(int key);
//     TableEntry getEntry(std::string key);
//     // static SymbolTable* getInstance();
// };

class SymbolTable {
private:
    SymbolTable();
    static SymbolTable* instance;
    int size;
    int subSize;
    // int subIdx;
    std::map<std::string, std::pair<double, double>> map;
    std::map<std::string, std::pair<double, double>> subMap;

public:
    static SymbolTable* getInstance();
    // void addEntry(std::string key, double loc, double len);
    void addEntry(std::string key, double loc, double len, int where);
    void addSubEntry(std::string key, double loc, double len);
    // std::pair<double, double> getEntry(std::string key);
    std::pair<double, double> getEntry(std::string key, int where);
    std::pair<double, double> getSubEntry(std::string key);
    // int getSize();
    int getSize(int which);
    void setSubSize(int size);
    int getSubSize();
};
#endif /* SYMBOLTABLE_H_ */