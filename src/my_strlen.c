/*
** EPITECH PROJECT, 2018
** lib : my_strlen
** File description:
** returns an int
*/

#include "rpg.h"

int my_strlen(char *str)
{
	int i = 0;

	while (str[i] != '\0')
		i++;
	return (i);
}
