/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_t_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 19:40:40 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/10/24 00:39:33 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game	*ft_game_init()
{
	t_game	*game;

	game = ft_calloc(1, sizeof(t_game));
	if (!game)
		return (0);
	game->win_width = MAX_WIN_WIDTH;
	game->win_height = MAX_WIN_HEIGHT;
	return (game);
}

void	ft_game_clear(t_game *game)
{
	if (!game)
		return ;
	if (game->map)
		ft_file_clear(&game->map);
	if (game->mlx && game->win)
		mlx_destroy_window(game->mlx, game->win);
	ft_free_sprites(game);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	if (game->map_fragment)
		ft_map_fragment_clear(game->map_fragment);
	if (game->player)
		free(game->player);
	free(game);
}

t_game	*ft_game_loading(int fd)
{
	t_game	*game;

	game = ft_game_init();
	if (!game)
	{
		close(fd);
		ft_error_so_long(0, 3);
	}
	game->map = ft_create_file_from_fd(fd);
	close(fd);
	if (!ft_checkmap(game->map))
		ft_error_so_long(game, 4);
	ft_count_keys(game);
	ft_process_char_map(game);
	ft_window_size(game);
	ft_map_fragment_loading(game);
	if (!game->map_fragment)
		ft_error_so_long(game, 0);
	game->mlx = mlx_init();
	if (!game->mlx)
		ft_error_so_long(game, 1);
	ft_init_window(game);
	ft_init_sprites(game);
	game->player = ft_player_config(game);
	ft_config_controls(game);
	ft_draw_fragment(game);
	return (game);
}

int	ft_game_close(void *param)
{
	t_game	*game;

    game = (t_game *)param;
	if (game)
		ft_game_clear(game);
	ft_printf("\e[31mThe game has been closed.\n\e[0m");
	exit(0);
	return (0);
}

void	ft_game_win(t_game *game)
{
	if (game)
	{
		ft_printf("Number of movements %d\n", ++game->count_moves);
		ft_print_victory_message(game);
		ft_game_clear(game);
	}
	exit(0);
}