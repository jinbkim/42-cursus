# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jinbkim <jinbkim@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/26 18:29:02 by jinbkim           #+#    #+#              #
#    Updated: 2020/07/28 12:30:12 by jinbkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= cub3d
LIB		= libft
LIB.A	= libft/libft.a
LIB.H	= libft/libft.h
CUB		= src
CUB.A	= src/cub3d.a
CUB.H	= src/cub3d.h

RM		= rm -rf
CC		= gcc
# CFLAGS	= -Wall -Wextra -Werror -g -fsanitize=address
CFLAGS	= -Wall -Wextra -Werror
MLX 	= -lmlx -lm -framework OpenGL -framework AppKit

all 	: $(NAME)

clean	: 
		$(RM) $(OBJS) *.gch *.out
		make clean -C $(LIB)
		make clean -C $(CUB)

fclean	: clean
		$(RM) $(NAME)
		make fclean -C $(LIB)
		make fclean -C $(CUB)

re		: fclean all

$(NAME) :
		make -C $(LIB)
		make -C $(CUB)
		$(CC) $(CFLAGS) $(MLX) $(LIB.A) $(LIB.H) $(CUB.A) $(CUB.H)
		mv a.out cub3d