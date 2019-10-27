// LZ78.hpp
#ifndef LZ78_HPP
#define LZ78_HPP

#include <string>
#include <vector>
#include <map>

using codebook_type = std::map<std::vector<char>, std::pair<std::vector<char>, char> >;

namespace LZ {
    class LZ78 {
        // Class attributes
        const std::string file_path;
        std::vector<unsigned char> buffer;
        codebook_type codebook;

        public:
            LZ78(const std::string file_path);
            void compact(const std::string out_file);
            void descompact(codebook_type codebook, const std::string file);

        private:
            codebook_type make_codebook(std::vector<unsigned char> buffer);
            std::string printVector(std::vector<char> v);


    };
}

#endif /* LZ78_HPP */
