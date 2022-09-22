/*
** EPITECH PROJECT, 2018
** check_button
** File description:
** init
*/

#include "rpg.h"

void position_name(new_game_t *ng)
{
	int size = my_strlen(ng->text.str);

	ng->player.name = malloc(sizeof(char) * (my_strlen(ng->text.str) + 1));
	ng->player.name = my_strcpy(ng->player.name, ng->text.str);
	ng->text.vector.x = 1250 - size * 90;
	ng->text.vector.y = 160;
	ng->text.str[size] = '!';
	ng->text.str[size + 1] = '\0';
	sfText_setPosition(ng->text.text, ng->text.vector);
}

void change_player(new_game_t *ng)
{
	if (ng->button[0].click == 1)
		ng->player.gender = 0;
	if (ng->button[1].click == 1)
		ng->player.gender = 1;
	if (ng->button[2].click == 1)
		ng->player.class = 2;
	if (ng->button[3].click == 1)
		ng->player.class = 1;
	if (ng->button[4].click == 1)
		ng->player.class = 0;
}

void check_button_ng(new_game_t *ng)
{
	for (int i = 2; i < 5 && ng->status == 1; i++)
		ng->button[i].click = 0;
	for (int i = 0; i < 2 && ng->status == 2; i++)
		ng->button[i].click = 0;
	for (int i = 0; i < 5 && ng->status != 1 && ng->status != 2; i++)
		ng->button[i].click = 0;
	change_player(ng);
	for (int i = 0; i < 5; i++) {
		if (ng->button[i].click == 1)
			ng->status++;
		if (ng->button[i].click == 1 && i > 1) {
			position_name(ng);
			choice_character(ng);
		}
		ng->button[i].click = 0;
	}
}
