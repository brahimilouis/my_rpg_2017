/*
** EPITECH PROJECT, 2017
** monv_image
** File description:
** ....
*/

#include "rpg.h"

void move_particle_e(fight_t *st, game_t *game)
{
	st->tempo_part[1].time = sfClock_getElapsedTime\
(st->tempo_part[1].clock);
	st->tempo_part[1].seconds = st->tempo_part[1].time.microseconds / 2000;
	if (st->tempo_part[1].seconds > 1) {
		for (int i = 0; i < 99; i++)
			st->part_e[i].max.x++;
		sfClock_restart(st->tempo_part[1].clock);
	}
	for (int i = 0; i < 100; i++) {
		if (i < 99 && st->part_e[i].max.y == st->part_e[i].max.x) {
			st->part_e[i].max.x = 0;
			st->part_e[i].pos = st->part_e[99].pos;
		}
		st->part_e[i].pos.x += st->part_e[i].vect.x;
		st->part_e[i].pos.y += st->part_e[i].vect.y;
	}
	if (st->part_e[99].pos.x < 340) {
		game->player.hp -= (game->player.status + 2) * 2;
		st->display_part_e = 0;
	}
}

void improve_part(particle_t *st)
{
	if (st->verif == 1)
		st->max.x++;
}

void retire_part(fight_t *st, int nb)
{
	int j = nb + 100;

	for (int i = nb; i < j; i++) {
		st->part_p[i].pos.x = 0;
		st->part_p[i].verif = 0;
	}
}

void move_particle_p(fight_t *st)
{
	st->tempo_part[0].time = sfClock_getElapsedTime\
(st->tempo_part[0].clock);
	st->tempo_part[0].seconds = st->tempo_part[0].time.microseconds / 200;
	if (st->tempo_part[0].seconds > 0.7) {
		for (int i = 0; i < 500; i++)
			improve_part(&st->part_p[i]);
		sfClock_restart(st->tempo_part[0].clock);
	}
	for (int i = 0; i < 500; i++) {
		if (st->part_p[i].verif == 1 && \
st->part_p[i].max.y == st->part_p[i].max.x) {
			st->part_p[i].max.x = 0;
			st->part_p[i].pos = st->part_p[(i / 100) * \
100 + 99].pos;
		}
		st->part_p[i].pos.x += st->part_p[i].vect.x;
		st->part_p[i].pos.y += st->part_p[i].vect.y;
	}
	for (int j = 0; j < 5; j++)
		if (st->part_p[99 + j * 100].pos.x > 1400)
			retire_part(st, j * 100);
}
