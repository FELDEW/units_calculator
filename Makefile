NAME = units_calculator

SRCS = ./main.cpp ./Unit.cpp ./Vector.cpp

CLANG =     clang++

CPPFLAGS =  -Wall -Wextra -Werror

RM =        rm -f

all :       ${NAME}

$(NAME) :
			$(CLANG) $(CPPFLAGS) $(SRCS) -o $@ -pthread

fclean  :
			$(RM) ${NAME}

re :        fclean all

.PHONY :    all fclean re