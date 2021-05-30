NAME		= main
OBJ			= *.o

RM			= rm -rf
CC			= clang++
CFLAGS		= -Wall -Wextra -Werror -std=c++98
DIR			= ./src



all 		: $(NAME)

clean		:
			make clean -C $(DIR)

fclean		:
			make fclean -C $(DIR)
			$(RM) $(NAME)

re			: fclean all



$(NAME) 	:
			make -C $(DIR)
			$(CC) $(CFLAGS) -o $(NAME) $(DIR)/$(OBJ)