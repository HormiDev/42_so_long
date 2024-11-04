/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_text.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:00:32 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/11/04 19:05:04 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_draw_text_keys(t_game *game)
{
	char	*num;
	char	*str;
	char	*tmp;

	num = ft_itoa(game->keys);
	if (!num)
		ft_error_so_long(game, 1);
	tmp = ft_strjoin("You still need to collect ", num);
	if (!tmp)
	{
		ft_error_so_long(game, 1);
		free(num);
	}
	str = ft_strjoin(tmp, " keys");
	if (!str)
	{
		ft_error_so_long(game, 1);
		free(tmp);
		free(num);
	}
	mlx_string_put(game->mlx, game->win, 10, 40, 0xffde87, str);
	free(tmp);
	free(num);
	free(str);
}

void	ft_draw_text(t_game *game)
{
	char	*str;
	char	*num;

	num = ft_itoa(game->count_moves);
	if (!num)
		ft_error_so_long(game, 1);
	str = ft_strjoin("Number of movements ", num);
	if (!str)
		ft_error_so_long(game, 1);
	mlx_string_put(game->mlx, game->win, 10, 20, 0x9dfeff, str);
	free(str);
	free(num);
	if (game->keys > 0)
		ft_draw_text_keys(game);
	else
		mlx_string_put(game->mlx, game->win, 10, 40, 0xc8ff87,
			"Go get the chest");
}
