/*
** EPITECH PROJECT, 2018
** refresh_menu
** File description:
** refresh for menu
*/

#include "rpg.h"

void refresh_menu(menu_t *menu, rpg_t *rpg)
{
	for (int i = 0; i < 2; i++)
		sfRenderWindow_drawSprite(rpg->window, \
menu->im[i].sprite, NULL);
	for (int i = 0; i < 5; i++)
		sfRenderWindow_drawRectangleShape(rpg->window, \
menu->button[i].rect, NULL);
	sfRenderWindow_display(rpg->window);
}
