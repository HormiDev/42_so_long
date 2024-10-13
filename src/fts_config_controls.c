/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_config_controls.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 00:25:28 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/10/13 23:58:07 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_up(t_game *game)
{
	game->map_fragment->map[game->player->y][game->player->x] = game->player->tile;
	if (game->player->y - 1 < 0)
	{
		game->map_fragment = game->map_fragment->up;
		game->player->y = game->map_fragment->y - 1;
		game->player->tile = game->map_fragment->map[game->player->y][game->player->x];
	}
	else
	{
		game->player->y--;
		game->player->tile = game->map_fragment->map[game->player->y][game->player->x];
	}
	game->map_fragment->map[game->player->y][game->player->x] = 'P';
	ft_draw_fragment(game);
}

void	ft_move_left(t_game *game)
{
	game->map_fragment->map[game->player->y][game->player->x] = game->player->tile;
	if (game->player->x - 1 < 0)
	{
		game->map_fragment = game->map_fragment->left;
		game->player->x = game->map_fragment->x - 1;
		game->player->tile = game->map_fragment->map[game->player->y][game->player->x];
	}
	else
	{
		game->player->x--;
		game->player->tile = game->map_fragment->map[game->player->y][game->player->x];
	}
	game->map_fragment->map[game->player->y][game->player->x] = 'P';
	ft_draw_fragment(game);
}

void	ft_move_down(t_game *game)
{
	game->map_fragment->map[game->player->y][game->player->x] = game->player->tile;
	if (game->player->y + 1 >= game->map_fragment->y)
	{
		game->map_fragment = game->map_fragment->down;
		game->player->y = 0;
		game->player->tile = game->map_fragment->map[game->player->y][game->player->x];
	}
	else
	{
		game->player->y++;
		game->player->tile = game->map_fragment->map[game->player->y][game->player->x];
	}
	game->map_fragment->map[game->player->y][game->player->x] = 'P';
	ft_draw_fragment(game);
}

void	ft_move_right(t_game *game)
{
	game->map_fragment->map[game->player->y][game->player->x] = game->player->tile;
	if (game->player->x + 1 >= game->map_fragment->x)
	{
		game->map_fragment = game->map_fragment->right;
		game->player->x = 0;
		game->player->tile = game->map_fragment->map[game->player->y][game->player->x];

	}
	else
	{
		game->player->x++;
		game->player->tile = game->map_fragment->map[game->player->y][game->player->x];
	}
	game->map_fragment->map[game->player->y][game->player->x] = 'P';
	ft_draw_fragment(game);
}

int ft_key_press(int keycode, t_game *game)
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