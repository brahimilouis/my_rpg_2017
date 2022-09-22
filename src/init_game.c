/*
** EPITECH PROJECT, 2018
** init
** File description:
** game
*/

#include "rpg.h"

int init_map_game(game_t *st, int verif)
{
	int i = 0;
	int j = 0;
	char *str = malloc(sizeof(char) * (16));

	str = my_strcpy(str, "map/map 0-0.jpg");
	while (j < 6) {
		verif = init_image(str, &st->map_s[j][i], verif);
		i++;
		if (i == 4) {
			i = 0;
			j++;
			str[8] = str[8] + 1;
		}
		str[10] = i + '0';
	}
	free(str);
	return (verif);
}

int init_obstacles_mobs_game(game_t *st, int i)
{
	i = init_image("obstacles/obstacle 1.png", &st->obstacles[0], i);
	i = init_image("obstacles/obstacle 2.png", &st->obstacles[1], i);
	i = init_image("obstacles/obstacle 3.png", &st->obstacles[2], i);
	i = init_image("obstacles/obstacle 4.png", &st->obstacles[3], i);
	i = init_image("mobs/mob 1.png", &st->mobs[0], i);
	i = init_image("mobs/mob 2.png", &st->mobs[1], i);
	i = init_image("mobs/mob 3.png", &st->mobs[2], i);
	i = init_image("mobs/mob 4.png", &st->mobs[3], i);
	i = init_image("mobs/mob 5.png", &st->mobs[4], i);
	i = init_image("mobs/mob 6.png", &st->mobs[5], i);
	return (i);
}

int init_obj_game(game_t *st, int i)
{
	i = init_image("obj/obj 1.png", &st->obj[0], i);
	i = init_image("obj/obj 2.png", &st->obj[1], i);
	i = init_image("obj/obj 3.png", &st->obj[2], i);
	i = init_image("obj/obj 4.png", &st->obj[3], i);
	i = init_image("obj/obj 5.png", &st->obj[4], i);
	i = init_image("obj/obj 6.png", &st->obj[5], i);
	i = init_image("obj/obj 7.png", &st->obj[6], i);
	return (i);
}

int init_game(game_t *st)
{
	int i = 0;

	i = init_map_game(st, i);
	i = init_obstacles_mobs_game(st, i);
	i = init_obj_game(st, i);
	i = init_image("png/perso_game.png", &st->im[0], i);
	i = init_image("png/carte.png", &st->im[1], i);
	i = init_image("png/perso.png", &st->im[2], i);
	i = init_image("png/Pause.png", &st->im[3], i);
	i = init_image("png/cross.png", &st->im[4], i);
	i = init_image("png/pnj_0.png", &st->talk_pnj[0], i);
	i = init_image("png/pnj_1.png", &st->talk_pnj[1], i);
	i = init_image("png/pnj_2.png", &st->talk_pnj[2], i);
	i = init_image("png/pnj_3.png", &st->talk_pnj[3], i);
	i = init_image("png/pnj_4.png", &st->talk_pnj[4], i);
	i = init_image("png/pnj_5.png", &st->talk_pnj[5], i);
	st->talk = 0;
	st->tempo[0].clock = sfClock_create();
	if (!st->tempo[0].clock)
		return (84);
	return (i);
}
