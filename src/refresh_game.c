/*
** EPITECH PROJECT, 2018
** refresh_menu
** File description:
** .....
*/

#include "rpg.h"

void refresh_event_game(game_t *st, rpg_t *rpg)
{
	if (st->display_map == 1 && st->display_inventory == 0)
		sfRenderWindow_drawSprite(rpg->window, st->im[1].sprite, NULL);
	if (st->display_map == 0 && st->display_inventory == 1) {
		sfRenderWindow_drawSprite(rpg->window, \
st->obj[st->player.status].sprite, NULL);
		sfRenderWindow_drawSprite(rpg->window, st->im[2].sprite, NULL);
	}
}

void refresh_pause(game_t *st, rpg_t *rpg)
{
	sfRenderWindow_drawSprite(rpg->window, st->im[3].sprite, NULL);
	for (int i = 0; i < 5; i++)
		sfRenderWindow_drawRectangleShape(rpg->window, \
st->button[i].rect, NULL);
	if (rpg->music == 0)
		sfRenderWindow_drawSprite(rpg->window, st->im[4].sprite, NULL);
	sfRenderWindow_display(rpg->window);
}

void refresh_map_game(game_t *st, rpg_t *rpg)
{
	char nb1 = st->map[pt_map(st->player.map)][20][0];
	char nb2 = st->map[pt_map(st->player.map)][20][1];

	if (nb1 != '0')
		sfRenderWindow_drawSprite(rpg->window, \
st->obstacles[nb1 - '0' - 1].sprite, NULL);
	if (nb2 != '0')
		sfRenderWindow_drawSprite(rpg->window, \
st->mobs[nb2 - '0' - 1].sprite, NULL);
}

void refresh_game(game_t *st, rpg_t *rpg)
{
	int y = st->player.map.y;
	int x = st->player.map.x;

	if (st->pause == 1) {
		refresh_pause(st, rpg);
		return;
	}
	sfRenderWindow_drawSprite(rpg->window, st->map_s[y][x].sprite, NULL);
	refresh_map_game(st, rpg);
	if (st->talk == 1)
		sfRenderWindow_drawSprite(rpg->window,	\
st->talk_pnj[st->player.status].sprite, NULL);
	sfRenderWindow_drawSprite(rpg->window, st->im[0].sprite, NULL);
	refresh_event_game(st, rpg);
	sfRenderWindow_display(rpg->window);
}
