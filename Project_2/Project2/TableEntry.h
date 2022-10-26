#ifndef TABLE_ENTRY_H_
#define TABLE_ENTRY_H_

#include <string>

// class TableEntry {
// private:
//     std::pair<double, double> entry;

// public:
//     TableEntry(double loc, double len);
//     double getLoc();
//     double getLen();
//     std::pair<double, double> getEntry();
// };

class TableEntry {
public:
    double loc;
    double len;
    TableEntry(double loc, double len);
};

#endif /* TABLE_ENTRY_H_ */
