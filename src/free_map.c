/*
** EPITECH PROJECT, 2018
** free
** File description:
** map
*/

#include "rpg.h"

void free_map(char ***map)
{
	for (int j = 0; j < 24; j++) {
		for (int i = 0; i < 20; i++)
			my_free(map[j][i]);
		my_free(map[j]);
	}
	my_free(map);
}
