/*
** EPITECH PROJECT, 2018
** my_rpg : menu_game
** File description:
** handle the menu game
*/

#include "rpg.h"

int check_button_menu(menu_t *menu, rpg_t *rpg)
{
	if (menu->button[0].click == 1)
		return (0);
	if (menu->button[1].click == 1)
		return (4);
	if (menu->button[2].click == 1)
		return (tuto_game(menu, rpg));
	if (menu->button[3].click == 1)
		return (-1);
	return (1);
}

int menu_game(scene_t *scene, rpg_t *rpg)
{
	int game = 1;

	if (rpg->music == 1) {
		sfMusic_play(rpg->song[6]);
		sfMusic_setLoop(rpg->song[0], sfTrue);
	}
	if (create_menu(&scene->menu) == 84)
		return (84);
	while (sfRenderWindow_isOpen(rpg->window) && game == 1) {
		movement_bird(&scene->menu);
		game = event_menu(rpg, &scene->menu, 1);
		if (game != -1)
			game = check_button_menu(&scene->menu, rpg);
		refresh_menu(&scene->menu, rpg);
	}
	sfMusic_stop(rpg->song[6]);
	if (game == -2)
		return (1);
	return (game);
}
