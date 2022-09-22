/*
** EPITECH PROJECT, 2018
** movement
** File description:
** player
*/

#include "rpg.h"

void movement_horizontal(game_t *st, int move, int top)
{
	int pos_offset = st->player.class * 432 + 216 * st->player.gender;

	st->tempo[0].time = sfClock_getElapsedTime(st->tempo[0].clock);
	st->tempo[0].seconds = st->tempo[0].time.microseconds / 10000;
	if (st->tempo[0].seconds > 1.0) {
		st->player.tempo_move++;
		st->im[0].pos.x += 8 * move;
		if (st->player.tempo_move == 3) {
			move_rect(&st->im[0].rect, &st->im[0], top, 75);
			st->im[0].offset = st->im[0].offset + 72;
			sfSprite_setTextureRect(st->im[0].sprite, \
st->im[0].rect);
			st->player.tempo_move = 0;
		}
		if (st->im[0].offset == pos_offset + 72 * 3)
			st->im[0].offset = pos_offset;
		sfSprite_setPosition(st->im[0].sprite, st->im[0].pos);
		sfClock_restart(st->tempo[0].clock);
	}
	if (st->im[0].pos.x == (st->player.cord.x) * 48)
		st->player.move = 0;
}

void movement_vertical(game_t *st, int move, int top)
{
	int pos_offset = st->player.class * 432 + 216 * st->player.gender;

	st->tempo[0].time = sfClock_getElapsedTime(st->tempo[0].clock);
	st->tempo[0].seconds = st->tempo[0].time.microseconds / 10000;
	if (st->tempo[0].seconds > 1.0) {
		st->player.tempo_move++;
		st->im[0].pos.y += 6 * move;
		if (st->player.tempo_move == 3) {
			move_rect(&st->im[0].rect, &st->im[0], top, 75);
			st->im[0].offset = st->im[0].offset + 72;
			sfSprite_setTextureRect(st->im[0].sprite, \
st->im[0].rect);
			st->player.tempo_move = 0;
		}
		if (st->im[0].offset == pos_offset + 72 * 3)
			st->im[0].offset = pos_offset;
		sfSprite_setPosition(st->im[0].sprite, st->im[0].pos);
		sfClock_restart(st->tempo[0].clock);
	}
	if (st->im[0].pos.y == (st->player.cord.y) * 54)
		st->player.move = 0;
}

void movement_player_map(game_t *st)
{
	st->im[0].pos.x = (st->player.cord.x) * 48;
	st->im[0].pos.y = (st->player.cord.y) * 54;
	sfSprite_setPosition(st->im[0].sprite, st->im[0].pos);
	st->player.move = 0;
}

void movement_player(game_t *st)
{
	if (st->player.move == 1)
		movement_horizontal(st, 1, 150);
	if (st->player.move == 2)
		movement_horizontal(st, -1, 75);
	if (st->player.move == 3)
		movement_vertical(st, 1, 0);
	if (st->player.move == 4)
		movement_vertical(st, -1, 225);
	if (st->player.move == 5)
		movement_player_map(st);
}

void check_move(rpg_t *rpg, game_t *st)
{
	if (st->player.move != 0)
		return;
	if (rpg->event.key.type == sfEvtKeyPressed)
		movement_map(st, rpg);
}
