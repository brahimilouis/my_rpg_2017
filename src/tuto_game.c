/*
** EPITECH PROJECT, 2018
** rpg : tuto_game
** File description:
** play the tutorial
*/

#include "rpg.h"

int tuto_game(menu_t *menu, rpg_t *rpg)
{
	int game = 1;

	while (sfRenderWindow_isOpen(rpg->window) && game != -1 && game != 4) {
		game = event_tuto(rpg, game);
		refresh_tuto(menu, rpg, game);
	}
	if (game == 4)
		return (-2);
	return (game);
}
