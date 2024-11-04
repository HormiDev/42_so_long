/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_t_map_fragment_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 21:44:12 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/11/02 22:01:24 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map_fragment	*ft_map_fragment_add_right(t_map_fragment *map_fragment,
					t_game *game)
{
	t_map_fragment	*new_map_fragment;

	if (!map_fragment)
		return (0);
	new_map_fragment = ft_map_fragment_new(game);
	if (!new_map_fragment)
		return (0);
	map_fragment->right = new_map_fragment;
	new_map_fragment->left = map_fragment;
	if (map_fragment->up && map_fragment->up->right)
	{
		map_fragment->up->right->down = new_map_fragment;
		new_map_fragment->up = map_fragment->up->right;
	}
	if (map_fragment->down && map_fragment->down->right)
	{
		map_fragment->down->right->up = new_map_fragment;
		new_map_fragment->down = map_fragment->down->right;
	}
	return (new_map_fragment);
}

t_map_fragment	*ft_map_fragment_add_left(t_map_fragment *map_fragment,
					t_game *game)
{
	t_map_fragment	*new_map_fragment;

	if (!map_fragment)
		return (0);
	new_map_fragment = ft_map_fragment_new(game);
	if (!new_map_fragment)
		return (0);
	map_fragment->left = new_map_fragment;
	new_map_fragment->right = map_fragment;
	if (map_fragment->up && map_fragment->up->left)
	{
		map_fragment->up->left->down = new_map_fragment;
		new_map_fragment->up = map_fragment->up->left;
	}
	if (map_fragment->down && map_fragment->down->left)
	{
		map_fragment->down->left->up = new_map_fragment;
		new_map_fragment->down = map_fragment->down->left;
	}
	return (new_map_fragment);
}

t_map_fragment	*ft_map_fragment_add_up(t_map_fragment *map_fragment,
					t_game *game)
{
	t_map_fragment	*new_map_fragment;

	if (!map_fragment)
		return (0);
	new_map_fragment = ft_map_fragment_new(game);
	if (!new_map_fragment)
		return (0);
	map_fragment->up = new_map_fragment;
	new_map_fragment->down = map_fragment;
	if (map_fragment->left && map_fragment->left->up)
	{
		map_fragment->left->up->right = new_map_fragment;
		new_map_fragment->left = map_fragment->left->up;
	}
	if (map_fragment->right && map_fragment->right->up)
	{
		map_fragment->right->up->left = new_map_fragment;
		new_map_fragment->right = map_fragment->right->up;
	}
	return (new_map_fragment);
}

t_map_fragment	*ft_map_fragment_add_down(t_map_fragment *map_fragment,
					t_game *game)
{
	t_map_fragment	*new_map_fragment;

	if (!map_fragment)
		return (0);
	new_map_fragment = ft_map_fragment_new(game);
	if (!new_map_fragment)
		return (0);
	map_fragment->down = new_map_fragment;
	new_map_fragment->up = map_fragment;
	if (map_fragment->left && map_fragment->left->down)
	{
		map_fragment->left->down->right = new_map_fragment;
		new_map_fragment->left = map_fragment->left->down;
	}
	if (map_fragment->right && map_fragment->right->down)
	{
		map_fragment->right->down->left = new_map_fragment;
		new_map_fragment->right = map_fragment->right->down;
	}
	return (new_map_fragment);
}

void	ft_map_fragment_necesary(t_game *game, int *x, int *y)
{
	int	x_aux;
	int	y_aux;
	int	x_tiles;
	int	y_tiles;

	*x = 1;
	*y = 1;
	x_aux = MAX_WIN_WIDTH / TILE_SIZE;
	y_aux = MAX_WIN_HEIGHT / TILE_SIZE;
	x_tiles = game->map->list_content->len - 1;
	y_tiles = game->map->lines;
	while (x_tiles > x_aux)
	{
		x_tiles -= x_aux;
		(*x)++;
	}
	while (y_tiles > y_aux)
	{
		y_tiles -= y_aux;
		(*y)++;
	}
}
