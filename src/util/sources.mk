UTIL := UnitNode.cpp

OBJ := $(OBJ) $(UTIL:.cpp=.o)

$(DIROBJ)/%.o: $(DIRUTIL)/%.cpp $(INC)
		$(COMPIL)
