/*
** EPITECH PROJECT, 2018
** my_rpg : get_save
** File description:
** get_save.c
*/

#include "rpg.h"

bool check_str(char *str, int i)
{
	for (int j = 0; str[j] != '\0'; j++)
		if (str[j] < '0' || (str[j] > '9' && str[j] < 'A') \
|| (str[j] > 'Z' && str[j] < 'a') || str[j] > 'z')
			return (false);
	if (my_strlen(str) > i)
		return (false);
	return (true);
}

int check_name(char **data, scene_t *scene)
{
	if (my_strncmp("NAME", data[0], 4) != 0)
		return (0);
	if (scene->ng.player.name != NULL && data[1] != NULL) {
		if (my_strcmp(scene->ng.player.name, data[1]) != 0) {
			my_puterror("Choose only one name.\n");
			return (84);
		}
	}
	if (my_arraylen(data) != 2 || check_str(data[1], 10) == false) {
		my_puterror("NAME:(your name) At most: 10 letters allowed.\n");
		return (84);
	}
	scene->ng.player.name = my_strdup(data[1]);
	return (0);
}

int check_data_line(char *dataline, scene_t *scene)
{
	char **data = str_to_word_array(dataline, ':');
	int i = 0;

	if (data == NULL)
		return (84);
	while (i == 0) {
		i = check_name(data, scene);
		i = check_gender(data, scene);
		i = check_class(data, scene);
		i = check_status(data, scene);
		break;
	}
	for (int y = 0; data[y] != NULL; y++)
		my_free(data[y]);
	my_free(data);
	return (i);
}

bool parse_data(char **data, scene_t *scene)
{
	scene->ng.player.name = NULL;
	for (int i = 0; data[i] != NULL; i++) {
		if (check_data_line(data[i], scene) == 84) {
			return (false);
		}
	}
	return (true);
}

int get_save(scene_t *scene, char *str)
{
	char **data = NULL;
	char *new = my_strcat("saves/", str);
	int count = read_file(new);

	if (count == -1)
		return (84);
	scene->ng.player.map.x = 3;
	scene->ng.player.map.y = 3;
	scene->ng.player.cord.x = 10;
	scene->ng.player.cord.y = 8;
	scene->ng.player.gender = -1;
	scene->ng.player.class = -1;
	scene->ng.player.status = 1234567890;
	data = get_debugged_map(new, count);
	if (data == NULL || parse_data(data, scene) == false)
		return (84);
	free(new);
	for (int i = 0; data[i] != NULL; i++)
		my_free(data[i]);
	my_free(data);
	return (0);
}
