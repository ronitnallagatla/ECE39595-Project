#ifndef REGEX_H_
#define REGEX_H_

#include <regex>
#include <string>

class Regex {
private:
    static Regex* instance;
    Regex();
    std::regex regex;

public:
    static Regex* getInstance();
    bool match(std::string str);
};

#endif /* REGEX_H_ */