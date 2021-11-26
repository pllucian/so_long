# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pllucian <pllucian@21-school.ru>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/22 21:21:16 by pllucian          #+#    #+#              #
#    Updated: 2021/11/26 22:54:55 by pllucian         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES =	so_long.c \
		parser.c \
		game.c \
		render.c \
		moves.c

FILES_BONUS =	so_long_bonus.c \
				parser_bonus.c \
				game_bonus.c \
				render_bonus.c \
				moves_bonus.c

SRCS = $(addprefix srcs/, $(FILES))

SRCS_BONUS = $(addprefix srcs/, $(FILES_BONUS))

OBJS = $(addprefix objs/, $(FILES:.c=.o))

OBJS_BONUS = $(addprefix objs/, $(FILES_BONUS:.c=.o))

INCL = includes/so_long.h

INCL_BONUS = includes/so_long_bonus.h

NAME = so_long

CC = gcc

CFLAGS = -Wall -Wextra -Werror

objs/%.o:		srcs/%.c
				@ [ -d objs ] || mkdir -p objs
				$(CC) $(CFLAGS) -c $< -o $@ -I./includes -I./libft/includes -I./mlx

$(NAME):		$(OBJS) $(INCL)
				@make -C ./libft
				$(CC) -o $@ $(OBJS) -Llibft -Lmlx -lft -lmlx -lXext -lX11 -lm -lz

bonus:			$(OBJS_BONUS) $(INCL_BONUS)
				@make -C ./libft
				$(CC) -o $(NAME) $(OBJS_BONUS) -Llibft -Lmlx -lft -lmlx -lXext -lX11 -lm -lz

all:			$(NAME)

clean:
				make clean -C ./libft
				$(RM)r $(OBJS) $(OBJS_BONUS) bonus objs

fclean:			clean
				make fclean -C ./libft
				$(RM) $(NAME)

re:				fclean all

.PHONY:			bonus all clean fclean re
