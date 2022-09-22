/*
** EPITECH PROJECT, 2017
** move_rect
** File description:
** move rectangle
*/

#include "rpg.h"

void move_rect(sfIntRect *rect, im_t *im, int top, int heiht)
{
	rect->top = top;
	rect->left = im->offset;
	rect->width = im->move;
	rect->height = heiht;
}
