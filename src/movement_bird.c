/*
** EPITECH PROJECT, 2017
** move_bird
** File description:
** ....
*/

#include "rpg.h"

void movement_bird(menu_t *menu)
{
	menu->tempo.time = sfClock_getElapsedTime(menu->tempo.clock);
	menu->tempo.seconds = menu->tempo.time.microseconds / 35000;
	if (menu->tempo.seconds > 1.0) {
		move_rect(&menu->im[1].rect, &menu->im[1], 0, 439);
		menu->im[1].offset = menu->im[1].offset + 441;
		if (menu->im[1].offset == 441 * 9)
			menu->im[1].offset = 0;
		sfSprite_setTextureRect(menu->im[1].sprite, menu->im[1].rect);
		sfClock_restart(menu->tempo.clock);
	}
}
