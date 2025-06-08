//Email: yuvali532@gmail.com
# Variables
CXX = g++
CXXFLAGS = -Wall -g
SRC = main.cpp
OBJ = $(SRC:.cpp=.o)
EXEC = run
DOCTEST_SRC = test.cpp
DOCTEST_EXEC = test
DOCTEST_DIR = ./doctest

# Target: make Main - Compiles and runs the demo program
Main: $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(EXEC)
	./$(EXEC)

# Target: make test - Compiles and runs the unit tests using Doctest
test: $(DOCTEST_SRC)
	$(CXX) $(CXXFLAGS) $(DOCTEST_SRC) -o $(DOCTEST_EXEC) -I$(DOCTEST_DIR)
	./$(DOCTEST_EXEC)

# Target: make valgrind - Runs valgrind to check for memory leaks in the demo
valgrind: Main
	valgrind --leak-check=full --show-leak-kinds=all ./$(EXEC)

# Target: make clean - Removes generated files 
clean:
	rm -f $(OBJ) $(EXEC) $(DOCTEST_EXEC)
