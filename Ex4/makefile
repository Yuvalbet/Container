# משתנים
CXX = g++
CXXFLAGS = -Wall -g
SRC = main.cpp
OBJ = $(SRC:.cpp=.o)
EXEC = run
DOCTEST_SRC = test.cpp
DOCTEST_EXEC = test
DOCTEST_DIR = ./doctest

# הפקודה make Main - להרצת קובץ ההדגמה
Main: $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(EXEC)
	./$(EXEC)

# הפקודה make test - להרצת בדיקות היחידה
test: $(DOCTEST_SRC)
	$(CXX) $(CXXFLAGS) $(DOCTEST_SRC) -o $(DOCTEST_EXEC) -I$(DOCTEST_DIR)
	./$(DOCTEST_EXEC)

# הפקודה make valgrind - בדיקת זליגת זיכרון באמצעות valgrind
valgrind: Main
	valgrind --leak-check=full --show-leak-kinds=all ./$(EXEC)

# הפקודה make clean - לניקוי קבצים לא רלוונטיים לאחר ההרצה
clean:
	rm -f $(OBJ) $(EXEC) $(DOCTEST_EXEC)
