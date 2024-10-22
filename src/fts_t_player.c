/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_t_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 22:00:33 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/10/21 21:43:14 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_localize_player(t_game *game, t_player *player)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->map_fragment->x)
	{
		y = 0;
		while (y < game->map_fragment->y)
		{
			if (game->map_fragment->map[y][x] == 'P')
			{
				player->x = x;
				player->y = y;
				return ;
			}
			y++;
		}
		x++;
	}
}

t_player	*ft_player_config(t_game *game)
{
	t_player	*player;

	player = (t_player *)malloc(sizeof(t_player));
	if (!player)
		ft_error_so_long(game, 1);
	player->n_sprite = 36;
	ft_localize_player(game, player);
	ft_proces_player_tile(game, player);
	return (player);
}

void	ft_proces_player_tile(t_game *game, t_player *player)
{
	player->tile = '0';
	if (player->y > 0)
	{
		if(game->map_fragment->map[player->y - 1][player->x] == '.' ||
			game->map_fragment->map[player->y - 1][player->x] == '/')
			player->tile += 1;
	}
	else
		if (game->map_fragment->up->map[game->map_fragment->y - 1][player->x] == '.' ||
			game->map_fragment->up->map[game->map_fragment->y - 1][player->x] == '/')
			player->tile += 1;
	if (player->x < game->map_fragment->x - 1)
	{
		if(game->map_fragment->map[player->y][player->x + 1] == '.' ||
			game->map_fragment->map[player->y][player->x + 1] == '/')
			player->tile += 2;
	}
	else
		if (game->map_fragment->right->map[player->y][0] == '.' ||
			game->map_fragment->right->map[player->y][0] == '/')
			player->tile += 2;
	if (player->y < game->map_fragment->y - 1)
	{
		if(game->map_fragment->map[player->y + 1][player->x] == '.' ||
			game->map_fragment->map[player->y + 1][player->x] == '/')
			player->tile += 4;
	}
	else
		if (game->map_fragment->down->map[0][player->x] == '.' ||
			game->map_fragment->down->map[0][player->x] == '/')
			player->tile += 4;
	if (player->x > 0)
	{
		if(game->map_fragment->map[player->y][player->x - 1] == '.' ||
			game->map_fragment->map[player->y][player->x - 1] == '/')
			player->tile += 8;
	}
	else
		if (game->map_fragment->left->map[player->y][game->map_fragment->x - 1] == '.' ||
			game->map_fragment->left->map[player->y][game->map_fragment->x - 1] == '/')
			player->tile += 8;
}
