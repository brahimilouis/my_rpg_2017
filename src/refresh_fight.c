/*
** EPITECH PROJECT, 2018
** refresh_menu
** File description:
** .....
*/

#include "rpg.h"

void refresh_particule(fight_t *st, rpg_t *rpg)
{
	for (int i = 0; i < 500; i++) {
		if (st->part_p[i].verif == 1) {
			sfSprite_setPosition(st->im_p[st->gender].sprite, \
st->part_p[i].pos);
			sfRenderWindow_drawSprite(rpg->window, st->im_p	\
[st->gender].sprite, NULL);
		}
	}
	for (int i = 0; st->display_part_e == 1 && i < 100; i++) {
		sfSprite_setPosition(st->im_p[3].sprite, \
st->part_e[i].pos);
		sfRenderWindow_drawSprite(rpg->window, st->im_p\
[3].sprite, NULL);
	}
}

void refresh_fight(fight_t *st, rpg_t *rpg, int fight, int hp)
{
	sfText_setString(st->text[3].text, \
convert_int_str(hp));
	sfText_setString(st->text[1].text, \
convert_int_str(st->mob[fight].life));
	sfRenderWindow_drawSprite(rpg->window, st->background.sprite, NULL);
	for (int j = 0; st->str[j] != '\0'; j++)
		sfRenderWindow_drawSprite(rpg->window, st->letter\
[st->str[j] - 'a'].sprite, NULL);
	sfRenderWindow_drawSprite(rpg->window, st->player.sprite, NULL);
	sfRenderWindow_drawSprite(rpg->window, st->mob[fight].im.sprite, NULL);
	for (int i = 0; i < 4; i++)
		sfRenderWindow_drawText(rpg->window, st->text[i].text, NULL);
	refresh_particule(st, rpg);
	sfRenderWindow_display(rpg->window);
}
