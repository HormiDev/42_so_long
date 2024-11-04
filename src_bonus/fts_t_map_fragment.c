/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_t_map_fragment.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 00:24:47 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/11/02 22:03:45 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map_fragment	*ft_map_fragment_new(t_game *game)
{
	t_map_fragment	*map_fragment;

	map_fragment = (t_map_fragment *)malloc(sizeof(t_map_fragment));
	if (!map_fragment)
		ft_error_so_long(game, 1);
	map_fragment->x = game->win_width / TILE_SIZE;
	map_fragment->y = game->win_height / TILE_SIZE;
	map_fragment->map = ft_create_str_rectangular_array
		(map_fragment->x, map_fragment->y);
	if (!map_fragment->map)
	{
		free(map_fragment);
		return (0);
	}
	map_fragment->left = 0;
	map_fragment->right = 0;
	map_fragment->up = 0;
	map_fragment->down = 0;
	return (map_fragment);
}

t_map_fragment	*ft_map_fragment_top_left_corner(t_map_fragment *map_fragment)
{
	if (!map_fragment)
		return (0);
	while (map_fragment->left)
		map_fragment = map_fragment->left;
	while (map_fragment->up)
		map_fragment = map_fragment->up;
	return (map_fragment);
}

void	ft_map_fragment_clear_column(t_map_fragment *map_fragment)
{
	if (!map_fragment)
		return ;
	if (map_fragment->down)
		ft_map_fragment_clear_column(map_fragment->down);
	if (map_fragment->map)
		ft_free_str_rectangular_array(map_fragment->map, map_fragment->y);
	free(map_fragment);
}

void	ft_map_fragment_clear_top_row(t_map_fragment *map_fragment)
{
	if (!map_fragment)
		return ;
	if (map_fragment->down)
		ft_map_fragment_clear_column(map_fragment->down);
	if (map_fragment->right)
		ft_map_fragment_clear_top_row(map_fragment->right);
	if (map_fragment->map)
		ft_free_str_rectangular_array(map_fragment->map, map_fragment->y);
	free(map_fragment);
}

void	ft_map_fragment_clear(t_map_fragment *map_fragment)
{
	if (!map_fragment)
		return ;
	map_fragment = ft_map_fragment_top_left_corner(map_fragment);
	ft_map_fragment_clear_top_row(map_fragment);
}
