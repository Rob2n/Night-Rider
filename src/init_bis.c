/*
** EPITECH PROJECT, 2018
** init_bis
** File description:
** init_bis
*/

#include "../include/my.h"

music_t *init_music(void)
{
	music_t *music = malloc(sizeof(music_t));

	music->song = sfMusic_createFromFile("sound/music.ogg");
	sfMusic_setLoop(music->song, sfTrue);
	music->hit = sfMusic_createFromFile("sound/hit.ogg");
	music->hit_side = sfMusic_createFromFile("sound/hit_side.ogg");
	if (music->song != NULL) {
		sfMusic_play(music->song);
	}
	return (music);
}

gen_t *init_all(char **av)
{
	gen_t *gen = malloc(sizeof(gen_t));
	sfVideoMode mode = {1200, 600, 32};
	game_object_t *object = init_objects();
	music_t *sound = init_music();
	char *map;

        map = path_to_str(av[1]);
	gen->mode = mode;
	gen->object = object;
	gen->sound = sound;
	gen->map = map;
	gen->game_on = 1;
	gen->framerate_limit = 60;
	gen->window = sfRenderWindow_create(gen->mode, "My Runner",
						sfResize | sfClose, NULL);
	sfRenderWindow_setFramerateLimit(gen->window, gen->framerate_limit);
	gen->clock = sfClock_create();
	gen->clock2 = sfClock_create();
	return (gen);
}

float inertia(float pos)
{
	if (pos > 0) {
		return (-0.09);
	}
	if (pos < 0) {
		return (0.09);
	}
	return (0);
}

void create_score_bis(game_object_t *obj, sfFont *font)
{
	obj->score = sfText_create();
	obj->score_str = "00000";
	sfText_setString(obj->score, obj->score_str);
	sfText_setFont(obj->score, font);
	sfText_setCharacterSize(obj->score, 30);
}

game_object_t create_score(char *str, sfVector2f pos_score)
{
	game_object_t obj;
	sfFont *font = sfFont_createFromFile("font.ttf");
	sfVector2f pos = {1000, 550};
	sfVector2f pos2 = {1100, 550};

	obj.text = sfText_create();
	sfText_setString(obj.text, str);
	sfText_setFont(obj.text, font);
	sfText_setCharacterSize(obj.text, 30);
	create_score_bis(&obj, font);
	obj.obj_pos = pos_score;
	obj.pos = pos;
	obj.speedx = 0;
	obj.speedy = 0;
	obj.fptr = &move_sprite;
	obj.state = 0;
	obj.type = type_score;
	sfText_setPosition(obj.text, pos);
	sfText_setPosition(obj.score, pos2);
	return (obj);
}
