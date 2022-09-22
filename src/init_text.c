/*
** EPITECH PROJECT, 2018
** init
** File description:
** text
*/

#include "rpg.h"

int init_text(text_t *text, int size)
{
	text->str = malloc(sizeof(char) * (12));
	text->str[0] = '\0';
	if (text->str == NULL)
		return (84);
	text->font = sfFont_createFromFile("png/arial.ttf");
	text->text = sfText_create();
	if (text->font == NULL || text->text == NULL)
		return (84);
	sfText_setFont(text->text, text->font);
	sfText_setString(text->text, "J");
	sfText_setColor(text->text, sfWhite);
	sfText_setCharacterSize(text->text, size);
	sfText_setPosition(text->text, text->vector);
	return (0);
}
