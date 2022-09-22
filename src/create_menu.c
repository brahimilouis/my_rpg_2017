/*
** EPITECH PROJECT, 2018
** create_intro
** File description:
** intro
*/

#include "rpg.h"

int create_menu(menu_t *menu)
{
	menu->tempo.seconds = 0;
	menu->im[1].pos.x = 700;
	menu->im[1].pos.y = 300;
	menu->im[1].move = 441;
	sfSprite_setPosition(menu->im[1].sprite, menu->im[1].pos);
	menu->im[1].offset = 0;
	for (int i = 0; i < 5; i++) {
		menu->button[i].size.x = 410;
		menu->button[i].size.y = 200;
		menu->button[i].position.y = 790;
		menu->button[i].position.x = i * 470 + 60;
		if (i == 4) {
			menu->button[i].position.y = 560;
			menu->button[i].position.x = 60;
		}
		if (init_button(&menu->button[i], menu->button[i].size, \
menu->button[i].position) == 84)
			return (84);
	}
	return (0);
}
