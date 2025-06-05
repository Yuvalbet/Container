# משתנים
CXX = g++                # המהדר לשימוש
CXXFLAGS = -Wall -g      # דגלים להדפסת אזהרות והוספת מידע דיבאג
SRC = main.cpp           # קובץ המקור היחיד (main.cpp)
OBJ = $(SRC:.cpp=.o)     # המרת קובץ .cpp ל-.o (קובץ אובייקט)
EXEC = run               # שם קובץ הביצוע
DOCTEST_SRC = test.cpp   # קובץ הבדיקות שלך

# ברירת מחדל היא להריץ את הקובץ הראשי
all: Main

# הפקודה make Main
Main: $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(EXEC)
	./$(EXEC)  # הרצת קובץ ההדגמה לאחר ההרכבה

# הפקודה make valgrind
valgrind: $(EXEC)
	valgrind --leak-check=full ./$(EXEC)

# הפקודה make clean - לניקוי קבצים לא רלוונטיים
clean:
	rm -f $(OBJ) $(EXEC) test
