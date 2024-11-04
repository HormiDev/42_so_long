/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 00:05:56 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/10/30 20:26:55 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_window_size(t_game *game)
{
	if (MAX_WIN_WIDTH < TILE_SIZE || MAX_WIN_HEIGHT < TILE_SIZE)
		ft_error_so_long(game, 5);
	if ((game->map->lines - 1) * TILE_SIZE < MAX_WIN_HEIGHT)
		game->win_height = game->map->lines * TILE_SIZE;
	if ((game->map->list_content->len - 2) * TILE_SIZE < MAX_WIN_WIDTH)
		game->win_width = (game->map->list_content->len - 1) * TILE_SIZE;
	if (game->win_width % TILE_SIZE != 0)
		game->win_width = (game->win_width / TILE_SIZE) * TILE_SIZE;
	if (game->win_height % TILE_SIZE != 0)
		game->win_height = (game->win_height / TILE_SIZE) * TILE_SIZE;
}

void	ft_init_window(t_game *game)
{
	game->win = mlx_new_window(game->mlx, game->win_width,
			game->win_height, "so_long");
	if (!game->win)
		ft_error_so_long(game, 1);
}
