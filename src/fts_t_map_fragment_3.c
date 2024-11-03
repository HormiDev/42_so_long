/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_t_map_fragment_3.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 22:01:31 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/11/02 22:02:29 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
			int cm_cf_x[3])
{
	int				cont_map_column;
	int				n_columns;
	int				cont_fragment_column;

	n_columns = game->map->list_content->len - 1;
	cont_map_column = 0;
	cont_fragment_column = ((cm_cf_x[2] * game->map_fragment->x) - n_columns)
		/ 2;
	while (cont_map_column < n_columns)
	{
		tmp_x->map[cm_cf_x[1]][cont_fragment_column]
			= game->map->array_content[cm_cf_x[0]][cont_map_column];
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
	int				cm_cf_x[3];

	tmp_y = game->map_fragment;
	cont_map_line = 0;
	cont_fragment_line = ((y * game->map_fragment->y) - game->map->lines) / 2;
	while (cont_map_line < game->map->lines)
	{
		cm_cf_x[0] = cont_map_line;
		cm_cf_x[1] = cont_fragment_line;
		cm_cf_x[2] = x;
		ft_copy_map_to_fragment_line(game, tmp_y, cm_cf_x);
		cont_map_line ++;
		cont_fragment_line++;
		if (cont_fragment_line == tmp_y->y)
		{
			cont_fragment_line = 0;
			tmp_y = tmp_y->down;
		}
	}
}

void	ft_map_fragment_fill_char(t_game *game, int c)
{
	int				x;
	int				y;
	t_map_fragment	*tmpy;
	t_map_fragment	*tmpx;

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
