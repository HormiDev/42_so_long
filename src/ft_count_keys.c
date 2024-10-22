/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_keys.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 01:43:11 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/10/22 01:47:37 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_count_keys(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	game->keys = 0;
	while (i < game->map->lines)
	{
		j = 0;
		while (j < game->map->list_content->len - 1)
		{
			if (game->map->array_content[i][j] == 'C')
				game->keys++;
			j++;
		}
		i++;
	}
}
