/*
** EPITECH PROJECT, 2017
** event
** File description:
** ......
*/

#include "rpg.h"

int event_load(rpg_t *rpg, load_t *load)
{
	while (sfRenderWindow_pollEvent(rpg->window, &rpg->event)) {
		if (rpg->event.type == sfEvtClosed)
			return (-1);
		if (rpg->event.key.type == sfEvtKeyPressed)
			change_name_player(&load->text, rpg);
		if (rpg->event.key.type == sfEvtKeyPressed && sfKeyboard_is\
KeyPressed(sfKeyReturn) == 1)
			return (3);
		if (rpg->event.key.type == sfEvtKeyPressed && sfKeyboard_is\
KeyPressed(sfKeyEscape) == 1)
			return (1);
	}
	return (4);
}
