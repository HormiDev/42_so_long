/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_config_controls.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 00:25:28 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/11/03 01:37:46 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_up_2(t_game *game)
{
	if (game->player->tile == 'c')
	{
		game->keys--;
		ft_proces_player_tile(game, game->player);
	}
	if (game->player->tile == 'e')
	{
		if (game->keys == 0)
			ft_game_win(game);
		else
		{
			ft_printf("You still need to collect %d keys\n", game->keys);
			game->count_moves--;
			ft_move_down(game);
			return ;
		}
	}
	ft_printf("Number of movements %d\n", ++game->count_moves);
	ft_draw_fragment(game);
}

void	ft_move_up(t_game *game)
{
	game->player->n_sprite = 34;
	if (game->player->tile == '0' + 1 || game->player->tile == '0' + 3
		|| game->player->tile == '0' + 9 || game->player->tile == '0' + 11
		|| game->player->tile == '0' + 5 || game->player->tile == '0' + 13
		|| game->player->tile == '0' + 7)
		return (ft_draw_fragment(game));
	game->map_fragment->map[game->player->y][game->player->x]
		= game->player->tile;
	if (game->player->y - 1 < 0)
	{
		game->map_fragment = game->map_fragment->up;
		game->player->y = game->map_fragment->y - 1;
		game->player->tile
			= game->map_fragment->map[game->player->y][game->player->x];
	}
	else
	{
		game->player->y--;
		game->player->tile
			= game->map_fragment->map[game->player->y][game->player->x];
	}
	game->map_fragment->map[game->player->y][game->player->x] = 'P';
	ft_move_up_2(game);
}

void	ft_move_left_2(t_game *game)
{
	if (game->player->tile == 'c')
	{
		game->keys--;
		ft_proces_player_tile(game, game->player);
	}
	if (game->player->tile == 'e')
	{
		if (game->keys == 0)
			ft_game_win(game);
		else
		{
			ft_printf("You still need to collect %d keys\n", game->keys);
			game->count_moves--;
			ft_move_right(game);
			return ;
		}
	}
	ft_printf("Number of movements %d\n", ++game->count_moves);
	ft_draw_fragment(game);
}

void	ft_move_left(t_game *game)
{
	game->player->n_sprite = 37;
	if (game->player->tile == '0' + 9 || game->player->tile == '0' + 8
		|| game->player->tile == '0' + 13 || game->player->tile == '0' + 12
		|| game->player->tile == '0' + 10 || game->player->tile == '0' + 14
		|| game->player->tile == '0' + 11)
		return (ft_draw_fragment(game));
	game->map_fragment->map[game->player->y][game->player->x]
		= game->player->tile;
	if (game->player->x - 1 < 0)
	{
		game->map_fragment = game->map_fragment->left;
		game->player->x = game->map_fragment->x - 1;
		game->player->tile
			= game->map_fragment->map[game->player->y][game->player->x];
	}
	else
	{
		game->player->x--;
		game->player->tile
			= game->map_fragment->map[game->player->y][game->player->x];
	}
	game->map_fragment->map[game->player->y][game->player->x] = 'P';
	ft_move_left_2(game);
}

void	ft_move_down_2(t_game *game)
{
	if (game->player->tile == 'c')
	{
		game->keys--;
		ft_proces_player_tile(game, game->player);
	}
	if (game->player->tile == 'e')
	{
		if (game->keys == 0)
			ft_game_win(game);
		else
		{
			ft_printf("You still need to collect %d keys\n", game->keys);
			game->count_moves--;
			ft_move_up(game);
			return ;
		}
	}
	ft_printf("Number of movements %d\n", ++game->count_moves);
	ft_draw_fragment(game);
}
