/*
** EPITECH PROJECT, 2018
** refresh_intro
** File description:
** refresh intro game
*/

#include "rpg.h"

void refresh_intro_scene(intro_t *st, rpg_t *rpg)
{
	sfRenderWindow_drawSprite(rpg->window, st->im[5].sprite, NULL);
	sfRenderWindow_drawSprite(rpg->window, st->im[1].sprite, NULL);
	if (st->status == 1) {
		sfRenderWindow_drawSprite(rpg->window, st->im[4].sprite, NULL);
		sfRenderWindow_drawSprite(rpg->window, st->im[7].sprite, NULL);
	} else {
		sfRenderWindow_drawSprite(rpg->window, st->im[8].sprite, NULL);
		sfRenderWindow_drawSprite(rpg->window, st->im[3].sprite, NULL);
	}
	sfRenderWindow_drawSprite(rpg->window, st->im[2].sprite, NULL);
}

void refresh_intro(intro_t *st, rpg_t *rpg)
{
	for (int i = 0; i < 4 && st->status == 0; i++) {
		if (i == 2)
			sfRenderWindow_drawSprite(rpg->window, \
st->im[4].sprite, NULL);
		sfRenderWindow_drawSprite(rpg->window, st->im[i].sprite, NULL);
	}
	if (st->status == 1 || st->status == 2 || st->status == 3)
		refresh_intro_scene(st, rpg);
	if (st->status == 3) {
		sfRenderWindow_drawSprite(rpg->window, st->im[6].sprite, NULL);
		sfRenderWindow_drawSprite(rpg->window, st->im[9].sprite, NULL);
	}
	sfRenderWindow_display(rpg->window);
}
