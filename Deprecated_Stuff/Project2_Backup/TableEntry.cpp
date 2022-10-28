#include "TableEntry.h"

// TableEntry::TableEntry(int loc, int len)
// {
//     entry.first = loc;
//     entry.second = len;
// }

// std::pair<int, int> TableEntry::getEntry()
// {
//     return entry;
// }

// int TableEntry::getLoc()
// {
//     return entry.first;
// }

// int TableEntry::getLen()
// {
//     return entry.second;
// }

TableEntry::TableEntry(): loc(-1), len(-1)
{
}

TableEntry::TableEntry(int loc, int len): loc(loc), len(len)
{
}

int TableEntry::getLoc()
{
    return loc;
}

int TableEntry::getLen()
{
    return len;
}

std::pair<int, int> TableEntry::getEntry()
{
    return std::make_pair(loc, len);
}