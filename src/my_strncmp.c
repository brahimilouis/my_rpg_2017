/*
** EPITECH PROJECT, 2018
** my_rpg : lib : my_strncmp
** File description:
** my_strncmp.c
*/

#include "rpg.h"

int my_strncmp(char *s1, char *s2, int n)
{
	int i = 0;
	int j = 0;

	while (i < n && j < n && s1[i] != '\0' && s2[j] != '\0')
		if (s1[i] == s2[j]) {
			i++;
			j++;
		}
		else if (s1[i] > s2[j])
			return (1);
		else
			return (-1);
	return (0);
}
