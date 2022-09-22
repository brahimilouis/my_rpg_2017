/*
** EPITECH PROJECT, 2018
** my_rpg : lib : my_strcmp
** File description:
** my_strcmp.c
*/

#include "rpg.h"

int my_strcmp(char *s1, char *s2)
{
	int i = 0;
	int j = 0;

	while (s1[i] != '\0' && s2[j] != '\0') {
		if (s1[i] == s2[j]) {
			i++;
			j++;
		} else if (s1[i] > s2[j])
			return (1);
		else
			return (-1);
	}
	i = my_strlen(s1);
	j = my_strlen(s2);
	if (i > j)
		return (1);
	else if (i < j)
		return (-1);
	return (0);
}
