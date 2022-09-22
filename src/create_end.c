/*
** EPITECH PROJECT, 2018
** create_intro
** File description:
** intro
*/

#include "rpg.h"

void create_end(end_t *st)
{
	for (int i = 0; i < 6; i++) {
		st->im[i].cord.x = 0;
		st->im[i].cord.y = 0;
	}
	for (int i = 0; i < 2; i++) {
		st->tempo[i].seconds = 0;
	}
	st->im[0].cord.y = -1080;
	st->im[1].cord.y = 1080;
	st->im[3].cord.x = -1;
	st->im[3].cord.y = 0.5;
	st->im[3].pos.x = 0;
	sfSprite_setPosition(st->im[0].sprite, st->im[0].cord);
	sfSprite_setPosition(st->im[1].sprite, st->im[1].cord);
	st->status = 0;
	sfClock_restart(st->tempo[1].clock);
}
