# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/19 16:55:30 by ide-dieg          #+#    #+#              #
#    Updated: 2024/11/05 21:29:59 by ide-dieg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = 	src/main.c \
		src/ft_error_so_long.c \
		src/fts_t_game.c \
		src/fts_t_game_2.c \
		src/fts_checkmap.c \
		src/fts_checkmap2.c \
		src/fts_t_map_fragment.c \
		src/fts_t_map_fragment_2.c \
		src/fts_t_map_fragment_3.c \
		src/fts_t_map_fragment_4.c \
		src/fts_window.c \
		src/fts_sprites.c \
		src/ft_draw_fragment.c \
		src/fts_config_controls.c \
		src/fts_config_controls_2.c \
		src/fts_t_player.c \
		src/fts_process_char_map.c \
		src/ft_count_keys.c \
		src/fts_history.c \

SRC_BONUS = src_bonus/main.c \
			src_bonus/ft_error_so_long.c \
			src_bonus/fts_t_game.c \
			src_bonus/fts_t_game_2.c \
			src_bonus/fts_checkmap.c \
			src_bonus/fts_checkmap2.c \
			src_bonus/fts_t_map_fragment.c \
			src_bonus/fts_t_map_fragment_2.c \
			src_bonus/fts_t_map_fragment_3.c \
			src_bonus/fts_t_map_fragment_4.c \
			src_bonus/fts_window.c \
			src_bonus/fts_sprites.c \
			src_bonus/ft_draw_fragment.c \
			src_bonus/ft_draw_text.c \
			src_bonus/fts_config_controls.c \
			src_bonus/fts_config_controls_2.c \
			src_bonus/fts_t_player.c \
			src_bonus/fts_process_char_map.c \
			src_bonus/ft_count_keys.c \
			src_bonus/fts_history.c \
			src_bonus/ft_animations_loop.c \

CC = cc

CFLAGS = -Wall -Wextra -Werror

LFLAGS = -lXext -lX11 -lm

LIBSA = minilibx-linux/libmlx.a \
		42_Libft/libft.a \
		

build: ide-dieg so_long_title update_submodules build_minilibx-linux build_libft
	@if [ ! -f $(NAME) ]; then \
		echo "$(NARANJA)Building $(NAME)...$(NC)"; \
		$(CC) $(CFLAGS) -o $(NAME) $(SRC) $(LIBSA) $(LFLAGS); \
		tput cuu1 && tput el; \
		echo "$(VERDE)$(NAME) built!$(NC)"; \
	fi

build_bonus: ide-dieg so_long_title update_submodules build_minilibx-linux build_libft
	@if [ ! -f $(NAME) ]; then \
		echo "$(NARANJA)Building $(NAME)...$(NC)"; \
		$(CC) $(CFLAGS) -o $(NAME) $(SRC_BONUS) $(LIBSA) $(LFLAGS); \
		tput cuu1 && tput el; \
		echo "$(VERDE)$(NAME) built!$(NC)"; \
	fi

build_windows_max_size: ide-dieg so_long_title update_submodules build_minilibx-linux build_libft
	@if [ ! -f $(NAME) ]; then \
		echo "$(NARANJA)Building $(NAME)...$(NC)"; \
		read -p "Enter MAX_WIN_WIDTH: " WIDTH; \
		read -p "Enter MAX_WIN_HEIGHT: " HEIGHT; \
		$(CC) $(CFLAGS) -D MAX_WIN_WIDTH=$$WIDTH -D MAX_WIN_HEIGHT=$$HEIGHT -o $(NAME) $(SRC) $(LIBSA) $(LFLAGS); \
		tput cuu1 && tput el && tput cuu1 && tput el &&tput cuu1 && tput el; \
		echo "$(VERDE)$(NAME) built!$(NC)"; \
	fi

build_bonus_windows_max_size: ide-dieg so_long_title update_submodules build_minilibx-linux build_libft
	@if [ ! -f $(NAME) ]; then \
		echo "$(NARANJA)Building $(NAME)...$(NC)"; \
		read -p "Enter MAX_WIN_WIDTH: " WIDTH; \
		read -p "Enter MAX_WIN_HEIGHT: " HEIGHT; \
		$(CC) $(CFLAGS) -D MAX_WIN_WIDTH=$$WIDTH -D MAX_WIN_HEIGHT=$$HEIGHT -o $(NAME) $(SRC_BONUS) $(LIBSA) $(LFLAGS); \
		tput cuu1 && tput el && tput cuu1 && tput el &&tput cuu1 && tput el; \
		echo "$(VERDE)$(NAME) built!$(NC)"; \
	fi

fclean: fclean_minilibx-linux fclean_libft
	@echo "Cleaning $(NAME)..."
	@rm -f $(NAME)
	@echo "$(NAME) cleaned!"

re: fclean build

re_bonus: fclean build_bonus

build_minilibx-linux:
	@if [ ! -f minilibx-linux/libmlx.a ]; then \
		echo "$(NARANJA)Compiling Minilibx-linux...$(NC)"; \
		make -C minilibx-linux > /dev/null 2>&1; \
		tput cuu1 && tput el; \
		echo "$(VERDE)Minilibx-linux compiled!$(NC)"; \
	fi

fclean_minilibx-linux:
	@echo "Cleaning Minilibx-linux..."
	@make -C minilibx-linux clean > /dev/null 2>&1
	@echo "Minilibx-linux cleaned!"

build_libft:
	@if [ ! -f 42_Libft/libft.a ]; then \
		echo "$(NARANJA)Compiling Libft...$(NC)"; \
		make all -C 42_Libft > /dev/null 2>&1; \
		tput cuu1 && tput el; \
		echo "$(VERDE)Libft compiled!$(NC)"; \
	fi

fclean_libft:
	@echo "Cleaning Libft..."
	@make fclean -C 42_Libft > /dev/null 2>&1
	@echo "Libft cleaned!"

update_submodules:
	@echo "$(NARANJA)Updating submodules...$(NC)"
	@git submodule update --init --recursive > /dev/null 2>&1
	@tput cuu1 && tput el
	@echo "$(VERDE)Submodules updated!$(NC)" 

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