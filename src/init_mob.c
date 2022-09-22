/*
** EPITECH PROJECT, 2018
** init
** File description:
** mob
*/

#include "rpg.h"

int init_mob(mob_t *mob, int difficulty, char *name, int life)
{
	char *sprite = malloc(sizeof(char *) * (22));
	int verif = 0;

	sprite = my_strcat("mobs/", name);
	sprite = my_strcat(sprite, ".png");
	verif = init_image(sprite, &mob->im, verif);
	mob->name = malloc(sizeof(char) * (my_strlen(name) + 1));
	mob->name = my_strcpy(mob->name, name);
	mob->life = life;
	mob->difficulty = difficulty;
	free(sprite);
	return (verif);
}

int init_all_mobs(mob_t *mobs)
{
	int verif = 0;
	int i = 0;

	while (verif != 84 && i < 6) {
		switch (i) {
		case 0: verif = init_mob(&mobs[0], 100, "Taupelle", 100);
			break;
		case 1: verif = init_mob(&mobs[1], 200, "Octopoulpe", 200);
			break;
		case 2: verif = init_mob(&mobs[2], 300, "BrownBull", 300);
			break;
		case 3:	verif = init_mob(&mobs[3], 400, "DumRose", 400);
			break;
		case 4: verif = init_mob(&mobs[4], 500, "MonkeyDLuffy", 500);
			break;
		case 5: verif = init_mob(&mobs[5], 600, "CinnaLion", 600);
			break;
		}
		i++;
	}
	return (verif);
}
