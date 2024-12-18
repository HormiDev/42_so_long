/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 16:24:11 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/11/16 18:23:11 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <time.h>
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include "../42_Libft/libft.h"

# ifndef TILE_SIZE
#  define TILE_SIZE 128
# endif
# if TILE_SIZE < 0
#  undef TILE_SIZE
#  define TILE_SIZE 128
# endif
# ifndef MAX_WIN_WIDTH
#  define MAX_WIN_WIDTH 1920
# endif
# if MAX_WIN_WIDTH < 0
#  undef MAX_WIN_WIDTH
#  define MAX_WIN_WIDTH 1920
# endif
# ifndef MAX_WIN_HEIGHT
#  define MAX_WIN_HEIGHT 896
# endif
# if MAX_WIN_HEIGHT < 0
#  undef MAX_WIN_HEIGHT
#  define MAX_WIN_HEIGHT 896
# endif

typedef struct s_player
{
	int		x;
	int		y;
	int		xy_position[2];
	int		xy_destination[2];
	int		n_sprite;
	char	tile;
	int		in_movement;
}	t_player;

typedef struct s_map_fragment
{
	int						x;
	int						y;
	char					**map;
	struct s_map_fragment	*left;
	struct s_map_fragment	*right;
	struct s_map_fragment	*up;
	struct s_map_fragment	*down;
}	t_map_fragment;

typedef struct s_game
{
	t_file			*map;
	t_map_fragment	*map_fragment;
	void			*mlx;
	int				win_width;
	int				win_height;
	void			*win;
	void			*sprites[39];
	t_player		*player;
	int				count_moves;
	int				keys;
	long			time_flowers;
	long			time_last_frame;
}	t_game;

void			ft_error_so_long(t_game *game, int error);

t_game			*ft_game_init(void);
void			ft_game_clear(t_game *game);
t_game			*ft_game_loading(int fd);
int				ft_game_close(void *param);
void			ft_game_win(t_game *game);

int				ft_checkmap(t_file *map);
int				ft_map_is_rectangular(t_file *map);
int				ft_map_is_closed(t_file *map);
int				ft_check_characters_map(t_file *map);
int				ft_check_epc_map(t_file *map);
void			ft_count_epc_map(t_file *map, int *e, int *p, int *c);
int				ft_check_map_roads(t_file *map);
void			ft_check_roads(t_file *map, int x, int y);
int				ft_check_map_roads_2(t_file *map);
void			ft_check_roads_2(t_file *map, int x, int y);
void			ft_localize_player_in_map(t_file *map, int *x, int *y);

t_map_fragment	*ft_map_fragment_new(t_game *game);
void			ft_map_fragment_clear(t_map_fragment *map_fragment);
void			ft_map_fragment_loading(t_game *game);
t_map_fragment	*ft_map_fragment_add_right(t_map_fragment *map_fragment,
					t_game *game);
t_map_fragment	*ft_map_fragment_add_left(t_map_fragment *map_fragment,
					t_game *game);
t_map_fragment	*ft_map_fragment_add_up(t_map_fragment *map_fragment,
					t_game *game);
t_map_fragment	*ft_map_fragment_add_down(t_map_fragment *map_fragment,
					t_game *game);
void			ft_map_fragment_necesary(t_game *game, int *x, int *y);
void			ft_map_fragment_extend(t_game *game, int x, int y);
void			ft_copy_map_to_fragment_line(t_game *game,
					t_map_fragment *tmp_x, int cm_cf_x[3]);
void			ft_copy_map_to_fragment(t_game *game, int x, int y);
void			ft_map_fragment_fill_char(t_game *game, int c);
t_map_fragment	*ft_map_fragment_search_player(t_game *game);
void			ft_map_fragment_loading(t_game *game);
void			ft_map_fragment_print(t_map_fragment *map_fragment);

void			ft_window_size(t_game *game);
void			ft_init_window(t_game *game);

void			*ft_new_sprite(t_game *game, char *path);
void			ft_init_sprites(t_game *game);
void			ft_free_sprites(t_game *game);

void			ft_draw_fragment(t_game *game);

void			ft_config_controls(t_game *game);
int				ft_key_press(int keycode, t_game *game);

t_player		*ft_player_config(t_game *game);
void			ft_localize_player(t_game *game, t_player *player);
void			ft_proces_player_tile(t_game *game, t_player *player);

void			ft_process_char_map(t_game *game);

void			ft_count_keys(t_game *game);

void			ft_move_up(t_game *game);
void			ft_move_up_2(t_game *game);
void			ft_move_down(t_game *game);
void			ft_move_down_2(t_game *game);
void			ft_move_left(t_game *game);
void			ft_move_left_2(t_game *game);
void			ft_move_right(t_game *game);
void			ft_move_right_2(t_game *game);

void			ft_print_start_history(t_game *game);
void			ft_print_start_history_es(t_game *game);
void			ft_print_victory_message(t_game *game);
void			ft_print_victory_message_es(t_game *game);

void			ft_draw_text(t_game *game);
int				ft_animations_loop(t_game *game);

#endif
