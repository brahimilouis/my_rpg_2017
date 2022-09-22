/*
** EPITECH PROJECT, 2017
** event
** File description:
** ......
*/

#include "rpg.h"

void init_particle_p(particle_t *part, int i)
{
	part->verif = 1;
	part->pos.x = 350;
	part->pos.y = 700;
	part->vect.x = 3.45;
	part->vect.y = -1.05;
	part->max.x = 0;
	part->max.y = -1;
	if (i < 50) {
		part->vect.y -= i * 0.05;
		part->max.y = 50 - i;
	} else if (i < 99) {
		i = i - 50;
		part->vect.y +=  i * 0.05;
		part->max.y = 50 - i;
	} else {
		part->vect.x *= 2.5;
		part->vect.y *= 2.5;
	}
}

void search_particle_p(fight_t *st)
{
	int i = 0;
	int j;
	int k = 0;

	while (i < 5) {
		if (st->part_p[i * 100].verif == 0)
			break;
		i++;
	}
	j = i * 100;
	i = j + 100;
	while (j < i && j < 500) {
		init_particle_p(&st->part_p[j], k);
		j++;
		k++;
	}
}

void check_lette_game(fight_t *st, char letter, int strength, rpg_t *rpg)
{
	if (letter < 'a')
		return;
	if (st->str[0] == letter) {
		if (rpg->music == 1)
			sfMusic_play(rpg->song[8]);
		st->combo++;
		search_particle_p(st);
		st->mob[strength - 2].life -= strength + st->combo / 4;
	} else {
		if (rpg->music == 1)
			sfMusic_play(rpg->song[9]);
		st->combo = 0;
	}
	for (int i = 1; st->str[i] != '\0'; i++) {
		st->letter[st->str[i] - 'a'].cord.x -= 73;
		sfSprite_setPosition(st->letter[st->str[i] - 'a']	\
.sprite, st->letter[st->str[i] - 'a'].cord);
		st->str[i - 1] = st->str[i];
	}
	st->str[my_strlen(st->str) - 1] = '\0';
}

int event_fight(rpg_t *rpg, game_t *st, int i)
{
	while (sfRenderWindow_pollEvent(rpg->window, &rpg->event)) {
		if (rpg->event.type == sfEvtClosed)
			return (-1);
		if (rpg->event.key.type == sfEvtKeyPressed)
			check_lette_game(&st->fight, found_letter(rpg), i, rpg);
	}
	return (1);
}
