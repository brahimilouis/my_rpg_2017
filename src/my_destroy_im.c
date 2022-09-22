/*
** EPITECH PROJECT, 2018
** my_rpg : lib : my_destroy
** File description:
** my_destroy
*/

#include "rpg.h"

void my_destroy_im(im_t im)
{
	if (im.sprite != NULL)
		sfSprite_destroy(im.sprite);
	if (im.texture != NULL)
		sfTexture_destroy(im.texture);
}
