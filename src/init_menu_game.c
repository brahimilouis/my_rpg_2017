/*
** EPITECH PROJECT, 2018
** my_rpg : menu_game
** File description:
** handle the menu game
*/

#include "rpg.h"

int init_menu_game(new_game_t *ng, rpg_t *rpg)
{
	int game = 2;
	int verif = 0;

	if (create_init_menu(ng) == 84)
		return (84);
	while (sfRenderWindow_isOpen(rpg->window) && game == 2) {
		verif = event_init_menu(rpg, ng);
		if (verif == 1 && ng->text.str[0] == '\0')
			verif = 0;
		check_button_ng(ng);
		if (verif == -1)
			game = -1;
		else if (verif == 1 && ng->status < 4)
			ng->status++;
		if (ng->status == 4 && game != -1)
			game = 6;
		refresh_init_menu(ng, rpg);
	}
	my_free(ng->text.str);
	return (game);
}
