/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_checkmap2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 02:14:44 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/12/18 17:48:39 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_characters_map(t_file *map)
{
	char	**map_array;
	int		x;
	int		y;
	int		i;
	int		j;

	map_array = map->array_content;
	y = map->lines;
	x = ft_strlen2(map_array[y - 1]);
	i = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			if (map_array[i][j] != '0' && map_array[i][j] != '1'
				&& map_array[i][j] != 'C' && map_array[i][j] != 'E'
				&& map_array[i][j] != 'P' && map_array[i][j] != 'X')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_localize_player_in_map(t_file *map, int *x, int *y)
{
	int		i;
	int		j;

	i = 0;
	while (i < map->lines)
	{
		j = 0;
		while (j < map->list_content->len - 1)
		{
			if (map->array_content[i][j] == 'P')
			{
				*x = i;
				*y = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	ft_check_roads_2(t_file *map, int x, int y)
{
	if (map->array_content[x + 1][y] == '0' ||
		map->array_content[x + 1][y] == 'C')
		map->array_content[x + 1][y] = 'P';
	else if (map->array_content[x + 1][y] == 'E')
		map->array_content[x + 1][y] = '1';
	if (map->array_content[x - 1][y] == '0' ||
		map->array_content[x - 1][y] == 'C')
		map->array_content[x - 1][y] = 'P';
	else if (map->array_content[x - 1][y] == 'E')
		map->array_content[x - 1][y] = '1';
	if (map->array_content[x][y + 1] == '0' ||
		map->array_content[x][y + 1] == 'C')
		map->array_content[x][y + 1] = 'P';
	else if (map->array_content[x][y + 1] == 'E')
		map->array_content[x][y + 1] = '1';
	if (map->array_content[x][y - 1] == '0' ||
		map->array_content[x][y - 1] == 'C')
		map->array_content[x][y - 1] = 'P';
	else if (map->array_content[x][y - 1] == 'E')
		map->array_content[x][y - 1] = '1';
	map->array_content[x][y] = '1';
}

int	ft_check_map_roads_2(t_file *map)
{
	t_file	*map_copy;
	int		epc[3];
	int		x;
	int		y;

	map_copy = ft_file_dup(map);
	if (!map_copy)
		return (0);
	epc[0] = 0;
	epc[1] = 0;
	epc[2] = 0;
	ft_count_epc_map(map_copy, &epc[0], &epc[1], &epc[2]);
	while (epc[1] != 0)
	{
		ft_localize_player_in_map(map_copy, &x, &y);
		ft_check_roads_2(map_copy, x, y);
		ft_count_epc_map(map_copy, &epc[0], &epc[1], &epc[2]);
	}
	ft_file_clear(&map_copy);
	if (epc[0] != 0 || epc[1] != 0 || epc[2] != 0)
		return (0);
	return (1);
}
