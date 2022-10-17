#ifndef STRINGBUFFER_H_
#define STRINGBUFFER_H_

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
    void print();
};

#endif /* STRINGBUFFER_H_ */