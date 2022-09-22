/*
** EPITECH PROJECT, 2018
** my_rpg : lib : arraylen
** File description:
** arraylen
*/

#include "rpg.h"

int my_arraylen(char **array)
{
	int i = 0;

	while (array[i] != NULL)
		i++;
	return (i);
}
