/*
** EPITECH PROJECT, 2018
** create_intro
** File description:
** intro
*/

#include "rpg.h"

void init_player(player_t *player)
{
	player->map.x = 3;
	player->map.y = 3;
	player->cord.x = 10;
	player->cord.y = 8;
	player->status = 0;
	player->move = 0;
}

int create_init_button(new_game_t *ng)
{
	for (int i = 0; i < 5; i++) {
		ng->button[i].size.x = 372;
		ng->button[i].size.y = 414;
		ng->button[i].position.y = 550;
		if (i < 2)
			ng->button[i].position.x = i * 695 + 429;
		else {
			ng->button[i].position.y = 500;
			ng->button[i].position.x = (i - 2) * 610 + 150;
		}
		if (init_button(&ng->button[i], ng->button[i].size, \
ng->button[i].position) == 84)
			return (84);
	}
	return (0);
}

int create_init_menu(new_game_t *ng)
{
	init_player(&ng->player);
	ng->status = 0;
	ng->text.vector.x = 500;
	ng->text.vector.y = 500;
	if (init_text(&ng->text, 150) == 84 || create_init_button(ng) == 84)
		return (84);
	return (0);
}
