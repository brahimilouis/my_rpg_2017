/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** decides which scene to go
*/

#include "rpg.h"

void cpy_player(player_t *player1, player_t *player2)
{
	player2->gender = player1->gender;
	player2->class = player1->class;
	player2->map = player1->map;
	player2->cord = player1->cord;
	player2->name = malloc(sizeof(char) * (my_strlen(player1->name) + 1));
	player2->name = my_strcpy(player2->name, player1->name);
	player2->move = 0;
	player2->status = player1->status;
	my_free(player1->name);
}

int my_rpg(rpg_t *rpg, scene_t *scene)
{
	while (rpg->game != -1 && rpg->game != 84) {
		switch (rpg->game) {
		case 0:	rpg->game = intro_game(scene, rpg);
			break;
		case 1:	rpg->game = menu_game(scene, rpg);
			break;
		case 2:	rpg->game = init_menu_game(&scene->ng, rpg);
			break;
		case 6:	cpy_player(&scene->ng.player, &scene->game.player);
			rpg->game = change_map_with_save(&scene->game);
			break;
		case 3:	rpg->game = game(&scene->game, rpg);
			break;
		case 4:	rpg->game = load_game(scene, rpg);
			break;
		case 5:	rpg->game = end_game(scene, rpg);
			break;
		}
	}
	close_game(scene, rpg);
	return (rpg->game);
}
