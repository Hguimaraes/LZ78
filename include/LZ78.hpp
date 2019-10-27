// LZ78.hpp
#ifndef LZ78_HPP
#define LZ78_HPP

#include <string>
#include <vector>

namespace LZ {
    class LZ78 {
        // Class attributes
        const std::string file_path;
        std::vector<unsigned char> buffer;
        std::vector<unsigned char> codebook;

        public:
            LZ78(const std::string file_path);
            void compact(const std::string out_file);
            void descompact(std::vector<unsigned char> codebook, const std::string file);

        private:
            std::vector<unsigned char> make_codebook(std::vector<unsigned char> buffer);


    };
}

#endif /* LZ78_HPP */
