# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/19 16:55:30 by ide-dieg          #+#    #+#              #
#    Updated: 2024/09/25 02:20:19 by ide-dieg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = 	src/main.c \
		src/fts_t_game.c \
		src/fts_checkmap.c \
		src/fts_checkmap2.c \

CC = gcc

CFLAGS = -Wall -Wextra -Werror

LFLAGS = -lXext -lX11 -lm

LIBSA = minilibx-linux/libmlx.a \
		minilibx-linux/libmlx_Linux.a \
		42_Libft/libft.a \
		

build: build_minilibx-linux build_libft
	$(CC) $(CFLAGS) -o $(NAME) $(SRC) $(LIBSA) $(LFLAGS)

fclean: fclean_minilibx-linux fclean_libft
	rm -f $(NAME)

re: fclean build

build_minilibx-linux:
	make -C minilibx-linux

fclean_minilibx-linux:
	make -C minilibx-linux clean

build_libft:
	make additional -C 42_Libft

fclean_libft:
	make fclean -C 42_Libft
