/*
** EPITECH PROJECT, 2018
** my_rpg : write_in_file
** File description:
** write into the file
*/

#include "rpg.h"

char *get_status(player_t *player)
{
	switch (player->status) {
	case 0: return "0\n";
	case 1: return "1\n";
	case 2: return "2\n";
	case 3: return "3\n";
	case 4: return "4\n";
	case 5: return "5\n";
	default: return (NULL);
	}
}

void write_class(player_t *player, FILE *file)
{
	if (player->class == 1)
		fwrite("CLASS:water\n", sizeof(char), 12, file);
	else if (player->class == 2)
		fwrite("CLASS:grass\n", sizeof(char), 12, file);
	else
		fwrite("CLASS:fire\n", sizeof(char), 11, file);
}

int create_file(player_t *player)
{
	char *pwd = my_strcat("saves/", player->name);
	FILE *file = fopen(pwd, "w");
	char *str = my_strcat(my_strcat("NAME:", player->name), "\n");

	if (file == NULL || str == NULL)
		return (84);
	fwrite(str, 1, my_strlen(str), file);
	if (player->gender == 0)
		fwrite("GENDER:boy\n", sizeof(char), 11, file);
	else
		fwrite("GENDER:girl\n", sizeof(char), 12, file);
	write_class(player, file);
	str = my_strcat("STATUS:", get_status(player));
	fwrite(str, 1, my_strlen(str), file);
	fclose(file);
	my_free(pwd);
	my_free(str);
	return (0);
}

int write_in_file(player_t *player)
{
	FILE *file;
	char *pwd = my_strcat("saves/", player->name);

	file = fopen(pwd, "r");
	if (file == NULL) {
		create_file(player);
		return (0);
	}
	fclose(file);
	if (remove(pwd) == -1)
		return (84);
	if (create_file(player) == 84)
		return (84);
	my_free(pwd);
	return (0);
}
