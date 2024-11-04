/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_fragment.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 23:52:57 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/11/02 22:33:48 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_draw_tile(t_game *game, int x, int y, int n_sprite)
{
	mlx_put_image_to_window(game->mlx, game->win, game->sprites[n_sprite],
		x + (TILE_SIZE - ((t_img *)game->sprites[n_sprite])->width),
		y + (TILE_SIZE - ((t_img *)game->sprites[n_sprite])->height));
}

void	ft_draw_player(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->sprites[game->player->tile - 45],
		x + (TILE_SIZE - ((t_img *)game->sprites[game->player->tile
				- 45])->width),
		y + (TILE_SIZE - ((t_img *)game->sprites[game->player->tile
				- 45])->height));
	mlx_put_image_to_window(game->mlx, game->win,
		game->sprites[game->player->n_sprite],
		x - 18 + (TILE_SIZE
			- ((t_img *)game->sprites[game->player->n_sprite])->width),
		y + (TILE_SIZE
			- ((t_img *)game->sprites[game->player->n_sprite])->height));
	if (game->player->y == game->map_fragment->y - 1
		&& (game->player->tile == 12 + '0' || game->player->tile == 4 + '0'
			|| game->player->tile == 6 + '0' || game->player->tile == 7 + '0'
			|| game->player->tile == 14 + '0' || game->player->tile == 5 + '0'
			|| game->player->tile == 13 + '0'))
		ft_draw_tile(game, x, y + TILE_SIZE, 1);
}

void	ft_select_tile(t_game *game, int x, int y)
{
	if (game->map_fragment->map[y][x] >= 46
		&& game->map_fragment->map[y][x] <= 76)
		ft_draw_tile(game, x * TILE_SIZE, y * TILE_SIZE,
			game->map_fragment->map[y][x] - 45);
	else if (game->map_fragment->map[y][x] == '/')
		ft_draw_tile(game, x * TILE_SIZE, y * TILE_SIZE, 2);
	else if (game->map_fragment->map[y][x] == 'P')
		ft_draw_player(game, x * TILE_SIZE, y * TILE_SIZE);
	else if (game->map_fragment->map[y][x] == 'c')
		ft_draw_tile(game, x * TILE_SIZE, y * TILE_SIZE, 33);
	else if (game->map_fragment->map[y][x] == 'e' && game->keys > 0)
		ft_draw_tile(game, x * TILE_SIZE, y * TILE_SIZE, 31);
	else if (game->map_fragment->map[y][x] == 'e' && game->keys <= 0)
		ft_draw_tile(game, x * TILE_SIZE, y * TILE_SIZE, 32);
	else
		ft_draw_tile(game, x * TILE_SIZE, y * TILE_SIZE, 0);
}

void	ft_draw_fragment(t_game *game)
{
	int	x;
	int	y;

	mlx_clear_window(game->mlx, game->win);
	x = 0;
	while (x < game->map_fragment->x)
	{
		y = 0;
		while (y < game->map_fragment->y)
		{
			ft_select_tile(game, x, y);
			y++;
		}
		x++;
	}
}
