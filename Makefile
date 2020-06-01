SRC_DIR = ./src
BLD_DIR = ./bin
INC_DIR = ./include

CPP = g++
CPP_FLAGS = -std=c++11
INC_FLAGS = -I $(INC_DIR)
SRC_FLAGS = $(wildcard $(SRC_DIR)/*.cpp)

default: clean dir $(BLD_DIR)/main.o

dir:
	mkdir -p $(BLD_DIR)

$(BLD_DIR)/main.o: $(SRC_DIR)/main.cpp
	$(CPP) $(CPP_FLAGS) $(INC_FLAGS) $(SRC_FLAGS) -o $(BLD_DIR)/main.o

clean:
	rm -rf $(BLD_DIR)
