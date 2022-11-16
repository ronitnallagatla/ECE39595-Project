#include <fstream>
#include <iostream>

int main(int argc, char* argv[])
{
    if (argc != 2) {
        std::cout << "Error: Invalid number of arguments" << std::endl;
        return EXIT_FAILURE;
    }

    std::ifstream fptr(argv[1]);

    /*
    - open the file for reading
    - read strings and add to string buffer
    - read instructions, create new instruction (derived from Stmt) and add to instruction memory
    - set pc to address of first instruction in instruction memory
    */

        return EXIT_SUCCESS;
}