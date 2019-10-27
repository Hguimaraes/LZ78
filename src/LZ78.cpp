#include "LZ78.hpp"

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

LZ::LZ78::LZ78(const std::string file_path){
    // Read the binary file
    std::ifstream input(file_path, std::ios::binary);
    this->buffer = std::vector<unsigned char>(std::istreambuf_iterator<char>(input), {});

    // Start the process of make the codebook
    this->codebook = this->make_codebook(buffer);
}

void LZ::LZ78::compact(const std::string out_file){
    // Compress buffer and save the file + codebook
}

std::vector<unsigned char> LZ::LZ78::make_codebook(std::vector<unsigned char> buffer){
    std::vector<unsigned char> codebook;
    return codebook;
}

void LZ::LZ78::descompact(std::vector<unsigned char> codebook, const std::string file){
    
}
