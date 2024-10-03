/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_so_long.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 21:19:25 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/09/29 01:09:57 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error_so_long(t_game *game, int error)
{
	if (game)
		ft_game_clear(game);
	ft_printf("Error\n");
	if (error == 0)
		ft_printf("Unregistered error.\n");
	else if (error == 1)
		ft_printf("Memory allocation error.\n");
	else if (error == 2)
		ft_printf("Missing map argument or there are too many arguments.\n");
	else if (error == 3)
		ft_printf("The map file does not exist or cannot be read.\n");
	else if (error == 4)
		ft_printf("Failure to create t_file.\n");
	else if (error == 5)
		ft_printf("The map needs more than two lines.\n");
	exit(0);
}
	