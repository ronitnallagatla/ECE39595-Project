#ifndef TABLE_ENTRY_H_
#define TABLE_ENTRY_H_

#include <string>

class TableEntry {
private:
    // std::pair<int, int> entry;
    int loc;
    int len;

public:
    TableEntry();
    TableEntry(int loc, int len);
    int getLoc();
    int getLen();
    std::pair<int, int> getEntry();
};

// class TableEntry {
// public:
//     double loc;
//     double len;
//     TableEntry(double loc, double len);
// };

#endif /* TABLE_ENTRY_H_ */
