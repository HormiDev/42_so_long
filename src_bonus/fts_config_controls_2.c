/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_config_controls_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 01:37:16 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/11/07 16:37:25 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_down(t_game *game)
{
	game->player->n_sprite = 36;
	if (game->player->tile == '0' + 12 || game->player->tile == '0' + 4
		|| game->player->tile == '0' + 6 || game->player->tile == '0' + 14
		|| game->player->tile == '0' + 5 || game->player->tile == '0' + 13
		|| game->player->tile == '0' + 7)
		return (ft_draw_fragment(game));
	game->map_fragment->map[game->player->y][game->player->x]
		= game->player->tile;
	if (game->player->y + 1 >= game->map_fragment->y)
	{
		game->map_fragment = game->map_fragment->down;
		game->player->y = 0;
		game->player->tile
			= game->map_fragment->map[game->player->y][game->player->x];
	}
	else
	{
		game->player->y++;
		game->player->tile
			= game->map_fragment->map[game->player->y][game->player->x];
	}
	game->map_fragment->map[game->player->y][game->player->x] = 'P';
	ft_move_down_2(game);
}

void	ft_move_right_2(t_game *game)
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
			game->count_moves--;
			ft_move_left(game);
			return ;
		}
	}
	game->count_moves++;
}

void	ft_move_right(t_game *game)
{
	game->player->n_sprite = 35;
	if (game->player->tile == '0' + 3 || game->player->tile == '0' + 2
		|| game->player->tile == '0' + 6 || game->player->tile == '0' + 7
		|| game->player->tile == '0' + 10 || game->player->tile == '0' + 14
		|| game->player->tile == '0' + 11)
		return (ft_draw_fragment(game));
	game->map_fragment->map[game->player->y][game->player->x]
		= game->player->tile;
	if (game->player->x + 1 >= game->map_fragment->x)
	{
		game->map_fragment = game->map_fragment->right;
		game->player->x = 0;
		game->player->tile
			= game->map_fragment->map[game->player->y][game->player->x];
	}
	else
	{
		game->player->x++;
		game->player->tile
			= game->map_fragment->map[game->player->y][game->player->x];
	}
	game->map_fragment->map[game->player->y][game->player->x] = 'P';
	ft_move_right_2(game);
}

int	ft_key_press(int keycode, t_game *game)
{
	if (keycode == 65307)
		ft_game_close(game);
	else if (keycode == 'w' || keycode == 'W' || keycode == 65362)
		ft_move_up(game);
	else if (keycode == 'a' || keycode == 'A' || keycode == 65361)
		ft_move_left(game);
	else if (keycode == 's' || keycode == 'S' || keycode == 65364)
		ft_move_down(game);
	else if (keycode == 'd' || keycode == 'D' || keycode == 65363)
		ft_move_right(game);
	return (0);
}

void	ft_config_controls(t_game *game)
{
	mlx_hook(game->win, 17, 0, ft_game_close, game);
	mlx_key_hook(game->win, ft_key_press, game);
}
