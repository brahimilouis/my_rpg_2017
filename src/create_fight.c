/*
** EPITECH PROJECT, 2018
** create
** File description:
** fight
*/

#include "rpg.h"

void create_text_fight(game_t *st)
{
	for (int i = 0; i < 26; i++)
		st->fight.letter[i].cord.y = 125;
	sfText_setString(st->fight.text[0].text, \
st->fight.mob[st->battle].name);
	sfText_setString(st->fight.text[1].text, \
convert_int_str(st->fight.mob[st->battle].life));
	sfText_setString(st->fight.text[2].text, st->player.name);
	sfText_setString(st->fight.text[3].text, \
convert_int_str(100 + st->player.status * 50));
	sfSprite_setPosition(st->fight.player.sprite, st->fight.player.pos);
	st->fight.player.offset = st->player.class * 427;
	st->fight.player.move = 427 + st->player.gender;
	move_rect(&st->fight.player.rect, &st->fight.player, \
st->player.gender * 705, 705 * (st->player.gender + 1));
	sfSprite_setTextureRect(st->fight.player.sprite, st->fight.player.rect);
}

int create_time_fight(game_t *st)
{
	st->fight.tempo.seconds = 0;
	st->fight.tempo.clock = sfClock_create();
	for (int i = 0; i < 3; i++) {
		st->fight.tempo_part[i].seconds = 0;
		st->fight.tempo_part[i].clock = sfClock_create();
		if (!st->fight.tempo_part[i].clock)
			return (84);

	}
	if (!st->fight.tempo.clock)
		return (84);
	return (0);
}

void init_all_part(game_t *st)
{
	for (int i = 0; i < 500; i++) {
		st->fight.part_p[i].verif = 0;
		st->fight.part_p[i].pos.x = 0;
		st->fight.part_p[i].pos.y = 0;
		st->fight.part_p[i].vect.x = 0;
		st->fight.part_p[i].vect.y = 0;
	}
}

int create_fight(game_t *st)
{
	init_all_part(st);
	st->fight.gender = st->player.class;
	st->fight.display_part_e = 0;
	st->fight.combo = 0;
	st->player.hp = 100 + st->battle * 50;
	st->fight.str = malloc(sizeof(char) * (27));
	if (st->fight.str == NULL)
		return (84);
	st->fight.str[0] = '\0';
	st->fight.player.pos.x = 150;
	st->fight.player.pos.y = 400;
	create_text_fight(st);
	if (create_time_fight(st) == 84)
		return (84);
	for (int i = 0; i < 6; i++)
		st->fight.mob[i].life = (i + 1) * 100;
	return (0);
}
