# project configuration
CC       = g++
LD_FLAGS = 
CC_FLAGS = -Wall -Wno-deprecated-declarations -std=c++14 -Ofast -funroll-loops
EXEC     = main

# libs and headers subfolders lookup
INCLUDE = -I./
SRC     = $(wildcard ./*.cpp)
OBJ     = $(patsubst ./%.cpp, ./%.o, $(SRC))

# sourcefile subfolders lookup
VPATH = ./

all: $(EXEC)

# create binary
$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(LD_FLAGS)

# objects
main.o: main.cpp tests.o tests.hpp graphs.hpp
	$(CC) $(INCLUDE) $(CC_FLAGS) -o $@ -c $<

tests.o: tests.cpp tests.hpp datastructures.hpp sorts.hpp graphs.hpp
	$(CC) $(INCLUDE) $(CC_FLAGS) -o $@ -c $<

work.o: work.cpp sorts.hpp nbrs.hpp datastructures.hpp graphs.hpp
	$(CC) $(INCLUDE) $(CC_FLAGS) -o $@ -c $<

