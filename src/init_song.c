/*
** EPITECH PROJECT, 2018
** init
** File description:
** song
*/

#include "rpg.h"

int init_song(rpg_t *st)
{
	st->song[0] = sfMusic_createFromFile("music/end.ogg");
	st->song[1] = sfMusic_createFromFile("music/figth theme.ogg");
	st->song[2] = sfMusic_createFromFile("music/footstep.ogg");
	st->song[3] = sfMusic_createFromFile("music/hurtsong.ogg");
	st->song[4] = sfMusic_createFromFile("music/introduction.ogg");
	st->song[5] = sfMusic_createFromFile("music/main themes.ogg");
	st->song[6] = sfMusic_createFromFile("music/wind.ogg");
	st->song[7] = sfMusic_createFromFile("music/song_click.ogg");
	st->song[8] = sfMusic_createFromFile("music/sword.ogg");
	st->song[9] = sfMusic_createFromFile("music/wrong.ogg");
	st->song[10] = sfMusic_createFromFile("music/victory.ogg");
	st->song[11] = sfMusic_createFromFile("music/lose.ogg");
	for (int i = 0; i < 12; i++)
		if (st->song[i] == NULL)
			return (84);
	st->music = 1;
	return (0);
}
