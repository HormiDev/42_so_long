/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_sprites.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 20:50:04 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/11/02 23:43:47 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_new_sprite(t_game *game, char *path)
{
	void	*sprite;
	t_file	*sprite_file;
	char	**data_line;
	int		width;
	int		height;

	sprite_file = ft_create_file_from_filename(path);
	if (!sprite_file)
		ft_error_so_long(game, 9);
	data_line = ft_split(sprite_file->array_content[2], ' ');
	if (!data_line)
	{
		ft_file_clear(&sprite_file);
		ft_error_so_long(game, 1);
	}
	width = ft_atoi(data_line[0] + 1);
	height = ft_atoi(data_line[1]);
	sprite = mlx_xpm_file_to_image(game->mlx, path, &width, &height);
	ft_file_clear(&sprite_file);
	ft_free_split(data_line);
	if (!sprite)
		ft_error_so_long(game, 1);
	return (sprite);
}

void	ft_init_sprites_2(t_game *game)
{
	game->sprites[13] = ft_new_sprite(game, "sprites/cesped_10.xpm");
	game->sprites[14] = ft_new_sprite(game, "sprites/cesped_11.xpm");
	game->sprites[15] = ft_new_sprite(game, "sprites/cesped_12.xpm");
	game->sprites[16] = ft_new_sprite(game, "sprites/cesped_13.xpm");
	game->sprites[17] = ft_new_sprite(game, "sprites/cesped_14.xpm");
	game->sprites[18] = ft_new_sprite(game, "sprites/cesped_15.xpm");
	game->sprites[19] = ft_new_sprite(game, "sprites/cesped_16.xpm");
	game->sprites[20] = ft_new_sprite(game, "sprites/cesped_17.xpm");
	game->sprites[21] = ft_new_sprite(game, "sprites/cesped_18.xpm");
	game->sprites[22] = ft_new_sprite(game, "sprites/cesped_19.xpm");
	game->sprites[23] = ft_new_sprite(game, "sprites/cesped_20.xpm");
	game->sprites[24] = ft_new_sprite(game, "sprites/cesped_21.xpm");
	game->sprites[25] = ft_new_sprite(game, "sprites/cesped_22.xpm");
	game->sprites[26] = ft_new_sprite(game, "sprites/cesped_23.xpm");
	game->sprites[27] = ft_new_sprite(game, "sprites/cesped_24.xpm");
	game->sprites[28] = ft_new_sprite(game, "sprites/cesped_25.xpm");
	game->sprites[29] = ft_new_sprite(game, "sprites/cesped_26.xpm");
	game->sprites[30] = ft_new_sprite(game, "sprites/cesped_27.xpm");
	game->sprites[31] = ft_new_sprite(game, "sprites/cofre_cerrado.xpm");
	game->sprites[32] = ft_new_sprite(game, "sprites/cofre_abierto.xpm");
	game->sprites[33] = ft_new_sprite(game, "sprites/key.xpm");
	game->sprites[34] = ft_new_sprite(game, "sprites/jugador_arriba_0.xpm");
	game->sprites[35] = ft_new_sprite(game, "sprites/jugador_derecha_0.xpm");
	game->sprites[36] = ft_new_sprite(game, "sprites/jugador_abajo_0.xpm");
	game->sprites[37] = ft_new_sprite(game, "sprites/jugador_izquierda_0.xpm");
}

void	ft_init_sprites(t_game *game)
{
	int	i;

	game->sprites[0] = ft_new_sprite(game, "sprites/sprite_null.xpm");
	game->sprites[1] = ft_new_sprite(game, "sprites/muro_0.xpm");
	game->sprites[2] = ft_new_sprite(game, "sprites/muro_1.xpm");
	game->sprites[3] = ft_new_sprite(game, "sprites/cesped_0.xpm");
	game->sprites[4] = ft_new_sprite(game, "sprites/cesped_1.xpm");
	game->sprites[5] = ft_new_sprite(game, "sprites/cesped_2.xpm");
	game->sprites[6] = ft_new_sprite(game, "sprites/cesped_3.xpm");
	game->sprites[7] = ft_new_sprite(game, "sprites/cesped_4.xpm");
	game->sprites[8] = ft_new_sprite(game, "sprites/cesped_5.xpm");
	game->sprites[9] = ft_new_sprite(game, "sprites/cesped_6.xpm");
	game->sprites[10] = ft_new_sprite(game, "sprites/cesped_7.xpm");
	game->sprites[11] = ft_new_sprite(game, "sprites/cesped_8.xpm");
	game->sprites[12] = ft_new_sprite(game, "sprites/cesped_9.xpm");
	ft_init_sprites_2(game);
	i = 0;
	while (i < 38)
	{
		if (!game->sprites[i])
			ft_error_so_long(game, 9);
		i++;
	}
}

void	ft_free_sprites(t_game *game)
{
	int	i;

	i = 0;
	while (i < 38)
	{
		if (game->sprites[i])
			mlx_destroy_image(game->mlx, game->sprites[i]);
		i++;
	}
}
