/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_history.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 23:09:15 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/12/18 19:36:15 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_print_start_history_es(t_game *game)
{
	ft_printf("\033[0m");
	ft_printf("-----------------------------ES----------------------------\n");
	ft_printf("\n");
	ft_printf("\033[0;33mBienvenid@ Valiente Explorador/a!\n\n");
	ft_printf("Estás a punto de embarcarte en una travesía épica en busca de ");
	ft_printf("las legendarias Llaves de la Fortuna. Estas llaves, ");
	ft_printf("escondidas en lo más profundo de la selva, son la clave ");
	ft_printf("para abrir el antiguo cofre del tesoro, lleno de riquezas ");
	ft_printf("inimaginables.\n\n");
	ft_printf("Para moverte por este mundo misterioso, puedes usar:\n\n");
	ft_printf("\033[0m  W                 ↑\n");
	ft_printf("A S D      \033[0;33mo\033[0m      ← ↓ →\n\n\033[0;33m");
	ft_printf("Explora cada rincón, resuelve enigmas y sortea peligros ");
	ft_printf("mientras buscas las \033[0m%d\033[0;33m llaves.", game->keys);
	ft_printf("\n\n");
	ft_printf("Tu valentía y astucia te guiarán en esta aventura inolvidable.");
	ft_printf("\n¡Buena suerte, explorador/a!\n");
	ft_printf("¡Que la suerte te acompañe!\n\n\033[0m");
}

void	ft_print_start_history(t_game *game)
{
	ft_printf("\033[0m");
	ft_printf("-----------------------------EN----------------------------\n");
	ft_printf("\n");
	ft_printf("\033[0;33mWelcome, Brave Explorer!\n\n");
	ft_printf("You are about to embark on an epic journey in search of ");
	ft_printf("the legendary Keys of Fortune. These keys, ");
	ft_printf("hidden deep within the jungle, are the key ");
	ft_printf("to opening the ancient treasure chest, filled with ");
	ft_printf("unimaginable riches.\n\n");
	ft_printf("To move around this mysterious world, you can use:\n\n");
	ft_printf("\033[0m  W                  ↑\n");
	ft_printf("A S D      \033[0;33mor\033[0m      ← ↓ →\n\n\033[0;33m");
	ft_printf("Explore every corner, solve puzzles, and avoid dangers ");
	ft_printf("while you search for the \033[0m%d\033[0;33m ", game->keys);
	ft_printf("keys.\n\n");
	ft_printf("Your courage and cunning will guide you in this unforgettable ");
	ft_printf("adventure.\n");
	ft_printf("Good luck, explorer!\n");
	ft_printf("May luck be with you! \n\n\033[0m");
	ft_print_start_history_es(game);
}

void	ft_print_victory_message_es(t_game *game)
{
	ft_printf("\033[0m");
	ft_printf("-----------------------------ES----------------------------\n");
	ft_printf("\n");
	ft_printf("\033[0;33m¡Felicidades, Valiente Explorador/a!\n\n");
	ft_printf("En tan solo \033[0m%d\033[0;33m ", game->count_moves);
	ft_printf("movimientos,\n");
	ft_printf("Has encontrado las legendarias Llaves de la Fortuna\n");
	ft_printf("y abierto el antiguo cofre del tesoro.\n\n");
	ft_printf("Tu coraje y astucia te han llevado a la victoria en esta ");
	ft_printf("gran aventura.\n");
	ft_printf("¡Disfruta de tus riquezas y logros!\n\n");
	ft_printf("Gracias por jugar, explorador/a. ¡Hasta la próxima!\n");
	ft_printf("\n\033[0m");
}

void	ft_print_victory_message(t_game *game)
{
	ft_printf("\033[0m");
	ft_printf("-----------------------------EN----------------------------\n");
	ft_printf("\n");
	ft_printf("\033[0;33mCongratulations, Brave Explorer!\n\n");
	ft_printf("In just \033[0m%d\033[0;33m moves, \n", game->count_moves);
	ft_printf("You have found the legendary Keys of Fortune\n");
	ft_printf("and unlocked the ancient treasure chest.\n\n");
	ft_printf("Your courage and cunning have led you to victory in this\n");
	ft_printf("great adventure.\n");
	ft_printf("Enjoy your riches and achievements!\n\n");
	ft_printf("Thank you for playing, explorer. Until next time!\n");
	ft_printf("\n\n\033[0m");
	ft_print_victory_message_es(game);
}

void	ft_print_dead_message(void)
{
	ft_printf("\033[0m");
	ft_printf("-----------------------------en----------------------------\n");
	ft_printf("\n\033[0;33m");
	ft_printf("Oh noooo! The skeleton has impaled you with a spear.\n");
	ft_printf("Darkness embraces you. Until next time, brave adventurer.");
	ft_printf("\033[0m");
	ft_printf("\n\n");
	ft_printf("-----------------------------es----------------------------\n");
	ft_printf("\n\033[0;33m");
	ft_printf("¡Oh noooo! El esqueleto te ha reventado de un lanzazo.\n");
	ft_printf("La oscuridad te recibe. Hasta la próxima, valiente aventurer@.");
	ft_printf("\n\033[0m");
}
