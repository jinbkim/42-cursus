SRC			= List.cpp \
				main.cpp \
				Map.cpp \
				Queue.cpp \
				Stack.cpp \
				Vector.cpp
OBJ			= ${SRC:%.cpp=%.o}

NAME		= main
RM			= rm -rf
CC			= clang++
CFLAGS		= -Wall -Wextra -Werror -g -fsanitize=address -std=c++98



all 		: $(NAME)

clean		:
			$(RM) $(OBJ) *.out *.dSYM

fclean		: clean

re			: fclean all



$(NAME) 	: $(SRC)
			$(CC) -c $(CFLAGS) $(SRC)