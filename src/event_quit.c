/*
** EPITECH PROJECT, 2017
** event
** File description:
** ......
*/

#include "rpg.h"

int event_quit(rpg_t *rpg, int i)
{
	while (sfRenderWindow_pollEvent(rpg->window, &rpg->event)) {
		if (rpg->event.type == sfEvtClosed)
			return (-1);
	}
	return (i);
}
