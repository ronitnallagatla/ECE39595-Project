#include "TableEntry.h"

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