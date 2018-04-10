/*
** EPITECH PROJECT, 2018
** map
** File description:
** map
*/

#include "../include/my.h"

char *path_to_str(char *path)
{
	int file = open(path, O_RDONLY);
	char *str = malloc(sizeof(char) * 4069);
	int off = 0;
	int len = 0;

	if (file < 0) {
		my_putstr("Failed loading the map, please try a valid one\n");
		my_putstr("Valid maps are contained in the maps folder\n");
		my_putstr("Example: ./my_runner maps/basic_map\n");
		return (NULL);
	}
	while ((len = read(file, (void*)str + off, 4069 - off + 1)) > 0) {
		off = off + len;
	}
	return (str);
}

int parse_map(char **map, int *game_on)
{
	int position = 0;

	while (**map != '\0') {
		position += 55;
		if (**map == 'o') {
			*map += 1;
			return (position);
		}
		if (**map == '\n')
			position = 0;
		*map += 1;
	}
	*game_on = 3;
	return (1000);
}

void destroy_object(game_object_t *obj, music_t *music)
{
	sfMusic_destroy(music->song);
	sfMusic_destroy(music->hit);
	sfMusic_destroy(music->hit_side);
	free(obj);
}

int check_help(char *str)
{
	if (*str == '-' && *(str + 1) == 'h' && !(*(str + 2))) {
		print_help(0);
		return (1);
	} else
		return (0);
}

void print_help(int a)
{
	if (a == 0) {
		my_putstr("USAGE\n./my_runner map\n\nOPTIONS\n-h      ");
		my_putstr("print the usage and quit.\n\nINFO\nAvoid ");
		my_putstr("fireballs by accelerating with the ARROW_KEYS\n");
	} else {
		my_putstr("./my_runner:  bad arguments:  0 given but 1");
		my_putstr(" is required\nretry with -h\n");
	}
}
