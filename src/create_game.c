/*
** EPITECH PROJECT, 2018
** create
** File description:
** game
*/

#include "rpg.h"

int create_button_game(game_t *st)
{
	for (int i = 0; i < 5; i++) {
		st->button[i].size.x = 400;
		st->button[i].size.y = 190;
		if (i != 4) {
			st->button[i].position.y = 803;
			st->button[i].position.x = i * 470 + 60;
		} else {
			st->button[i].position.y = 421;
			st->button[i].position.x = 60;
		}
		if (init_button(&st->button[i], st->button[i].size,	\
st->button[i].position) == 84)
			return (84);
	}
	return (0);
}

void init_var_create_game(game_t *st)
{
	st->player.hp = 100;
	st->pause = 0;
	st->battle = -1;
	st->tempo[0].seconds = 0;
	st->player.tempo_move = 0;
	st->im[0].pos.x = (st->player.cord.x) * 48;
	st->im[0].pos.y = (st->player.cord.y) * 54;
	st->im[0].move = 75;
}

int create_game(game_t *st)
{
	if (create_button_game(st) == 84)
		return (84);
	init_var_create_game(st);
	st->im[0].offset = st->player.class * 432 + 216 * st->player.gender;
	move_rect(&st->im[0].rect, &st->im[0], 0, 75);
	sfSprite_setTextureRect(st->im[0].sprite, st->im[0].rect);
	sfSprite_setPosition(st->im[0].sprite, st->im[0].pos);
	st->sound = 1;
	st->display_map = 0;
	st->display_inventory = 0;
	st->im[2].offset = st->player.class * 280;
	st->im[2].move = 280 + st->player.gender;
	move_rect(&st->im[2].rect, &st->im[2], st->player.gender * 545, \
545 * (st->player.gender + 1));
	sfSprite_setTextureRect(st->im[2].sprite, st->im[2].rect);
	st->im[2].pos.x = 680;
	st->im[2].pos.y = 200;
	sfSprite_setPosition(st->im[2].sprite, st->im[2].pos);
	return (0);
}
