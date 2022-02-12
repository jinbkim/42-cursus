SRC 	=	ft_printf.c\
			read_info.c\
			show_cps.c\
			show_diux.c\

OBJS	= $(SRC:.c=.o)

NAME	= libftprintf.a
LIBFT	= libft
LIBFT.A	= libft.a
RM		= rm -rf
LIB		= ar rc 
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

all 	: $(NAME)

clean	: 
		$(RM) $(OBJS) *.gch
		make clean -C $(LIBFT)

fclean	: clean
		$(RM) $(NAME)
		make fclean -C $(LIBFT)

re		: fclean all

$(NAME) : $(OBJS)
		make -C $(LIBFT)
		cp $(LIBFT)/$(LIBFT.A) $@
		$(LIB) $@ $^