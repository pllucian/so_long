# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pllucian <pllucian@21-school.ru>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/22 21:21:16 by pllucian          #+#    #+#              #
#    Updated: 2021/11/26 17:48:53 by pllucian         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES =	so_long.c \
		parser.c \
		game.c \
		render.c \
		moves.c

SRCS = $(addprefix srcs/, $(FILES))

OBJS = $(addprefix objs/, $(FILES:.c=.o))

INCL = includes/so_long.h

NAME = so_long

CC = gcc

CFLAGS = -Wall -Wextra -Werror

objs/%.o:	srcs/%.c
			@ [ -d objs ] || mkdir -p objs
			$(CC) $(CFLAGS) -c $< -o $@ -I./includes -I./libft/includes -I./mlx

$(NAME):	$(OBJS) $(INCL)
			@make -C ./libft
			$(CC) -o $@ $(OBJS) -Llibft -Lmlx -lft -lmlx -lXext -lX11 -lm -lz

all:		$(NAME) 

clean:
			make clean -C ./libft
			$(RM)r $(OBJS) objs

fclean:		clean
			make fclean -C ./libft
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
