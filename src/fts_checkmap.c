/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_checkmap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 02:14:18 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/09/25 02:15:52 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_map_is_rectangular(t_file *map)
{
	t_strlist	*tmp;
	int			x;

	tmp = map->list_content;
	x = tmp->len;
	if (x < 4)
		return (0);
	while (tmp->next)
	{
		if (tmp->len != x)
			return (0);
		tmp = tmp->next;
	}
	if (tmp->len + 1 != x)
		return (0);
	return (1);
}

int	ft_map_is_closed(t_file *map)
{
	char	**map_array;
	int		x;
	int		y;
	int		i;

	map_array = map->array_content;
	y = map->lines;
	x = ft_strlen2(map_array[y - 1]);
	i = 0;
	while (i < x)
	{
		if (map_array[0][i] != '1' || map_array[y - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < y)
	{
		if (map_array[i][0] != '1' || map_array[i][x - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

void	ft_count_epc_map(t_file *map, int *e, int *p, int *c)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->lines)
	{
		j = 0;
		while (j < map->list_content->len - 1)
		{
			if (map->array_content[i][j] == 'E')
				(*e)++;
			else if (map->array_content[i][j] == 'P')
				(*p)++;
			else if (map->array_content[i][j] == 'C')
				(*c)++;
			j++;
		}
		i++;
	}
}

int	ft_check_epc_map(t_file *map)
{
	int		e;
	int		p;
	int		c;

	e = 0;
	p = 0;
	c = 0;
	ft_count_epc_map(map, &e, &p, &c);
	if (p < 1)
		return (0);
	if (e < 1)
		return (0);
	if (c < 1)
		return (0);
	if (p > 1)
		return (0);
	if (e > 1)
		return (0);
	return (1);
}

int	ft_checkmap(t_file *map)
{
	if (!map)
		return (0);
	if (map->lines < 3)
		return (0);
	if (!ft_map_is_rectangular(map))
		return (0);
	if (!ft_map_is_closed(map))
		return (0);
	if (!ft_check_characters_map(map))
		return (0);
	if (!ft_check_epc_map(map))
		return (0);
	if (!ft_check_map_roads(map))
		return (0);
	return (1);
}
