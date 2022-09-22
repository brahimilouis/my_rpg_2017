/*
** EPITECH PROJECT, 2018
** end_game
** File description:
** end the game
*/

#include "rpg.h"

int end_game(scene_t *scene, rpg_t *rpg)
{
	int game = 5;

	sfMusic_play(rpg->song[6]);
	create_end(&scene->end);
	while (sfRenderWindow_isOpen(rpg->window) && game == 5) {
		status_end(&scene->end);
		game = event_end(rpg);
		refresh_end(&scene->end, rpg, &scene->game);
	}
	return (game);
}
