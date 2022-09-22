/*
** EPITECH PROJECT, 2018
** my_rpg : lib : my_puterror
** File description:
** print errors
*/

#include "rpg.h"

void my_puterror(char *str)
{
	for (int i = 0; str[i] != '\0'; i++)
		write(2, &str[i], 1);
}
