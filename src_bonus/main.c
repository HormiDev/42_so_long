/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 14:49:33 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/11/04 17:50:57 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	int		fd;
	t_game	*game;

	if (argc != 2)
		ft_error_so_long(0, 2);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_error_so_long(0, 3);
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 4))
		ft_error_so_long(0, 2);
	game = ft_game_loading(fd);
	if (!game)
	{
		ft_error_so_long(0, 4);
		close(fd);
		return (1);
	}
	ft_print_start_history(game);
	mlx_loop(game->mlx);
	ft_error_so_long(game, 0);
	return (0);
}
