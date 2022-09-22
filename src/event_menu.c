/*
** EPITECH PROJECT, 2017
** event
** File description:
** ......
*/

#include "rpg.h"

int event_menu(rpg_t *rpg, menu_t *menu, int i)
{
	sfVector2f pos;
	int verif = 0;

	while (sfRenderWindow_pollEvent(rpg->window, &rpg->event)) {
		if (rpg->event.type == sfEvtClosed)
			return (-1);
		if (rpg->event.type == sfEvtMouseButtonPressed && rpg->music \
== 1)
			sfMusic_play(rpg->song[7]);
		if (rpg->event.type == sfEvtMouseButtonPressed) {
			pos.x = rpg->event.mouseButton.x;
			pos.y = rpg->event.mouseButton.y;
			verif = 1;
		}
		for (int k = 0; verif == 1 && k < 5; k++)
			menu->button[k].click = button_is_clicked\
(&menu->button[k], pos);
	}
	return (i);
}
