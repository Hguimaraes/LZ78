# Compiler
CXX=g++

# FLAGs
CXXFLAGS=-std=c++11 -Wall -Wextra -g -O3
INCLUDES = -I include/ -I /usr/local/include

# PATHs
SRC_PATH = ./src
BUILD_PATH = ./build
BIN_PATH = ./bin

# Retrieve all source codes path
all: lz78 main lz78_compact

lz78_compact: lz78 main
	$(CXX) $(CXXFLAGS) $(BUILD_PATH)/*.o -o $(BIN_PATH)/lz78_compact

main: $(SRC_PATH)/main.cpp
	$(CXX) $(CXXFLAGS) -c $(SRC_PATH)/main.cpp -o $(BUILD_PATH)/main.o

lz78: $(SRC_PATH)/LZ78.cpp
	$(CXX) $(CXXFLAGS) -c $(SRC_PATH)/LZ78.cpp $(INCLUDES) -o $(BUILD_PATH)/lz78.o

clean:
	rm -f $(BUILD_PATH)/*.*  $(BIN_PATH)/*.*
