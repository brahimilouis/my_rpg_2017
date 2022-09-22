/*
** EPITECH PROJECT, 2018
** my_rpg : lib : my_strdup
** File description:
** my_strdup
*/

#include "rpg.h"

char *my_strdup(char *str)
{
	char *new_str;
	int count = -1;

	if (my_strcmp(str, "map/text_0") == 0)
		new_str = malloc(sizeof(char) * (my_strlen(str) + 2));
	else
		new_str = malloc(sizeof(char) * (my_strlen(str) + 1));
	if (new_str == NULL)
		return (NULL);
	while (++count < my_strlen(str))
		new_str[count] = str[count];
	new_str[count] = '\0';
	return (new_str);
}
