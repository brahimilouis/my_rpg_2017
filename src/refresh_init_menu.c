/*
** EPITECH PROJECT, 2018
** refresh_menu
** File description:
** .....
*/

#include "rpg.h"

void refresh_init_menu(new_game_t *ng, rpg_t *rpg)
{
	sfRenderWindow_drawSprite(rpg->window, ng->im[ng->status].sprite, NULL);
	for (int i = 0; i < 5; i++) {
		if (ng->status == 1 && i < 2)
			sfRenderWindow_drawRectangleShape(rpg->window, \
ng->button[i].rect, NULL);
		else if (ng->status == 2 && i < 5 && i > 1)
			sfRenderWindow_drawRectangleShape(rpg->window,	\
ng->button[i].rect, NULL);
	}
	if (ng->status == 3)
		sfRenderWindow_drawSprite(rpg->window, ng->im[4].sprite, NULL);
	if (ng->status == 0 || ng->status == 3) {
		sfText_setString(ng->text.text, ng->text.str);
		sfRenderWindow_drawText(rpg->window, ng->text.text, NULL);
	}
	sfRenderWindow_display(rpg->window);
}
