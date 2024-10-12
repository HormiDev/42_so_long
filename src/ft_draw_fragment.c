/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_fragment.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 23:52:57 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/10/13 01:03:42 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_draw_tile(t_game *game, int x, int y, int n_sprite)
{
	mlx_put_image_to_window(game->mlx, game->win, game->sprites[n_sprite],
			x * TILE_SIZE + (TILE_SIZE - ((t_img *)game->sprites[n_sprite])->width),
			y * TILE_SIZE + (TILE_SIZE - ((t_img *)game->sprites[n_sprite])->height));
}

void	ft_draw_fragment(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->map_fragment->x)
	{
		y = 0;
		while (y < game->map_fragment->y)
		{
			if (game->map_fragment->map[y][x] == '0')
				ft_draw_tile(game, x, y, 1);
			else if (game->map_fragment->map[y][x] == '1')
				ft_draw_tile(game, x, y, 2);
			else
				ft_draw_tile(game, x, y, 0);
			y++;
		}
		x++;
	}
}
