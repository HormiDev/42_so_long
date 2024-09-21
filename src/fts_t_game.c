/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_t_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 19:40:40 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/09/21 20:12:04 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

t_game	*ft_init_game(void)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	game->mlx = mlx_init();
	mlx_hook(game->mlx, 17, 0, XLowerWindow, NULL);
	game->width = 1920;
	game->height = 896;
	game->win = mlx_new_window(game->mlx, game->width, game->height, "so_long");
	game->map = NULL;
	game->sprites = malloc(sizeof(t_sprite));
	return (game);
}