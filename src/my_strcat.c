/*
** EPITECH PROJECT, 2018
** lib : my_strcat
** File description:
** concatenate 2 strings
*/

#include "rpg.h"

char *my_strcat(char *s1, char *s2)
{
	int i = 0;
	int j = 0;
	char *dest = NULL;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = my_strlen(s1);
	j = my_strlen(s2);
	dest = malloc(sizeof(char) * (i + j + 1));
	for (i = 0; s1[i] != '\0'; i++)
		dest[i] = s1[i];
	for (j = 0; s2[j] != '\0'; j++, i++)
		dest[i] = s2[j];
	dest[i] = '\0';
	return (dest);
}
