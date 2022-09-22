/*
** EPITECH PROJECT, 2018
** refresh_end
** File description:
** refresh the end
*/

#include "rpg.h"

void refresh_end(end_t *st, rpg_t *rpg, game_t *gam)
{
	gam->im[0].pos.x = 922;
	gam->im[0].pos.y = 530;
	if (st->status == 0) {
		sfRenderWindow_drawSprite(rpg->window, \
gam->map_s[1][0].sprite, NULL);
		sfRenderWindow_drawSprite(rpg->window, gam->im[0].sprite, NULL);
	} else if (st->status > 0) {
		sfRenderWindow_drawSprite(rpg->window, st->im[2].sprite, NULL);
		sfRenderWindow_drawSprite(rpg->window, st->im[3].sprite, NULL);
	}
	if (st->status == 3)
		sfRenderWindow_drawSprite(rpg->window, st->im[4].sprite, NULL);
	for (int i = 0; i < 2 && (st->status == 1 || st->status == 0 || \
st->status == 3); i++)
		sfRenderWindow_drawSprite(rpg->window, st->im[i].sprite, NULL);
	sfSprite_setPosition(gam->im[0].sprite, gam->im[0].pos);
	if (st->status == 4) {
		sfRenderWindow_drawSprite(rpg->window, st->im[5].sprite, NULL);
		sfRenderWindow_drawSprite(rpg->window, gam->im[0].sprite, NULL);
	}
	sfRenderWindow_display(rpg->window);
}
