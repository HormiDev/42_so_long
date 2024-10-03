/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_t_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 19:40:40 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/10/01 00:12:48 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game	*ft_game_init()
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		return (0);
	game->map = 0;
	game->map_fragment = 0;
	game->mlx = 0;
	game->win_width = MAX_WIN_WIDTH;
	game->win_height = MAX_WIN_HEIGHT;
	game->win = 0;
	game->sprites = 0;
	return (game);
}

void	ft_game_clear(t_game *game)
{
	ft_file_clear(&game->map);
	if (game->mlx && game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
		mlx_destroy_display(game->mlx);
	if (game->map_fragment)
		ft_map_fragment_clear(game->map_fragment);
	free(game);
}

t_game	*ft_game_loading(int fd)
{
	t_game	*game;

	game = ft_game_init();
	if (!game)
		ft_error_so_long(0, 3);
	ft_printf("Game initialized\n");
	game->map = ft_create_file_from_fd(fd);
	if (!ft_checkmap(game->map))
		ft_error_so_long(game, 4);
	ft_printf("Map created\n");
	ft_printf("Map lines: %d\n", game->map->lines);
	game->map_fragment = ft_map_fragment_loading(game);
	if (!game->map_fragment)
	{
		ft_game_clear(game);
		return (0);
	}
	ft_printf("Map fragment created\n");
	return (game);
}
