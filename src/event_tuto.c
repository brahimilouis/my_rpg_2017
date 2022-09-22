/*
** EPITECH PROJECT, 2018
** my_rpg : event_tuto
** File description:
** event loop for tuto
*/

#include "rpg.h"

int event_tuto(rpg_t *rpg, int game)
{
	while (sfRenderWindow_pollEvent(rpg->window, &rpg->event)) {
		if (rpg->event.type == sfEvtClosed)
			return (-1);
		if (rpg->event.key.type == sfEvtKeyPressed && \
sfKeyboard_isKeyPressed(sfKeySpace) == 1)
			return (game + 1);
	}
	return (game);
}
