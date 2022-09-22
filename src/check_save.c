/*
** EPITECH PROJECT, 2018
** my_rpg : file : check_save
** File description:
** check save
*/

#include "rpg.h"
#include <unistd.h>

int check_skills(char **data, scene_t *scene)
{
	(void)data;
	(void)scene;
	return (0);
}

int check_items(char **data)
{
	if (my_strncmp("ITEMS", data[0], 5) != 0)
		return (0);
	if (my_arraylen(data) == 4)
		if (my_arraylen(data) != 4 || check_str(data[1], 1) == false \
|| check_str(data[2], 1) == false || check_str(data[3], 1) == false) {
		my_puterror("ITEMS:number:number:number.\n");
		return (84);
	}
	return (0);
}

int check_status(char **data, scene_t *scene)
{
	if (my_strncmp("STATUS", data[0], 6) != 0)
		return (0);
	if (scene->ng.player.status != 1234567890 && data[1] != NULL)
		if (scene->ng.player.status == my_getnbr(data[1])) {
			my_puterror("Choose only one status");
			return (84);
		}
	if (my_arraylen(data) != 2 || check_str(data[1], 1) == false) {
		my_puterror("STATUS:(positive number)status of the game.\n");
		return (84);
	}
	scene->ng.player.status = my_getnbr(data[1]);
	return (0);
}

int check_class(char **data, scene_t *scene)
{
	if (my_strncmp("CLASS", data[0], 6) != 0)
		return (0);
	if (scene->ng.player.class != -1 && data[1] != NULL)
		if (scene->ng.player.class == my_getnbr(data[1])) {
			my_puterror("Choose only one class.\n");
			return (84);
		}
	if (my_arraylen(data) != 2 || check_str(data[1], 5) == false) {
		my_puterror("CLASS:water/grass/fire.\n");
		my_puterror("Choose only one class.\n");
		return (84);
	}
	if (my_strcmp("water", data[1]) == 0)
		scene->ng.player.class = 2;
	else if (my_strcmp("grass", data[1]) == 0)
		scene->ng.player.class = 1;
	else
		scene->ng.player.class = 0;
	return (0);
}

int check_gender(char **data, scene_t *scene)
{
	if (my_strncmp("GENDER", data[0], 6) != 0)
		return (0);
	if (scene->ng.player.gender != -1 && data[1] != NULL)
		if (scene->ng.player.gender == my_getnbr(data[1])) {
			my_puterror("Choose only one gender.\n");
			return (84);
		}
	if (my_arraylen(data) != 2 || check_str(data[1], 4) == false) {
		my_puterror("GENDER:(boy/girl).\n");
		return (84);
	}
	if (my_strcmp("boy", data[1]) == 0)
		scene->ng.player.gender = 0;
	else if (my_strcmp("girl", data[1]) == 0)
		scene->ng.player.gender = 1;
	else {
		my_puterror("GENDER:(boy/girl).\n");
		return (84);
	}
	return (0);
}
