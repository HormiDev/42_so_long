/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 16:24:11 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/09/25 19:35:33 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include "../42_Libft/libft.h"

typedef struct s_sprite
{
	int		width;
	int		height;
	void	*img;
}	t_sprite;

typedef struct s_game
{
	t_file	*map;
}	t_game;

t_game		*ft_init_game(int fd);
void		ft_free_game(t_game *game);
int			ft_checkmap(t_file *map);

int			ft_checkmap(t_file *map);
int			ft_map_is_rectangular(t_file *map);
int			ft_map_is_closed(t_file *map);
int			ft_check_characters_map(t_file *map);
int			ft_check_epc_map(t_file *map);
void		ft_count_epc_map(t_file *map, int *e, int *p, int *c);
int			ft_check_map_roads(t_file *map);
void		ft_check_roads(t_file *map, int x, int y);
void		ft_localize_player_in_map(t_file *map, int *x, int *y);

#endif
