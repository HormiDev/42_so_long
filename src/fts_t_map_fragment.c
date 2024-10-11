/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_t_map_fragment.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 00:24:47 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/10/10 23:56:20 by ide-dieg         ###   ########.fr       */
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

t_map_fragment	*ft_map_fragment_add_right(t_map_fragment *map_fragment, t_game *game)
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

t_map_fragment	*ft_map_fragment_add_left(t_map_fragment *map_fragment, t_game *game)
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

t_map_fragment	*ft_map_fragment_add_up(t_map_fragment *map_fragment, t_game *game)
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

t_map_fragment	*ft_map_fragment_add_down(t_map_fragment *map_fragment, t_game *game)
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

void	ft_map_fragment_extend(t_game *game, int x, int y)
{
	t_map_fragment	*tmp_y;
	t_map_fragment	*tmp_x;
	int				x_aux;

	tmp_y = game->map_fragment;
	while (y > 0)
	{
		x_aux = x;
		tmp_x = tmp_y;
		while (x_aux > 1)
		{
			tmp_x = ft_map_fragment_add_right(tmp_x, game);
			if (!tmp_x)
				ft_error_so_long(game, 1);
			x_aux--;
		}
		if (y > 1)
		{
			tmp_y = ft_map_fragment_add_down(tmp_y, game);
			if (!tmp_y)
				ft_error_so_long(game, 1);
		}
		y--;
	}
}

void	ft_copy_map_to_fragment_line(t_game *game, t_map_fragment *tmp_x,
			int cont_map_line, int cont_fragment_line, int x)
{
	int				cont_map_column;
	int				n_columns;
	int				cont_fragment_column;


	n_columns = game->map->list_content->len - 1;
	cont_map_column = 0;
	cont_fragment_column = ((x * game->map_fragment->x) - n_columns) / 2;
	while (cont_map_column < n_columns)
	{
		tmp_x->map[cont_fragment_line][cont_fragment_column] =
			game->map->array_content[cont_map_line][cont_map_column];
		cont_map_column++;
		cont_fragment_column++;
		if (cont_fragment_column == tmp_x->x)
		{
			cont_fragment_column = 0;
			tmp_x = tmp_x->right;
		}
	}
}

void	ft_copy_map_to_fragment(t_game *game, int x, int y)
{
	t_map_fragment	*tmp_y;
	int				cont_map_line;
	int				cont_fragment_line;

	tmp_y = game->map_fragment;
	cont_map_line = 0;
	cont_fragment_line = ((y * game->map_fragment->y) - game->map->lines) / 2;
	ft_printf("cont_fragment_line %d\n", cont_fragment_line);
	while (cont_map_line < game->map->lines)
	{
		ft_copy_map_to_fragment_line(game, tmp_y, cont_map_line,
			cont_fragment_line, x);
		cont_map_line ++;
		cont_fragment_line++;
		if (cont_fragment_line == tmp_y->y)
		{
			cont_fragment_line = 0;
			tmp_y = tmp_y->down;
		}
	}
}

void	ft_map_fragment_print(t_map_fragment *map_fragment)
{
	int x;
	int y;
	t_map_fragment *tmp;

	if (!map_fragment)
		return ;
	while (map_fragment)
	{
		y = 0;
		while (y < map_fragment->y)
		{
			tmp = map_fragment;
			x = 0;
			while (tmp)
			{
				write(1, &tmp->map[y][0], tmp->x);
				ft_printf(" ");
				tmp = tmp->right;
				x++;
			}
			ft_printf("\n");
			y++;
		}
		tmp = map_fragment;
		while (tmp)
		{
			ft_printf("x %d  y %d	", tmp->x, tmp->y);
			tmp = tmp->right;
		}
		ft_printf("\n");
		tmp = map_fragment;
		while (tmp)
		{
			if (tmp->up != 0)
				ft_printf("u%c ", tmp->up->map[0][0]);
			else
				ft_printf("u0 ");
			if (tmp->right != 0)
				ft_printf("r%c ", tmp->right->map[0][0]);
			else
				ft_printf("r0 ");
			if (tmp->down != 0)
				ft_printf("d%c ", tmp->down->map[0][0]);
			else
				ft_printf("d0 ");
			if (tmp->left != 0)
				ft_printf("l%c	", tmp->left->map[0][0]);
			else
				ft_printf("l0	");
			tmp = tmp->right;
		}
		ft_printf("\n");
		map_fragment = map_fragment->down;
	}
}

void	ft_map_fragment_fill_char(t_game *game, int c)
{
	int x;
	int y;
	t_map_fragment *tmpy;
	t_map_fragment *tmpx;

	tmpy = game->map_fragment;
	while (tmpy)
	{
		tmpx = tmpy;
		while (tmpx)
		{
			y = 0;
			while (y < tmpx->y)
			{
				x = 0;
				while (x < tmpx->x)
					tmpx->map[y][x++] = c;
				y++;
			}
			tmpx = tmpx->right;
		}
		tmpy = tmpy->down;
	}
}

t_map_fragment	*ft_map_fragment_search_player(t_game *game)
{
	t_map_fragment	*tmp_y;
	t_map_fragment	*tmp_x;
	int				x;
	int				y;

	tmp_y = game->map_fragment;
	while (tmp_y)
	{
		tmp_x = tmp_y;
		while (tmp_x)
		{
			y = 0;
			while (y < tmp_x->y)
			{
				x = 0;
				while (x < tmp_x->x)
					if (tmp_x->map[y][x++] == 'P')
						return (tmp_x);
				y++;
			}
			tmp_x = tmp_x->right;
		}
		tmp_y = tmp_y->down;
	}
	return (0);
}

void	ft_map_fragment_loading(t_game *game)
{
	int				x;
	int				y;

	ft_map_fragment_necesary(game, &x, &y);
	game->map_fragment = ft_map_fragment_new(game);
	if (!game->map_fragment)
		ft_error_so_long(game, 1);
	ft_printf("Map fragment created\n");
	ft_map_fragment_extend(game, x, y);
	ft_printf("Map fragment extended\n");
	ft_map_fragment_fill_char(game, ' ');
	ft_printf("Map copied fill char space\n");
	ft_copy_map_to_fragment(game, x, y);
	ft_printf("Map copied to fragment\n");
	ft_map_fragment_print(game->map_fragment);
	game->map_fragment = ft_map_fragment_search_player(game);
}
