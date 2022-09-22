##
## EPITECH PROJECT, 2017
## my_rpg : Makefile
## File description:
## compiles
##

SRCS	=	src/my_strcat.c			\
		src/my_getnbr.c			\
		src/str_to_word_array.c		\
		src/my_strcmp.c			\
		src/my_strncmp.c		\
		src/clean_str.c			\
		src/my_strdup.c			\
		src/my_puterror.c		\
		src/my_strlen.c			\
		src/my_arraylen.c		\
		src/my_strcpy.c			\
		src/my_destroy_im.c		\
		src/my_free.c			\
		src/main.c			\
		src/convert_int_str.c		\
		src/my_rpg.c			\
		src/move_background_intro.c	\
		src/create_intro.c		\
		src/event_intro.c		\
		src/intro_game.c		\
		src/refresh_intro.c		\
		src/init_spr_txt.c		\
		src/status_intro.c		\
		src/close_game.c		\
		src/menu_game.c			\
		src/create_menu.c		\
		src/refresh_menu.c		\
		src/tuto_game.c			\
		src/refresh_tuto.c		\
		src/event_tuto.c		\
		src/event_quit.c		\
		src/movement_bird.c		\
		src/move_rect.c			\
		src/init_button.c		\
		src/create_init_menu.c		\
		src/refresh_init_menu.c		\
		src/init_menu_game.c		\
		src/event_init_menu.c		\
		src/init_text.c			\
		src/found_letter.c		\
		src/file/get_from_file.c	\
		src/file/parse_file.c		\
		src/choice_character.c		\
		src/check_button_ng.c		\
		src/button_is_clicked.c		\
		src/event_menu.c		\
		src/get_save.c			\
		src/check_save.c		\
		src/game.c			\
		src/movement_map.c		\
		src/event.c			\
		src/refresh_game.c		\
		src/pt_map.c			\
		src/init_game.c			\
		src/create_game.c		\
		src/movement_player.c		\
		src/write_in_file.c		\
		src/maj_map.c			\
		src/change_map_with_save.c	\
		src/load_game.c			\
		src/refresh_load.c		\
		src/event_load.c		\
		src/create_load.c		\
		src/init_fight.c		\
		src/fight_game.c		\
		src/event_fight.c		\
		src/refresh_fight.c		\
		src/create_fight.c		\
		src/init_mob.c			\
		src/check_button_pause.c	\
		src/change_letter_game.c	\
		src/end_game.c			\
		src/refresh_end.c		\
		src/status_end.c		\
		src/create_end.c		\
		src/event_end.c			\
		src/init_end.c			\
		src/free_map.c			\
		src/move_particle.c		\
		src/init_song.c			\
		src/destroy_rpg.c		\
		src/destroy_scene.c		\

OBJS	=	$(SRCS:.c=.o)

CFLAGS	+=	-I./include

CFLAGS	+=	-W -Wall -Wextra -Wshadow

LIB	=	-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -Iinclude

NAME	=	my_rpg

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) -o $(NAME) $(OBJS) $(LIB)
		rm $(OBJS)

clean:
		rm -f $(OBJS)

fclean	:	clean
		rm -f $(NAME)

re:		fclean all

debug:		CFLAGS += -g
debug:		re
