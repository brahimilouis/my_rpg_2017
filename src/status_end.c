/*
** EPITECH PROJECT, 2018
** status
** File description:
** intro
*/

#include "rpg.h"

void move_black(end_t *st, int first, int second)
{
	int i;
	if (first > 0)
		i = 0;
	else
		i = 1;
	st->im[0].cord.y += first;
	st->im[1].cord.y += second;
	sfSprite_setPosition(st->im[0].sprite, st->im[0].cord);
	sfSprite_setPosition(st->im[1].sprite, st->im[1].cord);
	if (st->im[i].cord.y == -540)
		st->status++;
	if (st->im[i].cord.y == 1080)
		st->status++;
}

void status_end(end_t *st)
{
	st->tempo[1].time = sfClock_getElapsedTime(st->tempo[1].clock);
	st->tempo[1].seconds = st->tempo[1].time.microseconds / 6000;
	if (st->tempo[1].seconds > 1) {
		if (st->status == 2) {
			sfSprite_move(st->im[3].sprite, st->im[3].cord);
			st->im[3].pos.x++;
		}
		if (st->im[3].pos.x == 500 && st->status == 2)
			st->status++;
		if (st->status == 0)
			move_black(st, 3, -3);
		if (st->status == 1)
			move_black(st, -3, 3);
		if (st->status == 3)
			move_black(st, 3, -3);
		sfClock_restart(st->tempo[1].clock);
	}
}
