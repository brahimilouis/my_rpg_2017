/*
** EPITECH PROJECT, 2018
** choice_character
** File description:
** choose char
*/

#include "rpg.h"

void choice_character(new_game_t *ng)
{
	ng->im[4].offset = ng->player.class * 280;
	ng->im[4].move = 280 + ng->player.gender;
	move_rect(&ng->im[4].rect, &ng->im[4], ng->player.gender * 545, \
545 * (ng->player.gender + 1));
	sfSprite_setTextureRect(ng->im[4].sprite, ng->im[4].rect);
	ng->im[4].pos.x = 820;
	ng->im[4].pos.y = 320;
	sfSprite_setPosition(ng->im[4].sprite, ng->im[4].pos);
}
