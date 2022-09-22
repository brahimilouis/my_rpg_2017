/*
** EPITECH PROJECT, 2018
** my_rpg : found_letter
** File description:
** found a letter
*/

#include "rpg.h"

char found_more_letter(rpg_t *rpg)
{
	switch (rpg->event.key.code) {
	case sfKeyN : return ('n');
	case sfKeyO : return ('o');
	case sfKeyP : return ('p');
	case sfKeyQ : return ('q');
	case sfKeyR : return ('r');
	case sfKeyS : return ('s');
	case sfKeyT : return ('t');
	case sfKeyU : return ('u');
	case sfKeyV : return ('v');
	case sfKeyW : return ('w');
	case sfKeyX : return ('x');
	case sfKeyY : return ('y');
	case sfKeyZ : return ('z');
	case sfKeyM : return ('m');
	default : return (0);
	}
}

char found_letter(rpg_t *rpg)
{
	switch (rpg->event.key.code) {
	case sfKeyA : return ('a');
	case sfKeyB : return ('b');
	case sfKeyC : return ('c');
	case sfKeyD : return ('d');
	case sfKeyE : return ('e');
	case sfKeyF : return ('f');
	case sfKeyG : return ('g');
	case sfKeyH : return ('h');
	case sfKeyI : return ('i');
	case sfKeyJ : return ('j');
	case sfKeyK : return ('k');
	case sfKeyL : return ('l');
	case sfKeyBack : return (1);
	default : return (found_more_letter(rpg));
	}
}
