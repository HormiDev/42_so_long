/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 16:24:11 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/10/22 02:01:14 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include "../42_Libft/libft.h"

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
# ifndef TILE_SIZE
#  define TILE_SIZE 128
# endif
# if TILE_SIZE < 0
#  undef TILE_SIZE
#  define TILE_SIZE 128
# endif

typedef struct s_player
{
	int		x;
	int		y;
	int		n_sprite;
	char	tile;
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
	int 			win_width;
	int 			win_height;
	void			*win;
	void			*sprites[38];
	t_player		*player;
	int				count_moves;
	int				keys;
}	t_game;

void			ft_error_so_long(t_game *game, int error);

t_game			*ft_game_init();
void			ft_game_clear(t_game *game);
t_game			*ft_game_loading(int fd);
int				ft_game_close(void *param);

int				ft_checkmap(t_file *map);
int				ft_map_is_rectangular(t_file *map);
int				ft_map_is_closed(t_file *map);
int				ft_check_characters_map(t_file *map);
int				ft_check_epc_map(t_file *map);
void			ft_count_epc_map(t_file *map, int *e, int *p, int *c);
int				ft_check_map_roads(t_file *map);
void			ft_check_roads(t_file *map, int x, int y);
void			ft_localize_player_in_map(t_file *map, int *x, int *y);

t_map_fragment	*ft_map_fragment_new();
void			ft_map_fragment_clear(t_map_fragment *map_fragment);
void			ft_map_fragment_loading(t_game *game);
t_map_fragment	*ft_map_fragment_add_right(t_map_fragment *map_fragment, t_game *game);
t_map_fragment	*ft_map_fragment_add_left(t_map_fragment *map_fragment, t_game *game);
t_map_fragment	*ft_map_fragment_add_up(t_map_fragment *map_fragment, t_game *game);
t_map_fragment	*ft_map_fragment_add_down(t_map_fragment *map_fragment, t_game *game);
void			ft_map_fragment_necesary(t_game *game, int *x, int *y);

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
void			ft_move_down(t_game *game);
void			ft_move_left(t_game *game);
void			ft_move_right(t_game *game);

#endif
