/*
** EPITECH PROJECT, 2018
** my_rpg : close_game
** File description:
** close the game, destroy events
*/

#include "rpg.h"

int destroy_sprite4(scene_t *scene, int i, int j)
{
	if (j == -1)
		return (-1);
	switch (i) {
	case 5: my_destroy_im(scene->game.obj[i]);
		my_destroy_im(scene->game.map_s[i][0]);
		my_destroy_im(scene->game.map_s[i][1]);
		my_destroy_im(scene->game.map_s[i][2]);
		my_destroy_im(scene->game.map_s[i][3]);
		my_destroy_im(scene->game.mobs[i]);
		my_destroy_im(scene->game.talk_pnj[i]);
		return (0);
	case 6: my_destroy_im(scene->game.obj[i]);
		return (0);
	default: return (-1);
	}
}

int destroy_sprite3(scene_t *scene, int i, int j)
{
	if (j == -1)
		return (-1);
	switch (i) {
	case 4: my_destroy_im(scene->game.im[i]);
		my_destroy_im(scene->game.obj[i]);
		my_destroy_im(scene->game.map_s[i][0]);
		my_destroy_im(scene->game.map_s[i][1]);
		my_destroy_im(scene->game.map_s[i][2]);
		my_destroy_im(scene->game.map_s[i][3]);
		my_destroy_im(scene->game.mobs[i]);
		my_destroy_im(scene->game.talk_pnj[i]);
		return (0);
	default: return (-1);
	}
}

int destroy_sprite2(scene_t *scene, int i, int j)
{
	if (j == -1)
		return (-1);
	switch (i) {
	case 1:
	case 2:
	case 3: my_destroy_im(scene->game.im[i]);
		my_destroy_im(scene->game.obj[i]);
		my_destroy_im(scene->game.map_s[i][0]);
		my_destroy_im(scene->game.map_s[i][1]);
		my_destroy_im(scene->game.map_s[i][2]);
		my_destroy_im(scene->game.map_s[i][3]);
		my_destroy_im(scene->game.obstacles[i]);
		my_destroy_im(scene->game.mobs[i]);
		my_destroy_im(scene->game.talk_pnj[i]);
		my_destroy_im(scene->game.fight.im_p[i]);
		return (0);
	default: return (-1);
	}
}

int destroy_sprite1(scene_t *scene, int i, int j)
{
	if (j == -1)
		return (-1);
	switch (i) {
	case 0: my_destroy_im(scene->load.im[i]);
		my_destroy_im(scene->game.im[i]);
		my_destroy_im(scene->game.obj[i]);
		my_destroy_im(scene->game.map_s[i][0]);
		my_destroy_im(scene->game.map_s[i][1]);
		my_destroy_im(scene->game.map_s[i][2]);
		my_destroy_im(scene->game.map_s[i][3]);
		my_destroy_im(scene->game.obstacles[i]);
		my_destroy_im(scene->game.mobs[i]);
		my_destroy_im(scene->game.talk_pnj[i]);
		my_destroy_im(scene->game.fight.im_p[i]);
		return (0);
	default: return (-1);
	}
}

void close_game(scene_t *scene, rpg_t *rpg)
{
	destroy_game(scene);
	destroy_rpg(rpg);
	destroy_menu(scene);
	destroy_ng(scene);
	destroy_intro(scene);
	destroy_end(scene);
	if (scene->game.tempo[0].clock != NULL)
		sfClock_destroy(scene->game.tempo[0].clock);
	if (scene->game.fight.tempo.clock != NULL)
		sfClock_destroy(scene->game.fight.tempo.clock);
	sfRenderWindow_destroy(rpg->window);
}
