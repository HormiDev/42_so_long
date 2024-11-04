/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_so_long.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 21:19:25 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/11/03 19:30:00 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error_so_long_2(int error)
{
	if (error == 10)
		ft_printf("The map is invalid.\n");
	if (error == 11)
		ft_printf("The map is not rectangular.\n");
	if (error == 12)
		ft_printf("The map is not closed.\n");
	if (error == 13)
		ft_printf("The map cannot be resolved.\n");
}

void	ft_error_so_long(t_game *game, int error)
{
	if (game)
		ft_game_clear(game);
	perror("\e[31mError\n\e[33m");
	if (error == 1)
		ft_printf("Memory allocation error.\n");
	else if (error == 2)
		ft_printf("Invalid arguments. Use [./so_long maps/map_name.ber].\n");
	else if (error == 3)
		ft_printf("The map file does not exist or cannot be read.\n");
	else if (error == 4)
		ft_printf("Failure to create t_file.\n");
	else if (error == 5)
		ft_printf("Maximum window size is too small.\n");
	else if (error == 6)
		ft_printf("The map needs more than two lines.\n");
	else if (error == 7)
		ft_printf("The map needs more than two columns.\n");
	else if (error == 8)
		ft_printf("The map must contain one, P one E and one or more C.\n");
	else if (error == 9)
		ft_printf("Some sprite does not exist.\n");
	else
		ft_error_so_long_2(error);
	ft_printf("\e[39m");
	exit(0);
}
