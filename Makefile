# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/19 16:55:30 by ide-dieg          #+#    #+#              #
#    Updated: 2024/10/25 01:49:22 by ide-dieg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = 	src/main.c \
		src/ft_error_so_long.c \
		src/fts_t_game.c \
		src/fts_checkmap.c \
		src/fts_checkmap2.c \
		src/fts_t_map_fragment.c \
		src/fts_window.c \
		src/fts_sprites.c \
		src/ft_draw_fragment.c \
		src/fts_config_controls.c \
		src/fts_t_player.c \
		src/fts_process_char_map.c \
		src/ft_count_keys.c \
		src/fts_history.c \

CC = cc

CFLAGS = -Wall -Wextra -Werror

LFLAGS = -lXext -lX11 -lm

LIBSA = minilibx-linux/libmlx.a \
		42_Libft/libft.a \
		

build: ide-dieg so_long_title build_minilibx-linux build_libft
	@if [ ! -f $(NAME) ]; then \
		echo "Building $(NAME)..."; \
		$(CC) $(CFLAGS) -o $(NAME) $(SRC) $(LIBSA) $(LFLAGS); \
		echo "$(NAME) built!"; \
	fi

fclean: fclean_minilibx-linux fclean_libft
	@echo "Cleaning $(NAME)..."
	@rm -f $(NAME)
	@echo "$(NAME) cleaned!"

re: fclean build

build_minilibx-linux:
	@if [ ! -f minilibx-linux/libmlx.a ]; then \
		echo "Compiling Minilibx-linux..."; \
		make -C minilibx-linux > /dev/null 2>&1; \
		echo "Minilibx-linux compiled!"; \
	fi

fclean_minilibx-linux:
	@echo "Cleaning Minilibx-linux..."
	@make -C minilibx-linux clean > /dev/null 2>&1
	@echo "Minilibx-linux cleaned!"

build_libft:
	@if [ ! -f 42_Libft/libft.a ]; then \
		echo "Compiling Libft..."; \
		make additional -C 42_Libft > /dev/null 2>&1; \
		echo "Libft compiled!"; \
	fi

fclean_libft:
	@echo "Cleaning Libft..."
	@make fclean -C 42_Libft > /dev/null 2>&1
	@echo "Libft cleaned!"

ROJO = \033[0;31m
NC = \033[0m
NARANJA = \033[0;33m
AZUL = \033[0;34m
VERDE = \033[0;32m

ide-dieg:
	@clear	
	@echo "$(ROJO)██╗██████╗ ███████╗    ██████╗ ██╗███████╗ ██████╗ $(AZUL)         ██╗  ██╗██████╗ "
	@echo "$(ROJO)██║██╔══██╗██╔════╝    ██╔══██╗██║██╔════╝██╔════╝ $(AZUL)         ██║  ██║╚════██╗"
	@echo "$(ROJO)██║██║  ██║█████╗█████╗██║  ██║██║█████╗  ██║  ███╗$(AZUL)         ███████║ █████╔╝"
	@echo "$(ROJO)██║██║  ██║██╔══╝╚════╝██║  ██║██║██╔══╝  ██║   ██║$(AZUL)         ╚════██║██╔═══╝ "
	@echo "$(ROJO)██║██████╔╝███████╗    ██████╔╝██║███████╗╚██████╔╝$(AZUL)              ██║███████╗"
	@echo "$(ROJO)╚═╝╚═════╝ ╚══════╝    ╚═════╝ ╚═╝╚══════╝ ╚═════╝ $(AZUL)              ╚═╝╚══════╝"
	@echo "$(NARANJA)██╗  ██╗ ██████╗ ██████╗ ███╗   ███╗██╗██████╗ ███████╗██╗   ██╗$(VERDE)       ██╗  "
	@echo "$(NARANJA)██║  ██║██╔═══██╗██╔══██╗████╗ ████║██║██╔══██╗██╔════╝██║   ██║$(VERDE)   ██╗ ╚═██╗"
	@echo "$(NARANJA)███████║██║   ██║██████╔╝██╔████╔██║██║██║  ██║█████╗  ██║   ██║$(VERDE)   ╚═╝   ██║"
	@echo "$(NARANJA)██╔══██║██║   ██║██╔══██╗██║╚██╔╝██║██║██║  ██║██╔══╝  ╚██╗ ██╔╝$(VERDE)   ██╗   ██║"
	@echo "$(NARANJA)██║  ██║╚██████╔╝██║  ██║██║ ╚═╝ ██║██║██████╔╝███████╗ ╚████╔╝ $(VERDE)   ╚═╝ ██╔═╝ "
	@echo "$(NARANJA)╚═╝  ╚═╝ ╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝╚═╝╚═════╝ ╚══════╝  ╚═══╝  $(VERDE)       ╚═╝  $(NC)"

so_long_title:
	@echo " ____   __        __     __   __ _   ___ "
	@echo "/ ___) /  \      (  )   /  \ (  ( \ / __)"
	@echo "\\___ \(  O )____ / (_/\\(  O )/    /( (_ \ "
	@echo "(____/ \__/(____)\____/ \__/ \_)__) \___/"