/*
** EPITECH PROJECT, 2018
** my_rpg : lib : str_to_word_array
** File description:
** str_to_word_array
*/

#include "rpg.h"

void free_array(char **array)
{
	for (int i = 0; array[i]; i++)
		free(array[i]);
	free(array);
}

int count_words(char *str, char c)
{
	int words = 0;

	for (int i = 0; str[i] != '\0'; i++)
		if (str[i + 1] == c || str[i + 1] == '\0')
			words++;
	return (words);
}

char *fill_column(char *str, char c)
{
	char *column = NULL;
	static int cnt = 0;
	int pause = 0;
	int add = cnt;
	int i = 0;

	if (cnt == 0)
		for (; str[cnt] == c; cnt++);
	for (pause = cnt; str[pause] != c && str[pause] != '\0'; pause++);
	column = malloc(sizeof(char) * (pause - cnt + 1));
	add = pause - cnt;
	for (; i != add; i++)
		column[i] = str[cnt++];
	column[i] = str[cnt];
	for (; str[cnt] == c && str[cnt] != '\0'; cnt++);
	if (str[cnt] == '\0')
		cnt = 0;
	return (column);
}

char **str_to_word_array(char *str, char c)
{
	char **array = NULL;
	int words = 0;

	str = clean_str(str, c);
	words = count_words(str, c);
	array = malloc(sizeof(char *) * (words + 1));
	if (array == NULL)
		return (NULL);
	for (int i = 0; i != words; i++) {
		array[i] = fill_column(str, c);
		if (array[i] == NULL)
			return (NULL);
	}
	array[words] = NULL;
	return (array);
}
