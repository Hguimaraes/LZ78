#include "LZ78.hpp"

#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>

using codebook_type = std::map<std::vector<unsigned char>, std::pair<int, char> >;

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
    // vector of chars (key) and parallel list to make map ordered
    std::vector<unsigned char> key;
    std::map<std::vector<unsigned char>, int> insert_list;

    // Counter to fill our parallel list and pointer to object
    int ptr_prev_key = 0, counter = 0;

    // Initialize the codebook
    codebook_type codebook;

    for(auto it = buffer.cbegin() ; it != buffer.cend(); ++it){
        key.push_back(*it);
        if(codebook.find(key) == codebook.end()){
            // Fill the parallel list with the insertion order
            insert_list[key] = counter;
            counter++;
            
            // Insert the key on codebook
            codebook[key] = std::make_pair(ptr_prev_key, *it);
            key.clear();
        } else {
            ptr_prev_key = insert_list[key] + 1;
        }
    }

    // Save insert list to speed up the encoding process
    this->buffer_splited = insert_list;
    
    // @DEBUG
    for(auto it = codebook.cbegin(); it != codebook.cend(); ++it){
        std::cout << printVector(it->first) << ": {" << it->second.first <<", " << it->second.second <<"}" << std::endl;
    }

    return codebook;
}

std::string LZ::LZ78::printVector(std::vector<unsigned char> v){
	std::string s;
	std::for_each(v.begin(), v.end(), [&](const int &i){s += i;});
	return s;
}

void LZ::LZ78::descompact(codebook_type codebook, const std::string file){
    
}
