#include "TableEntry.h"

#include <string>

TableEntry::TableEntry(double loc, double len)
{
    entry.first = loc;
    entry.second = len;
}

std::pair<double, double> TableEntry::getEntry()
{
    return entry;
}

double TableEntry::getLoc()
{
    return entry.first;
}

double TableEntry::getLen()
{
    return entry.second;
}
