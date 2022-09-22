/*
** EPITECH PROJECT, 2017
** my_rpg : main.c
** File description:
** main
*/

#include <stdint.h>
#include "rpg.h"

int init_intro(intro_t *intro)
{
	if (init_spr_txt(intro) == 84)
		return (84);
	for (int i = 0; i < 2; i++) {
		intro->tempo[i].clock = sfClock_create();
		if (!intro->tempo[i].clock)
			return (84);
	}
	return (0);
}

int init_menu(menu_t *menu)
{
	int i = 0;

	i = init_image("png/menu.jpg", &menu->im[0], i);
	i = init_image("png/mouette.png", &menu->im[1], i);
	i = init_image("png/tuto0.jpg", &menu->tuto[0], i);
	i = init_image("png/tuto1.jpg", &menu->tuto[1], i);
	i = init_image("png/tuto2.jpg", &menu->tuto[2], i);
	if (i == 84)
		return (84);
	menu->tempo.clock = sfClock_create();
	if (menu->tempo.clock == NULL)
		return (84);
	return (0);
}

int init_ng(new_game_t *ng)
{
	int i = 0;

	i = init_image("png/NG1.jpg", &ng->im[0], i);
	i = init_image("png/NG2.jpg", &ng->im[1], i);
	i = init_image("png/NG3.jpg", &ng->im[2], i);
	i = init_image("png/NG4.png", &ng->im[3], i);
	i = init_image("png/perso.png", &ng->im[4], i);
	return (i);
}

int init_continue(load_t *load)
{
	int i = 0;

	i = init_image("png/load_game.png", &load->im[0], i);
	return (i);
}

int main(int ac, char **av, char **ae)
{
	sfVideoMode mode = {1920, 1080, 32};
	rpg_t rpg;
	scene_t scene;
	int rand;

	srand((((intptr_t)&rand) & 0xFFFFFFFF));
	(void)av;
	if (init_intro(&scene.intro) == 84)
		return (84);
	if (ac != 1 || ae[0] == NULL || &scene.intro == NULL)
		return (84);
	if (init_menu(&scene.menu) == 84 || init_ng(&scene.ng) == 84 || \
init_game(&scene.game) == 84 || init_continue(&scene.load) == 84 || \
init_fight(&scene.game.fight) == 84 || init_end(&scene.end) == 84 \
|| init_song(&rpg) == 84)
		return (84);
	rpg.window = sfRenderWindow_create(mode, "rpg", sfClose, NULL);
	if (rpg.window == NULL)
		return (84);
	rpg.game = 1;
	return ((my_rpg(&rpg, &scene) != -1) ? 84 : 0);
}
