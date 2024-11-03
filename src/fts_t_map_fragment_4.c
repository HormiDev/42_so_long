/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_t_map_fragment_4.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 22:03:23 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/11/02 22:04:02 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_map_fragment_loading(t_game *game)
{
	int				x;
	int				y;

	ft_map_fragment_necesary(game, &x, &y);
	game->map_fragment = ft_map_fragment_new(game);
	if (!game->map_fragment)
		ft_error_so_long(game, 1);
	ft_map_fragment_extend(game, x, y);
	ft_map_fragment_fill_char(game, ' ');
	ft_copy_map_to_fragment(game, x, y);
	game->map_fragment = ft_map_fragment_search_player(game);
}
/*
void	ft_map_fragment_print(t_map_fragment *map_fragment)
{
	int				x;
	int				y;
	t_map_fragment	*tmp;

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
}*/
