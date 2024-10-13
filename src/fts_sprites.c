/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_sprites.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 20:50:04 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/10/13 19:45:11 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void 	*ft_new_sprite(t_game *game, char *path)
{
	void	*sprite;
	t_file 	*sprite_file;
	char 	**data_line;
	int		width;
	int		height;

	sprite_file = ft_create_file_from_filename(path);
	if (!sprite_file)
		ft_error_so_long(game, 1);
	data_line = ft_split(sprite_file->array_content[2], ' ');
	if (!data_line)
	{
		ft_file_clear(&sprite_file);
		ft_error_so_long(game, 1);
	}
	width = ft_atoi(data_line[0] + 1);
	height = ft_atoi(data_line[1]);
	ft_printf("width:%d height:%d\n", width, height);
	sprite = mlx_xpm_file_to_image(game->mlx, path, &width, &height);
	ft_file_clear(&sprite_file);
	ft_free_split(data_line);
	if (!sprite)
		ft_error_so_long(game, 1);
	return (sprite);
}

void 	ft_init_sprites(t_game *game)
{
	int	i;

	game->sprites[0] = ft_new_sprite(game, "sprites/sprite_null.xpm");
	game->sprites[1] = ft_new_sprite(game, "sprites/cesped_1.xpm");
	game->sprites[2] = ft_new_sprite(game, "sprites/muro_1.xpm");
	game->sprites[3] = ft_new_sprite(game, "sprites/jugador_1.xpm");
	i = 0;
	while (i < 4)
	{
		if (!game->sprites[i])
			ft_error_so_long(game, 0);
		i++;
	}	
}

void	ft_free_sprites(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (game->sprites[i])
			mlx_destroy_image(game->mlx, game->sprites[i]);
		i++;
	}
}