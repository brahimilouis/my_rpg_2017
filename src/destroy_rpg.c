/*
** EPITECH PROJECT, 2018
** my_rpg : destroy_rpg
** File description:
** destroy rpg struct
*/

#include "rpg.h"

void destroy_intro(scene_t *scene)
{
	for (int i = 0; i < 10; i++)
		my_destroy_im(scene->intro.im[i]);
}

void destroy_menu(scene_t *scene)
{
	for (int i = 0; i < 2; i++)
		my_destroy_im(scene->menu.im[i]);
	for (int i = 0; i < 3; i++)
		my_destroy_im(scene->menu.tuto[i]);
	for (int i = 0; i < 5; i++)
		sfRectangleShape_destroy(scene->menu.button[i].rect);
}

void destroy_ng(scene_t *scene)
{
	sfText_destroy(scene->ng.text.text);
	sfFont_destroy(scene->ng.text.font);
	for (int i = 0; i < 5; i++)
		sfRectangleShape_destroy(scene->ng.button[i].rect);
	for (int i = 0; i < 6; i++)
		my_destroy_im(scene->ng.im[i]);
}

void destroy_game(scene_t *scene)
{
	for (int i = 0; i < 4; i++) {
		my_free(scene->game.fight.text[i].str);
		sfText_destroy(scene->game.fight.text[i].text);
		sfFont_destroy(scene->game.fight.text[i].font);
	}
	for (int i = 0; i < 6; i++)
		my_free(scene->game.fight.mob[i].name);
	for (int i = 0, j = 0; i < 26; i++) {
		my_destroy_im(scene->game.fight.letter[i]);
		j = destroy_sprite1(scene, i, j);
		j = destroy_sprite2(scene, i, j);
		j = destroy_sprite3(scene, i, j);
		j = destroy_sprite4(scene, i, j);
	}
}

void destroy_rpg(rpg_t *rpg)
{
	for (int i = 0; i < 12; i++)
		sfMusic_destroy(rpg->song[i]);
}
