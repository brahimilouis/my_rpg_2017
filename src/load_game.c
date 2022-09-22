/*
** EPITECH PROJECT, 2018
** load
** File description:
** game
*/

#include "rpg.h"

int loop_load_game(scene_t *scene, rpg_t *rpg)
{
	int game;
	int verif = -1;

	game = event_load(rpg, &scene->load);
	if (game == 3)
		verif = get_save(scene, scene->load.text.str);
	if (game == 3 && verif == 84) {
			game = 4;
			verif = -1;
			if (rpg->music == 1)
				sfMusic_play(rpg->song[9]);
	} else if (game == 3 && verif == 0)
		game = 3;
	refresh_load(&scene->load, rpg);
	return (game);
}

int load_game(scene_t *scene, rpg_t *rpg)
{
	int game = 4;

	if (create_load(&scene->load) == 84)
		return (84);
	while (sfRenderWindow_isOpen(rpg->window) && game == 4)
		game = loop_load_game(scene, rpg);
	my_free(scene->load.text.str);
	if (game == 3) {
		cpy_player(&scene->ng.player, &scene->game.player);
		if (change_map_with_save(&scene->game) == 84)
			return (84);
	}
	return (game);
}
