MAIN := main.cpp unit.cpp

OBJ := $(OBJ) $(MAIN:.cpp=.o)

$(DIROBJ)/%.o: $(DIRMAIN)/%.cpp $(INC)
		$(COMPIL)
