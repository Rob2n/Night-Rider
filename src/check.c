/*
** EPITECH PROJECT, 2018
** check
** File description:
** check
*/

#include "../include/my.h"

void check_reset_sprite(game_object_t *obj, music_t *music)
{
	if (obj->type == type_player && obj->state == 1) {
		move_player(obj, music);
		obj->speedx += inertia(obj->speedx);
		obj->speedy += inertia(obj->speedy);
	}
	if (obj->type == type_obs && obj->pos.y >= 500) {
		obj->speedx = -20;
		obj->speedy = 0;
	}
	obj->pos.x += obj->speedx;
	obj->pos.y += obj->speedy;
}

void check_event(sfRenderWindow *window, sfEvent event, game_object_t *obj,
		int game_on)
{
	if (event.type == sfEvtClosed)
		sfRenderWindow_close(window);
	if (event.type == sfEvtKeyPressed &&
	event.key.code == sfKeyEscape && (game_on == 2 || game_on == 3))
		sfRenderWindow_close(window);
	if (event.type == sfEvtKeyPressed && obj[2].state == 1)
		handle_keys(event, obj);
}

void check_hit(game_object_t *obj, int *game_on, music_t *sound)
{
	sfFloatRect pos1 = sfSprite_getGlobalBounds(obj[4].sprite);
	sfFloatRect pos2 = sfSprite_getGlobalBounds(obj[2].sprite);

	if (sfFloatRect_intersects(&pos1, &pos2, NULL) == sfTrue) {
		*game_on = 2;
		obj[5].state = 0;
		if (sfMusic_getStatus(sound->hit) == sfStopped)
			sfMusic_play(sound->hit);
	}
}

void end_screen(game_object_t *object, int game_on)
{
	static int tempo = 0;

	if (game_on == 3) {
		tempo++;
	}
	if (tempo == 400 && game_on == 3) {
		object[0].speedx = -7;
		object[1].speedx = -16;
		object[6].state = 0;
	}
	if (game_on == 2 || (tempo == 250 && game_on == 3)) {
		position_score(object);
	}
}

void start_screen(game_object_t *object, int *game_on)
{
	if (object[2].state == 0) {
		if (object[2].pos.x >= 10) {
			object[2].speedx += -0.055;
		}
		if (object[2].speedx <= -9) {
			object[2].speedx = 0;
			object[2].state = 1;
			object[3].state = 2;
			*game_on = 0;
			init_car_fly(object);
		}
	}
}
