/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_t_map_fragment.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 00:24:47 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/10/03 02:37:59 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map_fragment	*ft_map_fragment_new()
{
	t_map_fragment	*map_fragment;

	map_fragment = (t_map_fragment *)malloc(sizeof(t_map_fragment));
	if (!map_fragment)
		return (0);
	map_fragment->x = MAX_WIN_WIDTH / TILE_SIZE;
	map_fragment->y = MAX_WIN_HEIGHT / TILE_SIZE;
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

void	ft_map_fragment_clear(t_map_fragment *map_fragment)
{
	if (!map_fragment)
		return ;
	if (map_fragment->right)
		map_fragment->right->left = 0;
	if (map_fragment->left)
		map_fragment->left->right = 0;
	if (map_fragment->up)
		map_fragment->up->down = 0;
	if (map_fragment->down)
		map_fragment->down->up = 0;
	if (map_fragment->right)
		{ft_printf("clear rigth\n"); ft_map_fragment_clear(map_fragment->right);}
	if (map_fragment->left)
		{ft_printf("clear left\n"); ft_map_fragment_clear(map_fragment->left);}
	if (map_fragment->up)
		{ft_printf("clear up\n"); ft_map_fragment_clear(map_fragment->up);}
	if (map_fragment->down)
		{ft_printf("clear down\n"); ft_map_fragment_clear(map_fragment->down);}
	if (map_fragment->map)
		ft_free_str_rectangular_array(map_fragment->map, map_fragment->y);
	free(map_fragment);
}

/*void	ft_map_fragment_clear(t_map_fragment *map_fragment)
{
	t_map_fragment	*tmp_left;
	t_map_fragment	*tmp_right;
	t_map_fragment	*tmp_up;
	t_map_fragment	*tmp_down;

	if (!map_fragment)
		return ;
	ft_printf("clear fragment map\n");
	tmp_left = map_fragment->left;
	if (tmp_left)
		tmp_left->right = 0;
	tmp_right = map_fragment->right;
	if (tmp_right)
		tmp_right->left = 0;
	tmp_up = map_fragment->up;
	if (tmp_up)
		tmp_up->down = 0;
	tmp_down = map_fragment->down;
	if (tmp_down)
		tmp_down->up = 0;
	if (map_fragment->map)
		ft_free_str_rectangular_array(map_fragment->map, map_fragment->y);
	free(map_fragment);
	if (tmp_left)
		{ft_printf("clear fragment map left\n"); ft_map_fragment_clear(tmp_left);}
	if (tmp_right)
		{ft_printf("clear fragment map right\n"); ft_map_fragment_clear(tmp_right);}
	if (tmp_up)
		{ft_printf("clear fragment map up\n"); ft_map_fragment_clear(tmp_up);}
	if (tmp_down)
		{ft_printf("clear fragment map down\n"); ft_map_fragment_clear(tmp_down);}
}*/

t_map_fragment *ft_map_fragment_add_right(t_map_fragment *map_fragment)
{
	t_map_fragment	*new_map_fragment;

	if (!map_fragment)
		return (0);
	new_map_fragment = ft_map_fragment_new();
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

t_map_fragment *ft_map_fragment_add_left(t_map_fragment *map_fragment)
{
	t_map_fragment	*new_map_fragment;

	if (!map_fragment)
		return (0);
	new_map_fragment = ft_map_fragment_new();
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

t_map_fragment *ft_map_fragment_add_up(t_map_fragment *map_fragment)
{
	t_map_fragment	*new_map_fragment;

	if (!map_fragment)
		return (0);
	new_map_fragment = ft_map_fragment_new();
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

t_map_fragment *ft_map_fragment_add_down(t_map_fragment *map_fragment)
{
	t_map_fragment	*new_map_fragment;

	if (!map_fragment)
		return (0);
	new_map_fragment = ft_map_fragment_new();
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
	int x_aux;
	int y_aux;
	int x_tiles;
	int y_tiles;

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

	ft_printf("%d %d\n", x, y);
	tmp_y = game->map_fragment;
	while (y > 0)
	{
		x_aux = x;
		tmp_x = tmp_y;
		while (x_aux > 1)
		{
			ft_printf("Adding right\n");
			tmp_x = ft_map_fragment_add_right(tmp_x);
			if (!tmp_x)
				ft_error_so_long(game, 1);
			x_aux--;
		}
		if (y > 1)
		{
			ft_printf("Adding down\n");
			tmp_y = ft_map_fragment_add_down(tmp_y);
			if (!tmp_y)
				ft_error_so_long(game, 1);
		}
		y--;
	}
}

void	ft_copy_map_to_fragment_line(t_game *game, t_map_fragment *tmp_y,
			int cont_map_line, int cont_fragment_line)
{
	t_map_fragment	*tmp_x;
	int				cont_map_column;
	int				n_columns;

	n_columns = game->map->list_content->len - 1;
	tmp_x = tmp_y;
	cont_map_column = 0;
	while (cont_map_column < n_columns)
	{
		if (n_columns - cont_map_column < tmp_x->x)
			tmp_x->x = n_columns - cont_map_column; //esto tiene que afectar a todos los nodos de la derecha y liberar las columnas sobrantes del array
		ft_printf("Map: %d, %d, %d, %d\n", cont_map_line, cont_map_column,
			cont_fragment_line, tmp_x->x);
		ft_strncpy(tmp_x->map[cont_fragment_line],
			&game->map->array_content[cont_map_line][cont_map_column],
			tmp_x->x);
		ft_printf("hola\n");
		cont_map_column += tmp_x->x;
		tmp_x = tmp_x->right;
	}
}

void	ft_copy_map_to_fragment(t_game *game)//arreglar
{
	t_map_fragment	*tmp_y;
	int				cont_map_line;
	int				cont_fragment_line;
	int				n_lines;

	n_lines = game->map->lines;
	tmp_y = game->map_fragment;
	cont_map_line = 0;
	while (cont_map_line < n_lines)
	{
		if (n_lines - cont_map_line < game->map_fragment->y)
			game->map_fragment->y = n_lines - cont_map_line;//esto tiene que afectar a todos los nodos de abajo y liberar las lineas sobrantes del array
		cont_fragment_line = 0;
		while (cont_fragment_line < game->map_fragment->y)
		{
			ft_copy_map_to_fragment_line(game, tmp_y, cont_map_line,
				cont_fragment_line);
			cont_fragment_line++;
			cont_map_line++;
		}
		tmp_y = tmp_y->down;
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
				write(1, &tmp->map[y][x], tmp->x);
				ft_printf(" ");
				tmp = tmp->right;
				x++;
			}
			ft_printf("\n");
			y++;
		}
		map_fragment = map_fragment->down;
	}
}

t_map_fragment	*ft_map_fragment_loading(t_game *game)
{
	int				x;
	int				y;

	ft_map_fragment_necesary(game, &x, &y);
	game->map_fragment = ft_map_fragment_new();
	if (!game->map_fragment)
		ft_error_so_long(game, 1);
	ft_printf("Map fragment created\n");
	ft_map_fragment_extend(game, x, y);
	ft_printf("Map fragment extended\n");
	ft_copy_map_to_fragment(game);
	ft_printf("Map copied to fragment\n");
	ft_map_fragment_print(game->map_fragment);
	return (game->map_fragment);
}
