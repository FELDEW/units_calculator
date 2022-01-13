NAME = test_maker

SRCS = ./test_maker.cpp ../Vector.cpp

CLANG =     clang++

CPPFLAGS =  -Wall -Wextra -Werror

RM =        rm -f

all :       ${NAME}

$(NAME) : 
			$(CLANG) $(CPPFLAGS) $(SRCS) -o $@

fclean  :
			$(RM) ${NAME}

re :        fclean all

.PHONY :    all fclean re