/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 14:49:33 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/09/21 20:42:17 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main()
{
	void *mlx;
	void *win;
	void *img;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 1920, 896, "so_long");
	
	int img_width = 128;
	int img_height = 500;
	img = mlx_xpm_file_to_image(mlx, "sprites/muro_1.xpm", &img_width, &img_height);
	
	if (!img)
	{
		mlx_destroy_window(mlx, win);
		return (0);
	}

	mlx_put_image_to_window(mlx, win, img, 0, 0);
	int x = 0;
	int y = 0;

	while (y < 896 - 128)
	{
		x = 0;
		while (x < 1920)
		{
			mlx_put_image_to_window(mlx, win, img, x, y);
			x += 128;
		}
		y += 128;
	}

	if (!mlx || !win)
		return (0);

	// Registra el manejador de eventos para el cierre de la ventana
	mlx_hook(win, 17, 0, XLowerWindow, NULL);

	// Inicia el bucle de eventos principal
	mlx_loop(mlx);
}