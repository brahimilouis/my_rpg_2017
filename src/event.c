/*
** EPITECH PROJECT, 2017
** event
** File description:
** ......
*/

#include "rpg.h"

void my_event_key(rpg_t *rpg, game_t *st)
{
	if (rpg->event.key.type == sfEvtKeyPressed)
		movement_map(st, rpg);
	if (rpg->event.key.type == sfEvtKeyPressed && \
sfKeyboard_isKeyPressed(sfKeyM) == 1)
		st->display_map = 1;
	else if (rpg->event.key.type == sfEvtKeyReleased && \
sfKeyboard_isKeyPressed(sfKeyM) != 1)
		st->display_map = 0;
	if (rpg->event.key.type == sfEvtKeyPressed && \
sfKeyboard_isKeyPressed(sfKeyI) == 1)
		st->display_inventory = \
(st->display_inventory - 1) * -1;
	if (rpg->event.key.type == sfEvtKeyPressed &&	\
sfKeyboard_isKeyPressed(sfKeyEscape) == 1) {
		st->pause = 1;
	}
}

int event(rpg_t *rpg, game_t *st)
{
	sfVector2f pos;
	int verif = 0;

	while (sfRenderWindow_pollEvent(rpg->window, &rpg->event)) {
		if (rpg->event.type == sfEvtClosed)
			return (-1);
		my_event_key(rpg, st);
		if (rpg->event.type == sfEvtMouseButtonPressed && rpg->music \
== 1)
			sfMusic_play(rpg->song[7]);
		if (rpg->event.type == sfEvtMouseButtonPressed) {
			pos.x = rpg->event.mouseButton.x;
			pos.y = rpg->event.mouseButton.y;
			verif = 1;
		}
		for (int i = 0; verif == 1 && i < 5 && st->pause == 1; i++)
			st->button[i].click = button_is_clicked\
(&st->button[i], pos);
	}
	return (3);
}
