/*
** EPITECH PROJECT, 2018
** intro_game
** File description:
** .....
*/

#include "rpg.h"

int intro_game(scene_t *scene, rpg_t *rpg)
{
	int game = 0;

	create_intro(&scene->intro);
	if (rpg->music == 1)
		sfMusic_play(rpg->song[4]);
	while (sfRenderWindow_isOpen(rpg->window) && game == 0) {
		status_intro(&scene->intro);
		move_background_intro(&scene->intro);
		game = event_intro(rpg);
		refresh_intro(&scene->intro, rpg);
		if (scene->intro.im[6].cord.x >= 800)
			game = 1;
	}
	sfMusic_stop(rpg->song[4]);
	if (game == -1)
		return (-1);
	return (2);
}
