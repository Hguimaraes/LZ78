#include "LZ78.hpp"

#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <bitset>
#include <map>

using codebook_type = std::map<std::vector<char>, std::pair<std::vector<char>, char> >;

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

codebook_type LZ::LZ78::make_codebook(std::vector<unsigned char> buffer){
    // Counter to fill our dictionary
    std::vector<char> key;
    std::vector<char> ptr_prev_key;

    // Initialize the codebook
    codebook_type codebook;
    ptr_prev_key.push_back('0');

    for(auto it = buffer.cbegin() ; it != buffer.cend(); ++it){
        key.push_back(*it);

        if(codebook.find(key) == codebook.end()){
            codebook[key] = std::make_pair(ptr_prev_key, *it);
            key.clear();
        } else {
            ptr_prev_key = codebook[key].first;
            ptr_prev_key.push_back(codebook[key].second);
        }
    }
    
    // @DEBUG
    for(auto it = codebook.cbegin(); it != codebook.cend(); ++it){
        std::cout << printVector(it->first) << ": {" << printVector(it->second.first) <<", " << it->second.second <<"}" << std::endl;
    }

    return codebook;
}

std::string LZ::LZ78::printVector(std::vector<char> v){
	std::string s;
	std::for_each(v.begin(), v.end(), [&](const int &i){s += i;});
	return s;
}

void LZ::LZ78::descompact(codebook_type codebook, const std::string file){
    
}
