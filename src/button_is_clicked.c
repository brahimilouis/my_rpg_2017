/*
** EPITECH PROJECT, 2018
** my_rpg : buttonIsClicked
** File description:
** clique button
*/

#include "rpg.h"

int button_is_clicked(button_t *st, sfVector2f clickPosition)
{
	return (clickPosition.x <\
sfRectangleShape_getPosition(st->rect).x +\
sfRectangleShape_getSize(st->rect).x &&\
clickPosition.x > sfRectangleShape_getPosition(st->rect).x &&\
clickPosition.y < sfRectangleShape_getPosition(st->rect).y + \
sfRectangleShape_getSize(st->rect).y &&\
clickPosition.y > sfRectangleShape_getPosition(st->rect).y);
}
