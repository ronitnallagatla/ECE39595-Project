#ifndef FILEIO_H_
#define FILEIO_H_

#include <fstream>
#include <iostream>

class FileIO {
private:
    std::ifstream input;
    std::ofstream output;
    static FileIO* instance;
    FileIO();

public:
    static FileIO* getInstance();
    void openInputFile(std::string fileName);
    void openOutputFile(std::string fileName);
    std::string readLine();
    void writeLine(std::string line);
    void closeInputFile();
    void closeOutputFile();
};

#endif /* FILEIO_H_ */