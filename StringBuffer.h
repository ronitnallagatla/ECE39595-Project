#ifndef STRINGBUFFER_H_
#define STRINGBUFFER_H_

#include <iostream>
#include <string>
#include <vector>

class StringBuffer {
private:
    static StringBuffer* instance;
    StringBuffer();
    std::vector<std::string> buffer;

public:
    static StringBuffer* getInstance();
    void add(std::string str);
    void serialize(std::ofstream& outFile);
    std::string get(int i);
};

#endif /* STRINGBUFFER_H_ */