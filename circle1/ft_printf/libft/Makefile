SRC 	=	arr_init.c\
			data_leng.c\
			ft_isnum.c\
			ft_put_data.c\
			ft_strdup.c\
			ft_strlen.c

OBJS	= $(SRC:.c=.o)

NAME	= libft.a
RM		= rm -f
LIB		= ar rc 
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

all 	: $(NAME)

clean	: 
		$(RM) $(OBJS) *.gch

fclean	: clean
		$(RM) $(NAME)

re		: fclean all

$(NAME) : $(OBJS)
		$(LIB) $@ $^
