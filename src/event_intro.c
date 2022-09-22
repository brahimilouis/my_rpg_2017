/*
** EPITECH PROJECT, 2017
** event
** File description:
** ......
*/

#include "rpg.h"

int event_intro(rpg_t *rpg)
{
	while (sfRenderWindow_pollEvent(rpg->window, &rpg->event)) {
		if (rpg->event.type == sfEvtClosed)
			return (-1);
		if (rpg->event.key.type == sfEvtKeyPressed && \
sfKeyboard_isKeyPressed(sfKeySpace) == 1)
			return (1);
	}
	return (0);
}
