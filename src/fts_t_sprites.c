/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_t_sprites.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 19:42:38 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/09/21 20:43:32 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

t_sprite	*init_sprites(t_game *game)
{
	t_sprite	*sprites;

	sprites = (t_sprite *)malloc(sizeof(t_sprite));
	if (!sprites)
		return (NULL);
	sprites->width = 128;
	sprites->height = 128;
	sprites->img = mlx_xpm_file_to_image(game->mlx, "sprites/cesped_1.xpm", sprites->width, sprites->height);
	return (sprites);
}