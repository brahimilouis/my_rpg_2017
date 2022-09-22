/*
** EPITECH PROJECT, 2018
** init_button
** File description:
** button
*/

#include "rpg.h"

int init_button(button_t* button, sfVector2f size, sfVector2f position)
{
	button->rect = sfRectangleShape_create();
	if (button->rect == NULL)
		return (84);
	button->click = 0;
	sfRectangleShape_setPosition(button->rect, position);
	sfRectangleShape_setSize(button->rect, size);
	sfRectangleShape_setFillColor(button->rect, sfTransparent);
	return (0);
}
