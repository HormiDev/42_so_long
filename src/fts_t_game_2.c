/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_t_game_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 00:05:50 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/11/03 01:38:08 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
