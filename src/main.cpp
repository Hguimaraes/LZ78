#include <cstring>
#include <iostream>
#include <fstream>
//#include "LZ78.hpp"

inline bool file_exists (const std::string& name) {
    std::ifstream f(name.c_str());
    return f.good();
}

int main(int argc, char **argv){
    // Check if a parameter is passed through CLI
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " FILE_TO_COMPACT" << std::endl;
        return 1;
    }

    // Check if passed file exists
    if (!file_exists(argv[1])){
        std::cerr << "File not found: " << argv[1] << std::endl;
        return 1;
    }

    std::cout << argv[0] << " will compact the file: " << argv[1] << "!" << std::endl;
    return 0;
}
