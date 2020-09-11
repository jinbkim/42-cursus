# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jinbkim <jinbkim@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/26 18:11:27 by jinbkim           #+#    #+#              #
#    Updated: 2020/07/28 12:30:08 by jinbkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC 	= $(wildcard *.c) 
OBJS	= $(SRC:.c=.o)

NAME	= libft.a
RM		= rm -f
LIB		= ar rc 
CC		= gcc
# CFLAGS	= -Wall -Wextra -Werror -g -fsanitize=address
CFLAGS	= -Wall -Wextra -Werror
all 	: $(NAME)

clean	: 
		$(RM) $(OBJS) *.gch *.out

fclean	: clean
		$(RM) $(NAME)

re		: fclean all

$(NAME) : $(OBJS)
		$(LIB) $(NAME) $(OBJS)