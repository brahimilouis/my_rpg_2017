/*
** EPITECH PROJECT, 2018
** my_rpg : init_fight
** File description:
** init struct fight
*/

#include "rpg.h"

void init_fight_text(fight_t *fight, int i)
{
	if (i == 0) {
		fight->text[0].vector.x = 600;
		fight->text[0].vector.y = 30;
		init_text(&fight->text[0], 70);
	}
	if (i == 0) {
		fight->text[1].vector.x = 1500;
		fight->text[1].vector.y = 30;
		init_text(&fight->text[1], 70);
	}
	if (i == 0) {
		fight->text[2].vector.x = 600;
		fight->text[2].vector.y = 930;
		init_text(&fight->text[2], 70);
	}
	if (i == 0) {
		fight->text[3].vector.x = 1500;
		fight->text[3].vector.y = 930;
		init_text(&fight->text[3], 70);
	}
}

int init_clock_fight(fight_t *st)
{
	st->tempo.clock = sfClock_create();
	for (int i = 0; i < 3; i++) {
		st->tempo_part[i].clock = sfClock_create();
		if (!st->tempo_part[i].clock)
			return (84);

	}
	if (!st->tempo.clock)
		return (84);
	return (0);
}

int init_fight(fight_t *fight)
{
	int i = 0;
	char *str = my_strdup("png/A.png");

	i = init_all_mobs(fight->mob);
	if (init_clock_fight(fight) == 84)
		return (84);
	for (int j = 0; str[4] != 'Z' + 1; j++) {
		i = init_image(str, &fight->letter[j], i);
		str[4]++;
	}
	i = init_image("png/particles1.png", &fight->im_p[1], i);
	i = init_image("png/particles2.png", &fight->im_p[0], i);
	i = init_image("png/particles3.png", &fight->im_p[2], i);
	i = init_image("png/particles4.png", &fight->im_p[3], i);
	i = init_image("png/player_fight.png", &fight->player, i);
	i = init_image("png/fight.png", &fight->background, i);
	init_fight_text(fight, i);
	return (i);
}
