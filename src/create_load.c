/*
** EPITECH PROJECT, 2018
** create
** File description:
** load
*/

#include "rpg.h"

int create_load(load_t *load)
{
	load->text.vector.x = 500;
	load->text.vector.y = 500;
	if (init_text(&load->text, 150) == 84)
		return (84);
	return (0);
}
