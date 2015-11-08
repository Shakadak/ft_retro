ENT := Unit.cpp Player.cpp

OBJ := $(OBJ) $(ENT:.cpp=.o)

$(DIROBJ)/%.o: $(DIRENT)/%.cpp $(INC)
		$(COMPIL)
