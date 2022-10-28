#ifndef TABLE_ENTRY_H_
#define TABLE_ENTRY_H_

#include <string>

class TableEntry {
private:
    int loc;
    int len;

public:
    TableEntry();
    TableEntry(int loc, int len);
    int getLoc();
    int getLen();
    std::pair<int, int> getEntry();
};

#endif /* TABLE_ENTRY_H_ */
