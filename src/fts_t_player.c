/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_t_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 22:00:33 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/10/13 22:13:59 by ide-dieg         ###   ########.fr       */
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
	player->n_sprite = 2;
	player->tile = '0';
	ft_localize_player(game, player);
	return (player);
}