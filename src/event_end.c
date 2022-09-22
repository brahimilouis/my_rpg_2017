/*
** EPITECH PROJECT, 2017
** event
** File description:
** ......
*/

#include "rpg.h"

int event_end(rpg_t *rpg)
{
	while (sfRenderWindow_pollEvent(rpg->window, &rpg->event)) {
		if (rpg->event.type == sfEvtClosed)
			return (-1);
		if (rpg->event.key.type == sfEvtKeyPressed &&	\
sfKeyboard_isKeyPressed(sfKeyEscape) == 1)
			return (1);
	}
	return (5);
}
