# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jinbkim <jinbkim@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/26 18:11:27 by jinbkim           #+#    #+#              #
#    Updated: 2020/09/08 11:41:54 by jinbkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC 	= $(wildcard *.c)
OBJS	= $(SRC:.c=.o)

NAME	= libft
RM		= rm -rf
LIB		= ar rc
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g -fsanitize=address

all 	: $(NAME)

$(NAME)	: $(OBJS)

clean	:
		$(RM) $(OBJS) *.gch *.out

fclean	: clean
		$(RM) $(NAME)

re		: fclean all

$(NAME)	: $(OBJS)