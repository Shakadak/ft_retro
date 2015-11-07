STATE := State.cpp

OBJ := $(OBJ) $(STATE:.cpp=.o)

$(DIROBJ)/%.o: $(DIRSTATE)/%.cpp $(INC)
		$(COMPIL)
