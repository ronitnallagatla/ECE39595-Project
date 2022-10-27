#include <regex>

#include "Regex.h"

Regex* Regex::instance = 0;

Regex::Regex() { }

Regex* Regex::getInstance()
{
    if (instance == nullptr) {
        instance = new Regex();
    }
    return instance;
}

bool Regex::match(std::string str)
{
    return std::regex_match(str, regex);
}