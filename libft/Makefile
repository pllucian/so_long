# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pllucian <pllucian@21-school.ru>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/10 10:52:07 by pllucian          #+#    #+#              #
#    Updated: 2021/11/23 16:35:49 by pllucian         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES =	ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memccpy.c \
		ft_memmove.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strlen.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strnstr.c \
		ft_strncmp.c \
		ft_atoi.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_arraylen.c \
		ft_freearray.c \
		ft_strisdigit.c \
		get_next_line.c

FT_PRINTF =	ft_printf.c ft_print_char.c ft_print_string.c ft_print_pointer.c \
			ft_print_int.c ft_print_uint.c ft_print_hex.c ft_print_percent.c \
			ft_set_flags.c ft_print_field.c ft_printf_utils.c

SRCS = $(addprefix srcs/, $(FILES)) $(addprefix srcs/ft_printf/, $(FT_PRINTF))

OBJS = $(addprefix objs/, $(FILES:.c=.o) $(FT_PRINTF:.c=.o))

INCL = includes/libft.h includes/ft_printf.h

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

objs/%.o:	srcs/%.c
			@ [ -d objs ] || mkdir -p objs
			$(CC) $(CFLAGS) -c $< -o $@ -I./includes

objs/%.o:	srcs/ft_printf/%.c
			@ [ -d objs ] || mkdir -p objs
			$(CC) $(CFLAGS) -c $< -o $@ -I./includes

$(NAME):	$(OBJS) $(INCL)
			$(AR) rcs $@ $(OBJS)

all:		$(NAME)

clean:
			$(RM)r $(OBJS) objs

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
