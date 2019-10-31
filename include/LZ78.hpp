// LZ78.hpp
#ifndef LZ78_HPP
#define LZ78_HPP

#include <string>
#include <vector>
#include <map>

using codebook_type = std::map<std::vector<unsigned char>, std::pair<int, char> >;

namespace LZ {
    class LZ78 {
        // Class attributes
        const std::string file_path;
        std::vector<unsigned char> buffer;
        codebook_type codebook;
        std::map<std::vector<unsigned char>, int> buffer_splited;

        public:
            LZ78(const std::string file_path);
            void compact(const std::string out_file);

        private:
            codebook_type make_codebook(std::vector<unsigned char> buffer);
            std::string printVector(std::vector<unsigned char> v);
            std::string toBinary(int n, int bit_size);


    };
}

#endif /* LZ78_HPP */
