/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_config_controls.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 00:25:28 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/10/13 00:25:37 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_key_press(int keycode, t_game *game)
{
	if (keycode == 65307)
		ft_game_close(game);
	return (0);
}

void	ft_config_controls(t_game *game)
{
	mlx_hook(game->win, 17, 0, ft_game_close, game);
	mlx_key_hook(game->win, ft_key_press, game);
}