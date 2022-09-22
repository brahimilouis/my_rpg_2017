/*
** EPITECH PROJECT, 2018
** maj
** File description:
** map
*/

#include "rpg.h"

void maj_map(game_t *game, char **map, int pos)
{
	int nb = my_getnbr(&map[20][2]);
	int i = 0;
	int j = 0;

	while (j < 20) {
		if (game->map[pos][j][i] > '1')
			game->map[pos][j][i] = '0';
		if (game->map[nb][j][i] == '*')
			game->map[nb][j][i] = '0';
		i++;
		if (i == 39) {
			i = 0;
			j++;
		}
	}
	game->map[pos][20][1] = '0';
	if (game->map[nb][20][0] == '0' && nb == 14)
		game->map[nb][j][i] = '1';
	else
		game->map[nb][j][i] = '0';
}
