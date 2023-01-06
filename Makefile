CXX		:= clang++
OUTPUT	:= sfmlgame

SFML_DIR := /opt/homebrew/Cellar/sfml/2.5.1_2/

#Compiler & Linker flags
CXX_FLAGS := -O3 -std=c++17
INCLUDES := -I./src -I$(SFML_DIR)/include
LDFLAGS := -O3 -lsfml-graphic -lsfml-window -lsfml-system -lsfml-audio -L$(SFML_DIR)/lib

#source files
SRC_FILES := $(wildcard src/*.cpp)
OBJ_FILES := $(SRC_FILES:.cpp=.o)

# all of these targets with make
all:$(OUTPUT)

#define main executable requirements / command
$(OUTPUT): $(OBJ_FILES) Makefile
	$(CXX) $(OBJ_FILES) $(LDFLAGS) -o ./bin/$@

# specify creation of obj files
.cpp.o:
	$(CXX) -c $(CXX_FLAGS) $(INCLUDES) $< -o $@

# make clean command
clean:
	rm -f $(OBJ_SFMLGAME) ./bin/sfmlgame

# make run command
run: $(OUTPUT)
	cd bin && ./sfmlgame && cd ../
