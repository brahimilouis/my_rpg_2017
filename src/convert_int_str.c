/*
** EPITECH PROJECT, 2017
** my_putnbr_base
** File description:
** ...
*/

#include "rpg.h"

int my_intlen(int nb)
{
	int len = 0;

	if (nb == 0)
		return (1);
	for (; nb != 0; len++)
		nb /= 10;
	if (len == 0)
		return (1);
	return (len);
}

char *convert_int_str(int nb)
{
	int diviseur = 1;
	int division = 1;
	int i = -1;
	char *str = malloc(sizeof(char) * (my_intlen(nb) + 1));

	str[my_intlen(nb)] = '\0';
	if (nb == 0)
		return ("0");
	if (str == NULL)
		return (NULL);
	for (; division != 0; i++) {
		division = nb / diviseur;
		diviseur *= 10;
	}
	diviseur /= 100;
	for (int j = 0; i > 0; i--, j++) {
		str[j] = (nb / diviseur) + 48;
		nb = nb % diviseur;
		diviseur = diviseur / 10;
	}
	return (str);
}
