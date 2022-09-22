/*
** EPITECH PROJECT, 2018
** refresh
** File description:
** load
*/

#include "rpg.h"

void refresh_load(load_t *load, rpg_t *rpg)
{
	sfRenderWindow_drawSprite(rpg->window, load->im[0].sprite, NULL);
	sfText_setString(load->text.text, load->text.str);
	sfRenderWindow_drawText(rpg->window, load->text.text, NULL);
	sfRenderWindow_display(rpg->window);
}
