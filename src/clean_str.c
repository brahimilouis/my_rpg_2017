/*
** EPITECH PROJECT, 2018
** lib : clean_str
** File description:
** clean_str.c
*/

#include "rpg.h"

int check_valid_str(char *str)
{
	int cnt = 0;

	for (; str[cnt] != '\0'; )
		switch (str[cnt]) {
		case ' ': cnt++; break;
		case '\n': cnt++; break;
		case '\t': cnt++; break;
		case '\v': cnt++; break;
		default: return (0);
		}
	if (str[cnt] == '\0')
		return (0);
	return (-1);
}

int check_errors(char c, char cut)
{
	if (c != cut && c != '\t' && c != '\v')
		return (1);
	return (0);
}

char *remove_last_space(char *str, char cut)
{
	int i = my_strlen(str);

	if (str[i - 1] == cut || str[i - 1] < '0')
		str[i - 1] = '\0';
	return (str);
}

char *check_false_char(char *str)
{
	for (int i = 0; str[i] != '\0'; i++)
		if (str[i] < 32 || str[i] > '~')
			str[i] = ' ';
	return (str);
}

char *clean_str(char *str, char cut)
{
	int cnt = 0;

	if (check_valid_str(str)== -1)
		return (NULL);
	check_false_char(str);
	for (int i = 0; str[i] != '\0'; i++)
		if (check_errors(str[i], cut) == 1)
			str[cnt++] = str[i];
		else if (cnt != 0 && (check_errors(str[i], cut) == 0) \
&& (check_errors(str[i - 1], cut) == 1))
			str[cnt++] = cut;
	str[cnt] = '\0';
	remove_last_space(str, cut);
	return (str);
}
