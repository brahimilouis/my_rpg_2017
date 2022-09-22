/*
** EPITECH PROJECT, 2018
** move_bg_intro
** File description:
** ....
*/

#include "rpg.h"

void move_background_intro(intro_t *intro)
{
	intro->tempo[0].time = sfClock_getElapsedTime(intro->tempo[0].clock);
	intro->tempo[0].seconds = intro->tempo[0].time.microseconds / 100;
	for (int i = 0; i < 3 && intro->tempo[0].seconds > 0.1; i++) {
		if (intro->im[i].cord.x >= 3840) {
			intro->im[i].cord.x = 0;
			intro->im[i].pos.x = 3840;
			sfSprite_move(intro->im[i].sprite, intro->im[i].pos);
			intro->im[i].pos.x = -(i + 1);
		} else {
			sfSprite_move(intro->im[i].sprite, intro->im[i].pos);
			intro->im[i].cord.x += (i + 1);
		}
		if (i == 2)
			sfClock_restart(intro->tempo[0].clock);
	}
}
