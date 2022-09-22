/*
** EPITECH PROJECT, 2018
** my_rpg : fight
** File description:
** handle the menu game
*/

#include "rpg.h"

void stop_fight_game(game_t *st, rpg_t *rpg)
{
	sfMusic_stop(rpg->song[1]);
	my_free(st->fight.str);
}

void song_fight_game(rpg_t *rpg)
{
	if (rpg->music == 1) {
		sfMusic_play(rpg->song[1]);
		sfMusic_setLoop(rpg->song[1], sfTrue);
	}
}

void move_particle(game_t *st)
{
	st->fight.tempo_part[2].time = sfClock_getElapsedTime	\
(st->fight.tempo_part[2].clock);
	st->fight.tempo_part[2].seconds = \
st->fight.tempo_part[2].time.microseconds / 200;
	if (st->fight.tempo_part[2].seconds > 0.1) {
		move_particle_p(&st->fight);
		if (st->fight.display_part_e == 1)
				move_particle_e(&st->fight, st);
		sfClock_restart(st->fight.tempo_part[2].clock);
	}
}

int fight_game(game_t *st, rpg_t *rpg)
{
	int verif = 1;

	song_fight_game(rpg);
	if (create_fight(st) == 84)
		return (84);
	while (sfRenderWindow_isOpen(rpg->window) && verif == 1) {
		change_letter_game(st, rpg);
		verif = event_fight(rpg, st, 2 + st->player.status);
		refresh_fight(&st->fight, rpg, st->battle, st->player.hp);
		move_particle(st);
		if (st->player.hp <= 0)
			verif = 2;
		if (st->fight.mob[st->battle].life <= 0)
			verif = 3;
	}
	stop_fight_game(st, rpg);
	return (verif);
}
