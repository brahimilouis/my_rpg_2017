/*
** EPITECH PROJECT, 2018
** my_rpg : lib : my_free
** File description:
** my_free
*/

#include "rpg.h"

void my_free(void *ptr)
{
	if (ptr != NULL)
		free(ptr);
}
