/*
** EPITECH PROJECT, 2018
** my_rpg : parse_file
** File description:
** parse_file.c
*/

#include "rpg.h"

bool parse_line(char *line)
{
	int i = 0;

	for (; line[i] != '\0'; i++)
		if ((line[i] < '0' || line[i] > '9') && \
line[i] != '*' && line[i] != 'm' && line[i] != ('-'))
			return (false);
	if (i != 39)
		return (false);
	return (true);
}

bool parse_last_line(char *line)
{
	if (my_strlen(line) != 4)
		return (false);
	for (int i = 0; line[i] != '\0'; i++)
		if ((line[i] < '0' || line[i] > '9') && i != 3)
			return (false);
	if ((line[3] < '0' || line[3] > '9') && line[3] != '.')
		return (false);
	return (true);
}

bool parse_file(char **map)
{
	int i = 0;

	for (; map[i] != NULL; i++) {
		if (i == 20 && parse_last_line(map[i]) == false)
			return (false);
		if (i != 20 && parse_line(map[i]) == false)
			return (false);
	}
	if (i != 21)
		return (false);
	return (true);
}
