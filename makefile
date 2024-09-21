# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/19 16:55:30 by ide-dieg          #+#    #+#              #
#    Updated: 2024/09/20 16:28:43 by ide-dieg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = 	src/main.c

CC = gcc

CFLAGS = -Wall -Wextra -Werror

LFLAGS = -lXext -lX11 -lm

LIBSA = minilibx-linux/libmlx.a \
		minilibx-linux/libmlx_Linux.a \

build: build_minilibx-linux
	$(CC) $(CFLAGS) -o $(NAME) $(SRC) $(LIBSA) $(LFLAGS)

fclean: fclean_minilibx-linux
	rm -f $(NAME)

re: fclean build

build_minilibx-linux:
	make -C minilibx-linux

fclean_minilibx-linux:
	make -C minilibx-linux clean
