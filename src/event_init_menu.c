/*
** EPITECH PROJECT, 2017
** event
** File description:
** ......
*/

#include "rpg.h"

void change_name_player(text_t *text, rpg_t *rpg)
{
	char c = found_letter(rpg);
	int size = 0;

	if (c == '\0' || (size = my_strlen(text->str)) > 9) {
		if (c == 1)
			text->str[size - 1] = '\0';
		return;
	}
	if (c == 1)
		text->str[size - 1] = '\0';
	else {
		text->str[size] = c;
		text->str[size + 1] = '\0';
	}
}

void event_init_menu_click(rpg_t *rpg, new_game_t *ng)
{
	sfVector2f pos;
	int verif = 0;

	if (rpg->event.type == sfEvtMouseButtonPressed && rpg->music	\
== 1)
		sfMusic_play(rpg->song[7]);
	if (rpg->event.type == sfEvtMouseButtonPressed) {
		pos.x = rpg->event.mouseButton.x;
		pos.y = rpg->event.mouseButton.y;
		verif = 1;
	}
	for (int i = 0; verif == 1 && i < 5; i++)
		ng->button[i].click = button_is_clicked	\
(&ng->button[i], pos);
}

int event_init_menu(rpg_t *rpg, new_game_t *ng)
{
	while (sfRenderWindow_pollEvent(rpg->window, &rpg->event)) {
		if (rpg->event.type == sfEvtClosed)
			return (-1);
		if (rpg->event.key.type == sfEvtKeyPressed && sfKeyboard_is\
KeyPressed(sfKeyReturn) == 1 && ng->status != 1 && ng->status != 2)
			return (1);
		event_init_menu_click(rpg, ng);
		if (rpg->event.key.type == sfEvtKeyPressed && ng->status == 0)
			change_name_player(&ng->text, rpg);
	}
	return (0);
}
