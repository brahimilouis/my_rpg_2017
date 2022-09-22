/*
** EPITECH PROJECT, 2018
** movement_map
** File description:
** map
*/

#include "rpg.h"

int check_changement_map(game_t *st, int y, int x)
{
	if (y == -1) {
		st->player.cord.y = 18;
		st->player.map.y--;
		return (1);
	} else if (y == 19) {
		st->player.map.y++;
		st->player.cord.y = 0;
		return (1);
	}
	if (x == -1) {
		st->player.cord.x = 38;
		st->player.map.x--;
		return (1);
	} else if (x == 39) {
		st->player.cord.x = 0;
		st->player.map.x++;
		return (1);
	}
	return (0);
}

void change_map_home(game_t *st)
{
	if (st->player.map.x == 2) {
		st->player.map.x = 3;
		st->player.cord.x = 14;
		st->player.cord.y = 17;
	} else {
		st->player.map.x = 2;
		st->player.cord.x = 32;
		st->player.cord.y = 10;
	}
	st->player.move = 5;
}

void check_movement_player(game_t *st, int yy, int xx, rpg_t *rpg)
{
	if (xx == 1)
		st->player.move = 1;
	if (xx == -1)
		st->player.move = 2;
	if (yy == 1)
		st->player.move = 3;
	if (yy == -1)
		st->player.move = 4;
	st->player.cord.x += xx;
	st->player.cord.y += yy;
	if (rpg->music == 1)
		sfMusic_play(rpg->song[2]);
}

void check_pos(game_t *st, int yy, int xx, rpg_t *rpg)
{
	int map = pt_map(st->player.map);
	int x = st->player.cord.x;
	int y = st->player.cord.y;

	if (check_changement_map(st, yy + y, xx + x) == 1) {
		st->player.move = 5;
		if (rpg->music == 1)
			sfMusic_play(rpg->song[2]);
		return;
	}
	if (st->map[map][y + yy][x + xx] == 'm')
		change_map_home(st);
	if (st->map[map][y + yy][x + xx] == '0')
		check_movement_player(st, yy, xx, rpg);
	else if (st->map[map][y + yy][x + xx] > '1' && \
st->map[map][y + yy][x + xx] < '8')
		st->battle = st->map[map][y + yy][x + xx] - '2';
	if (st->map[map][y + yy][x + xx] == '-')
		st->talk = 1;
	else
		st->talk = 2;
}

void movement_map(game_t *st, rpg_t *rpg)
{
	if (st->player.move != 0 || st->display_map == 1)
		return;
	switch (rpg->event.key.code) {
	case sfKeyRight :
		check_pos(st, 0, 1, rpg); break;
	case sfKeyUp :
		check_pos(st, -1, 0, rpg); break;
	case sfKeyDown :
		check_pos(st, 1, 0, rpg); break;
	case sfKeyLeft:
		check_pos(st, 0, -1, rpg); break;
	default: break;
	}
}
