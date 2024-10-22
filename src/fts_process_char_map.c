/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_process_char_map.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:43:43 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/10/21 12:44:20 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_process_char_map(t_game *game)
{
	int		i;
	int		j;
	
	i = 0;
	while (i < game->map->lines)
	{
		j = 0;
		while (j < game->map->list_content->len - 1)
		{
			if (game->map->array_content[i][j] == '1')
				game->map->array_content[i][j] = '/';
			if (game->map->array_content[i][j] == 'C')
				game->map->array_content[i][j] = 'c';
			if (game->map->array_content[i][j] == 'E')
				game->map->array_content[i][j] = 'e';
			j++;
		}
		i++;
	}
	i = 0;
	while (i < game->map->lines)
	{
		j = 0;
		while (j < game->map->list_content->len - 1)
		{
			if (game->map->array_content[i][j] == '0')
			{
				if (game->map->array_content[i - 1][j] == '/')
					game->map->array_content[i][j]+= 1;
				if (game->map->array_content[i][j + 1] == '/')
					game->map->array_content[i][j]+= 2;	
				if (game->map->array_content[i + 1][j] == '/')
					game->map->array_content[i][j]+= 4;
				if (game->map->array_content[i][j - 1] == '/')
					game->map->array_content[i][j]+= 8;
			}
			j++;
		}
		i++;
	}
	i = 1;
	while (i < game->map->lines)
	{
		j = 0;
		while (j < game->map->list_content->len - 1)
		{
			if (game->map->array_content[i][j] == '/' &&
					game->map->array_content[i - 1][j] != '/' &&
					game->map->array_content[i - 1][j] != '.')
				game->map->array_content[i][j] = '.';

			j++;
		}
		i++;
	}
}
