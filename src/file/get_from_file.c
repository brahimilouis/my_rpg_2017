/*
** EPITECH PROJECT, 2018
** my_rpg : get_from_file
** File description:
** recuperates a file's data
*/

#include "rpg.h"

char **get_map(char *path, int count)
{
	char **map = malloc(sizeof(char *) * (count + 1));
	char *buffer = NULL;
	FILE* stream = fopen(path, "r");
	ssize_t read = 0;
	size_t n = 0;

	if (stream == NULL || map == NULL)
		return (NULL);
	read = getline(&buffer, &n, stream);
	map[0] = my_strdup(buffer);
	for (count = 0; read != -1; count++) {
		map[count] = my_strdup(buffer);
		if (count != 20)
			map[count][my_strlen(map[count]) - 2] = '\0';
		read = getline(&buffer, &n, stream);
	}
	map[count] = NULL;
	fclose(stream);
	return (map);
}

char **get_debugged_map(char *path, int count)
{
	char **map = malloc(sizeof(char *) * (count + 1));
	char *buffer = NULL;
	FILE* stream = fopen(path, "r");
	ssize_t read = 0;
	size_t n = 0;

	if (stream == NULL || map == NULL)
		return (NULL);
	read = getline(&buffer, &n, stream);
	map[0] = my_strdup(buffer);
	for (count = 0; read != -1; count++) {
		map[count] = my_strdup(buffer);
		if (count != 3)
			map[count][my_strlen(map[count]) - 1] = '\0';
		read = getline(&buffer, &n, stream);
	}
	map[count] = NULL;
	fclose(stream);
	return (map);
}

int read_file(char *path)
{
	char *buffer = NULL;
	FILE *stream = fopen(path, "rb");
	ssize_t read = 0;
	size_t n = 0;
	int count = 0;

	if (stream == NULL)
		return (-1);
	read = getline(&buffer, &n, stream);
	if (read == -1)
		return (read);
	while (read != -1) {
		count++;
		read = getline(&buffer, &n, stream);
	}
	fclose(stream);
	return (count);
}

char **get_from_file(char *path)
{
	int count = read_file(path);
	char **map = NULL;

	if (count == -1) {
		my_puterror(path);
		return (NULL);
	}
	map = get_map(path, count);
	if (map == NULL)
		return (NULL);
	if (parse_file(map) == false)
		return (NULL);
	return (map);
}

char ***get_maps(void)
{
	char ***charray = malloc(sizeof(char **) * 25);
	char *str = my_strdup("map/text_0");

	if (charray == NULL || str == NULL)
		return (NULL);
	for (int i = 0, a = 0; i < 24; i++) {
		charray[i] = get_from_file(str);
		if (charray[i] == NULL)
			return (NULL);
		if (i == 19 || i == 9) {
			a++;
			str[9] = a + '0';
			str[10] = '0';
			str[11] = '\0';
		} else if (a == 0)
			str[9] = str[9] + 1;
		else
			str[10] = str[10] + 1;
	}
	my_free(str);
	return (charray);
}
