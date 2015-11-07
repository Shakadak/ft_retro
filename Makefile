NAME	:=	ft_retro

### DIRECTORIES ###

DIRSRC	:=	src
DIROBJ	:=	obj
DIRINC	:=	inc

DIRMAIN		:=	$(DIRSRC)/main
3DIRPARSER	:=	$(DIRSRC)/parser
#DIRSHAPE	:=	$(DIRSRC)/shapes
#DIRRAY		:=	$(DIRSRC)/ray
#DIRUTIL		:=	$(DIRSRC)/util

### FILES ###

#HEAD := $(DIRINC)/$(NAME).h

include $(DIRMAIN)/sources.mk
#include $(DIRPARSER)/sources.mk
#include $(DIRSHAPE)/sources.mk
#include $(DIRRAY)/sources.mk
#include $(DIRUTIL)/sources.mk

POBJ	:=	$(addprefix $(DIROBJ)/, $(OBJ))

### COMPILATION VARIABLES ###

CC := clang++

C_FLAG	:=	-Wall -Wextra -Werror
O_FLAG	:=	-O3

C_INC	:=	-I $(DIRINC)

L_FLAG	:=	-lncurses

COMPIL	= $(CC) -o $@ -c $< $(C_INC) $(C_FLAG) $(O_FLAG)
LINK	= $(CC) -o $@ $^ $(L_FLAG)


### RULES ###

.PHONY: all clean fclean re

all: $(PMLX) $(PFT) $(PUMLX) $(PMTX) $(NAME)

$(POBJ): |$(DIROBJ)

$(DIROBJ):
	mkdir $(DIROBJ)

$(NAME): $(POBJ)
	$(LINK)


### MISC ###

clean:
	rm -rf $(DIROBJ)

fclean: clean
	rm -f $(NAME)

run: all
	./$(NAME)

re: fclean all
