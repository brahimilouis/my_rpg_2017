/*
** EPITECH PROJECT, 2018
** change_letter_game
** File description:
** ...
*/

#include "rpg.h"

int my_check_letter(char *str, char letter)
{
	int i = 0;

	while (str[i] != '\0') {
		if (str[i] == letter)
			return (0);
		i++;
	}
	return (1);
}

void add_letter(fight_t *st)
{
	char letter = rand() % 26 + 'a';
	int size = my_strlen(st->str);

	if (size == 22)
		return;
	while (my_check_letter(st->str, letter) == 0)
		letter = rand() % 26 + 'a';
	st->str[size] = letter;
	st->str[size + 1] = '\0';
	st->letter[letter - 'a'].cord.x = 182 + size * 73;
	sfSprite_setPosition(st->letter[letter - 'a'].sprite, \
st->letter[letter - 'a'].cord);
}

void init_particle_e(particle_t *part, int i)
{
	part->pos_init.x = 1400;
	part->pos_init.y = 400;
	part->vect.x = -3.45;
	part->vect.y = 1.1;
	part->max.x = 0;
	if (i < 50) {
		part->vect.y += i * 0.05;
		part->max.y = 50 - i;
	} else if (i < 99) {
		i = i - 50;
		part->vect.y -=  i * 0.05;
		part->max.y = 50 - i;
	} else {
		part->vect.x *= 2.5;
		part->vect.y *= 2.5;
	}
	part->pos = part->pos_init;
}

void change_letter_game(game_t *st, rpg_t *rpg)
{
	static int i = 0;

	st->fight.tempo.time = sfClock_getElapsedTime(st->fight.tempo.clock);
	st->fight.tempo.seconds = st->fight.tempo.time.microseconds \
/ (350000 - st->player.status * 35000);
	if (st->fight.tempo.seconds > 1.0) {
		i++;
		add_letter(&st->fight);
		sfClock_restart(st->fight.tempo.clock);
	}
	if (i == 3) {
		if (rpg->music == 1)
			sfMusic_play(rpg->song[3]);
		i = 0;
		for (int j = 0; j < 100; j++)
			init_particle_e(&st->fight.part_e[j], j);
		st->fight.display_part_e = 1;
	}
}
