/*
** EPITECH PROJECT, 2018
** change_map
** File description:
** with_save
*/

#include "rpg.h"

int change_map_with_save(game_t *st)
{
	st->map = get_maps();
	if (st->map == NULL)
		return (84);
	st->map[24] = NULL;
	if (st->player.status > 0)
		maj_map(st, st->map[21], 21);
	if (st->player.status > 1)
		maj_map(st, st->map[10], 10);
	if (st->player.status > 2)
		maj_map(st, st->map[7], 7);
	if (st->player.status > 3)
		maj_map(st, st->map[13], 13);
	if (st->player.status > 4)
		maj_map(st, st->map[8], 8);
	if (st->player.status > 5)
		maj_map(st, st->map[4], 4);
	return (3);
}
