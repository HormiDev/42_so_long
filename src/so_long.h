/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 16:24:11 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/09/21 20:40:18 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include "../42_get_next_line/get_next_line.h"

typedef struct s_sprite
{
	int	    width;
	int	    height;
	void    *img;
} t_sprite;

typedef struct s_game
{
	void		*mlx;
	int			width;
	int			height;
	void		*win;
	char		**map;
	t_sprite	*sprites;
} t_game;

t_game	*ft_init_game(void);

#endif
