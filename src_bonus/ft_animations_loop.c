/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animations_loop.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 21:27:29 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/12/18 18:40:11 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_iter_squeleton(t_game *game, int x, int y)
{
	if (game->map_fragment->map[y][x] < 91)
		game->map_fragment->map[y][x]++;
	else
		game->map_fragment->map[y][x] = 88;
}

void	ft_animate_flowers(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->map_fragment->x)
	{
		y = 0;
		while (y < game->map_fragment->y)
		{
			if (game->map_fragment->map[y][x] >= 64
				&& game->map_fragment->map[y][x] <= 76)
			{
				game->map_fragment->map[y][x]++;
				if ((game->map_fragment->map[y][x] - 64) % 4 == 0)
					game->map_fragment->map[y][x] -= 4;
			}
			if (game->map_fragment->map[y][x] >= 88
				&& game->map_fragment->map[y][x] <= 91)
				ft_iter_squeleton(game, x, y);
			y++;
		}
		x++;
	}
}

int	ft_animations_loop(t_game *game)
{
	long	time;

	time = clock();
	if (game->time_flowers + 100000 < time)
	{
		game->time_flowers = time;
		ft_animate_flowers(game);
	}
	if (game->time_last_frame + 16666 < time)
	{
		game->time_last_frame = time;
		ft_draw_fragment(game);
	}
	return (0);
}
