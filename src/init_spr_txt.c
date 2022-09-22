/*
** EPITECH PROJECT, 2018
** rpg : init_spr_txt
** File description:
** initializes sprite and texture
*/

#include "rpg.h"

int init_image(char *path, im_t *im, int verif)
{
	if (verif == 84)
		return (84);
	im->sprite = sfSprite_create();
	im->texture = sfTexture_createFromFile(path, NULL);
	if (!im->sprite || !im->texture)
		return (84);
	sfSprite_setTexture(im->sprite, im->texture, sfTrue);
	return (0);
}

int init_spr_txt(intro_t *intro)
{
	int i = 0;

	i = init_image("png/blue_sky.png", &intro->im[0], i);
	i = init_image("png/sea_2.png", &intro->im[1], i);
	i = init_image("png/sea_1.png", &intro->im[2], i);
	i = init_image("png/space_to_skip.png", &intro->im[3], i);
	i = init_image("png/boat.png", &intro->im[4], i);
	i = init_image("png/darksky.png", &intro->im[5], i);
	i = init_image("png/end_intro.png", &intro->im[6], i);
	i = init_image("png/thunder_plus_skip.png", &intro->im[7], i);
	i = init_image("png/boat_break.png", &intro->im[8], i);
	i = init_image("png/end_intro.png", &intro->im[9], i);
	return (i);
}
