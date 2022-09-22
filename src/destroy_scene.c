/*
** EPITECH PROJECT, 2018
** my_rpg : destroy_scene
** File description:
** destroy all other scenes
*/

#include "rpg.h"

void destroy_end(scene_t *scene)
{
	for (int i = 0; i < 2; i++)
		sfClock_destroy(scene->end.tempo[i].clock);
	for (int i = 0; i < 6; i++)
		my_destroy_im(scene->end.im[i]);
}
