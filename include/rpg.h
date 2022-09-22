/*
** EPITECH PROJECT, 2018
** include
** File description:
** rpg
*/

#ifndef __RPG_H__
#define __RPG_H__

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdbool.h>
#include <stdio.h>

struct st_im {
	sfTexture *texture;
	sfSprite *sprite;
	sfVector2f pos;
	sfVector2f cord;
	sfIntRect rect;
	int offset;
	int move;
};

typedef struct st_im im_t;

struct st_button {
	sfRectangleShape *rect;
	sfVector2f size;
	sfVector2f position;
	int click;
};

typedef struct st_button button_t;

struct st_particle {
	sfVector2f pos;
	sfVector2f vect;
	sfVector2f max;
	sfVector2f pos_init;
	int verif;
};

typedef struct st_particle particle_t;

struct st_player {
	int move;
	int tempo_move;
	char *name;
	int gender;
	int class;
	unsigned int hp;
	sfVector2f map;
	sfVector2f cord;
	int status;
};

typedef struct st_player player_t;

struct st_mob {
	im_t im;
	char *name;
	int life;
	int difficulty;
};

typedef struct st_mob mob_t;

struct st_text {
	sfFont *font;
	sfText *text;
	char *str;
	int nb;
	sfVector2f vector;
};

typedef struct st_text text_t;

struct st_tempo {
	sfTime time;
	sfClock *clock;
	float seconds;
};

typedef struct st_tempo tempo_t;

struct st_end {
	im_t im[6];
	tempo_t tempo[2];
	int status;
};

typedef struct st_end end_t;

struct st_intro {
	im_t im[10];
	tempo_t tempo[2];
	int status;
};

typedef struct st_intro intro_t;

struct st_load {
	im_t im[1];
	button_t button[5];
	text_t text;
};

typedef struct st_load load_t;

struct st_fight {
	tempo_t tempo;
	im_t letter[26];
	char *str;
	im_t player;
	im_t background;
	mob_t mob[6];
	text_t text[4];
	int combo;
	im_t im_p[4];
	particle_t part_p[500];
	particle_t part_e[100];
	tempo_t tempo_part[3];
	int display_part_e;
	int gender;
};

typedef struct st_fight fight_t;

struct st_menu {
	im_t im[2];
	button_t button[5];
	tempo_t tempo;
	im_t tuto[3];
};

typedef struct st_menu menu_t;

struct st_new_game {
	im_t im[6];
	button_t button[5];
	text_t text;
	int status;
	int check;
	player_t player;
};

typedef struct st_new_game new_game_t;

struct st_game {
	button_t button[5];
	char ***map;
	im_t talk_pnj[6];
	im_t mobs[6];
	im_t obstacles[4];
	im_t map_s[6][4];
	im_t im[5];
	im_t obj[7];
	tempo_t tempo[1];
	player_t player;
	fight_t fight;
	int battle;
	int display_inventory;
	int display_map;
	int pause;
	int talk;
	int sound;
};

typedef struct st_game game_t;

struct st_mobs {
	im_t im;
	char *name;
	int life;
	int difficulty;
};

typedef struct st_mobs mobs_t;

struct st_scene {
	intro_t intro;
	menu_t menu;
	new_game_t ng;
	game_t game;
	load_t load;
	end_t end;
	tempo_t tempo;
};

typedef struct st_scene scene_t;

struct st_rpg {
	tempo_t tempo;
	sfRenderWindow* window;
	int game;
	sfEvent event;
	int music;
	sfMusic *song[12];
};

typedef struct st_rpg rpg_t;

int destroy_sprite4(scene_t *scene, int i, int j);
int destroy_sprite3(scene_t *scene, int i, int j);
int destroy_sprite2(scene_t *scene, int i, int j);
int destroy_sprite1(scene_t *scene, int i, int j);
void free_map(char ***map);
void	check_letter_game(fight_t *st, char letter, int strength);
void	check_move(rpg_t *rpg, game_t *st);
void	check_button_ng(new_game_t *ng);
int	check_button_pause(game_t *st, rpg_t *rpg);
int end_game(scene_t *scene, rpg_t *rpg);
void refresh_end(end_t *st, rpg_t *rpg, game_t *game);
void move_particle_e(fight_t *st, game_t *game);
void move_particle_p(fight_t *st);
int event_end(rpg_t *rpg);
void create_end(end_t *st);
void status_end(end_t *st);
void change_letter_game(game_t *st, rpg_t *rpg);
int init_end(end_t *st);
int create_fight(game_t *st);
int fight_game(game_t *st, rpg_t *rpg);
int event_fight(rpg_t *rpg, game_t *st, int i);
void refresh_fight(fight_t *st, rpg_t *rpg, int fight, int hp);
int tuto_game(menu_t *menu, rpg_t *rpg);
void refresh_tuto(menu_t *menu, rpg_t *rpg, int game);
int event_tuto(rpg_t *rpg, int game);
void	movement_player(game_t *st);
int	change_map_with_save(game_t *st);
int	game(game_t *st, rpg_t *rpg);
void	movement_map(game_t *st, rpg_t *rpg);
int	event(rpg_t *rpg, game_t *st);
int	create_game(game_t *st);
void	refresh_game(game_t *st, rpg_t *rpg);
int	event_menu(rpg_t *rpg, menu_t *menu, int i);
void	change_name_player(text_t *text, rpg_t *rpg);
int	create_load(load_t *load);
int	load_game(scene_t *scene, rpg_t *rpg);
void	refresh_load(load_t *load, rpg_t *rpg);
int get_save(scene_t *scene, char *str);
void cpy_player(player_t *player1, player_t *player2);
int	event_load(rpg_t *rpg, load_t *load);
int	create_init_menu(new_game_t *ng);
void	refresh_init_menu(new_game_t *ng, rpg_t *rpg);
int	event_init_menu(rpg_t *rpgn, new_game_t *ng);
void	create_intro(intro_t *scene);
int	create_menu(menu_t *menu);
int	event_quit(rpg_t *rpg, int i);
void	refresh_menu(menu_t *menu, rpg_t *rpg);
void	close_game(scene_t *scene, rpg_t *rpg);
int	event_intro(rpg_t *rpg);
char	found_letter(rpg_t *rpg);
char	found_more_letter(rpg_t *rpg);
int	button_is_clicked(button_t *st, sfVector2f clickPosition);
void	choice_character(new_game_t *ng);
int	init_game(game_t *st);
int	init_all_mobs(mob_t *mobs);
int	init_intro(intro_t *intro);
int	init_menu_game(new_game_t *ng, rpg_t *rpg);
int	init_menu(menu_t *menu);
int	init_text(text_t *text, int size);
int	init_fight(fight_t *fight);
void	init_fight_text(fight_t *fight, int i);
int	init_ng(new_game_t *ng);
int	init_button(button_t* button, sfVector2f size, sfVector2f position);
int	init_image(char *path, im_t *im, int verif);
int	init_spr_txt(intro_t *intro);
int	intro_game(scene_t *scene, rpg_t *rpg);
int	menu_game(scene_t *scene, rpg_t *rpg);
void	move_rect(sfIntRect *rect, im_t *im, int top, int heiht);
void	move_background_intro(intro_t *intro);
void	movement_bird(menu_t *menu);
int	my_rpg(rpg_t *rpg, scene_t *scene);
void	refresh_intro(intro_t *st, rpg_t *rpg);
void	status_intro(intro_t *st);
char	**get_from_file(char *path);
int	read_file(char *path);
char	***get_maps(void);
char	**get_map(char *path, int count);
char **get_debugged_map(char *path, int count);
bool	parse_file(char **map);
bool	parse_line(char *line);
char	*convert_int_str(int nb);
void	my_free(void *ptr);
void	my_fputnbr(int nb, FILE *file);
void	my_puterror(char *str);
char	*my_strdup(char *str);
int     my_strlen(char *str);
char	*clean_str(char *str, char cut);
int	my_getnbr(char *str);
int	my_getstr(char *str);
char	*my_strcpy(char *dest, char const *src);
int	my_strcmp(char *s1, char *s2);
int	my_strncmp(char *s1, char *s2, int n);
char	**str_to_word_array(char *str, char c);
int	my_arraylen(char **array);
char	*my_strcat(char *s1, char *s2);
void	my_destroy_im(im_t im);
void	maj_map(game_t *game, char **map, int pos);
int	check_skills(char **data, scene_t *scene);
int	check_items(char **data);
int	check_hp(char **data, scene_t *scene);
int	check_class(char **data, scene_t *scene);
int	check_gender(char **data, scene_t *scene);
int	check_name(char **data, scene_t *scene);
int	check_status(char **data, scene_t *scene);
bool	check_str(char *str, int i);
int	check_data_line(char *dataline, scene_t *scene);
bool	parse_data(char **data, scene_t *scene);
int	pt_map(sfVector2f map);
int	write_in_file(player_t *player);
int	create_file(player_t *player);
char	*get_status(player_t *player);
int	init_song(rpg_t *st);
void	destroy_intro(scene_t *scene);
void	destroy_menu(scene_t *scene);
void	destroy_ng(scene_t *scene);
void	destroy_game(scene_t *scene);
void	destroy_rpg(rpg_t *rpg);
void	destroy_end(scene_t *scene);
void	destroy_load(scene_t *scene);

#endif
