#ifndef TABLE_ENTRY_H_
#define TABLE_ENTRY_H_

#include <string>

class TableEntry {
private:
    std::pair<double, double> entry;

public:
    TableEntry(double loc, double len);
    double getLoc();
    double getLen();
    std::pair<double, double> getEntry();
};

#endif /* TABLE_ENTRY_H_ */
