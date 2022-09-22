/*
** EPITECH PROJECT, 2018
** my_rpg : menu_game
** File description:
** handle the menu game
*/

#include "rpg.h"

void pos_init_player(game_t *st)
{
	st->player.map.x = 3;
	st->player.map.y = 3;
	st->player.cord.x = 10;
	st->player.cord.y = 8;
	st->im[0].pos.x = (st->player.cord.x) * 48;
	st->im[0].pos.y = (st->player.cord.y) * 54;
	sfSprite_setPosition(st->im[0].sprite, st->im[0].pos);
}

int my_fight(game_t *st, rpg_t *rpg)
{
	int game = 3;
	int verif = 0;

	sfMusic_pause(rpg->song[5]);
	verif = fight_game(st, rpg);
	st->battle = -1;
	if (verif == 3) {
		sfMusic_play(rpg->song[5]);
		if (rpg->music == 1)
			sfMusic_play(rpg->song[10]);
		st->player.status++;
		maj_map(st, st->map[pt_map(st->player.map)], \
pt_map(st->player.map));
	} else if (verif == 2) {
		if (rpg->music == 1)
			sfMusic_play(rpg->song[11]);
		pos_init_player(st);
	}
	if (verif == -1)
		game = -1;
	return (game);
}

void free_game(game_t *st)
{
	free_map(st->map);
	my_free(st->player.name);
}

int loop_game(game_t *st, rpg_t *rpg, int game)
{
	game = event(rpg, st);
	if (st->player.move != 0) {
		movement_player(st);
		check_move(rpg, st);
	}
	if (st->pause == 1 && game != -1)
		game = check_button_pause(st, rpg);
	if (st->battle != -1 && game != -1)
		game = my_fight(st, rpg);
	if (st->player.status == 6)
		game = 5;
	refresh_game(st, rpg);
	return (game);

}

int game(game_t *st, rpg_t *rpg)
{
	int game = 3;

	if (rpg->music == 1) {
		sfMusic_play(rpg->song[5]);
		sfMusic_setLoop(rpg->song[5], sfTrue);
	}
	if (create_game(st) == 84)
		return (84);
	while (sfRenderWindow_isOpen(rpg->window) && game == 3)
		game = loop_game(st, rpg, game);
	if (game == 6 && write_in_file(&st->player) == 84)
		return (84);
	if (game == 6)
		game = 1;
	sfMusic_stop(rpg->song[5]);
	free_game(st);
	return (game);
}
