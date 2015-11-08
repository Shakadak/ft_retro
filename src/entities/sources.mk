ENT := Unit.cpp

OBJ := $(OBJ) $(ENT:.cpp=.o)

$(DIROBJ)/%.o: $(DIRENT)/%.cpp $(INC)
		$(COMPIL)
