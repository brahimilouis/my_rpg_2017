/*
** EPITECH PROJECT, 2018
** init
** File description:
** end
*/

#include "rpg.h"

int init_end(end_t *st)
{
	int i = 0;

	for (int j = 0; j < 2; j++) {
		st->tempo[j].clock = sfClock_create();
		if (!st->tempo[j].clock)
			return (84);
	}
	i = init_image("png/end_intro.png", &st->im[0], i);
	i = init_image("png/end_intro.png", &st->im[1], i);
	i = init_image("png/outro 1.png", &st->im[2], i);
	i = init_image("png/outro 2.png", &st->im[3], i);
	i = init_image("png/outro 3.png", &st->im[4], i);
	i = init_image("png/outro 4.png", &st->im[5], i);
	return (i);
}
