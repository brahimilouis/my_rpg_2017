/*
** EPITECH PROJECT, 2018
** status
** File description:
** intro
*/

#include "rpg.h"

void status_intro(intro_t *st)
{
	st->tempo[1].time = sfClock_getElapsedTime(st->tempo[1].clock);
	st->tempo[1].seconds = st->tempo[1].time.microseconds / 6000;
	if (st->tempo[1].seconds > 1500.00 && st->tempo[1].seconds <= 1550.00)
		st->status = 1;
	else if (st->tempo[1].seconds > 1550 && st->tempo[1].seconds < 2000)
		st->status = 2;
	if (st->tempo[1].seconds > 1 && (st->status == 2 || st->status == 3)) {
		sfSprite_move(st->im[8].sprite, st->im[8].pos);
		if (st->status == 3) {
			sfSprite_move(st->im[6].sprite, st->im[6].pos);
			sfSprite_move(st->im[9].sprite, st->im[9].pos);
			st->im[6].cord.x += 3;
		}
		st->im[8].cord.x++;
		if (st->im[8].cord.x >= 200) {
			st->status = 3;
			st->im[8].pos.x = 0;
		}
		sfClock_restart(st->tempo[1].clock);
	}
}
