/*
** EPITECH PROJECT, 2018
** check_button_pause
** File description:
** check
*/

#include "rpg.h"

int check_button_pause(game_t *st, rpg_t *rpg)
{
	int game = 3;

	if (st->button[0].click == 1)
		game = 6;
	if (st->button[1].click == 1)
		game = 1;
	if (st->button[2].click == 1)
		st->pause = 0;
	if (st->button[3].click == 1)
		game = -1;
	if (st->button[4].click == 1 && rpg->music == 1) {
		sfMusic_pause(rpg->song[5]);
		rpg->music = 0;
	} else if (st->button[4].click == 1) {
		sfMusic_play(rpg->song[5]);
		sfMusic_setLoop(rpg->song[5], sfTrue);
		rpg->music = 1;
	}
	for (int i = 0; i < 5; i++)
		st->button[i].click = 0;
	return (game);
}
