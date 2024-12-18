/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_process_char_map.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:43:43 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/12/18 18:30:24 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// arr[0] = i, arr[1] = j, arr[2] = tile_pseudo_count,
// arr[3] = tile_count, arr[4] = tile
void	ft_process_char_map_4(t_game *game, int *arr)
{
	while (arr[0] < game->map->lines)
	{
		arr[1] = 0;
		while (arr[1] < game->map->list_content->len - 1)
		{
			if (game->map->array_content[arr[0]][arr[1]] == '0')
			{
				if (arr[2] == arr[3])
				{
					game->map->array_content[arr[0]][arr[1]] = arr[4] + 16;
					arr[4] += 5;
					arr[2] = 0;
					arr[3]++;
					if (arr[3] > 4)
						arr[3] = 0;
					if (arr[4] > '0' + 11)
						arr[4] -= 12;
				}
				else
					arr[2]++;
			}
			arr[1]++;
		}
		arr[0]++;
	}
}

void	ft_process_char_map_3(t_game *game)
{
	int	i;
	int	j;
	int	arr[5];

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
	arr[2] = 0;
	arr[3] = 0;
	arr[4] = '0';
	arr[0] = 1;
	ft_process_char_map_4(game, &arr[0]);
}

void	ft_process_char_map_2(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map->lines)
	{
		j = 0;
		while (j < game->map->list_content->len - 1)
		{
			if (game->map->array_content[i][j] == '0')
			{
				if (game->map->array_content[i - 1][j] == '/')
					game->map->array_content[i][j] += 1;
				if (game->map->array_content[i][j + 1] == '/')
					game->map->array_content[i][j] += 2;
				if (game->map->array_content[i + 1][j] == '/')
					game->map->array_content[i][j] += 4;
				if (game->map->array_content[i][j - 1] == '/')
					game->map->array_content[i][j] += 8;
			}
			j++;
		}
		i++;
	}
	ft_process_char_map_3(game);
}

void	ft_process_char_map(t_game *game)
{
	int	i;
	int	j;

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
	ft_process_char_map_2(game);
}
