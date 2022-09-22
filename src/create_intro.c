/*
** EPITECH PROJECT, 2018
** create_intro
** File description:
** intro
*/

#include "rpg.h"

void create_intro(intro_t *scene)
{
	for (int i = 0; i < 10; i++) {
		scene->im[i].cord.x = 0;
		scene->im[i].cord.y = 0;
		scene->im[i].pos.y = 0;
		scene->im[i].pos.x = 0;
	}
	for (int i = 0; i < 2; i++)
		scene->tempo[i].seconds = 0;
	scene->im[0].pos.x = -1;
	scene->im[1].pos.x = -2;
	scene->im[2].pos.x = -3;
	scene->im[6].pos.y = -1080;
	scene->im[8].pos.y = 1;
	scene->im[9].pos.y = 1080;
	sfSprite_move(scene->im[6].sprite, scene->im[6].pos);
	sfSprite_move(scene->im[9].sprite, scene->im[9].pos);
	scene->im[9].pos.y = -3;
	scene->im[6].pos.y = 3;
	scene->status = 0;
	sfClock_restart(scene->tempo[1].clock);
	sfClock_restart(scene->tempo[0].clock);
}
