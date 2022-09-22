/*
** EPITECH PROJECT, 2018
** my_rpg : refresh_tuto
** File description:
** refresh tuto
*/

#include "rpg.h"

void refresh_tuto(menu_t *menu, rpg_t *rpg, int game)
{
	switch (game) {
	case 1:	sfRenderWindow_drawSprite(rpg->window, menu->tuto[0].sprite, \
NULL);
		break;
	case 2:	sfRenderWindow_drawSprite(rpg->window, menu->tuto[1].sprite, \
NULL);
		break;
	case 3:	sfRenderWindow_drawSprite(rpg->window, menu->tuto[2].sprite, \
NULL);
		break;
	default: break;
	}
	sfRenderWindow_display(rpg->window);
}
