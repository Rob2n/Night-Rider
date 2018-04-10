/*
** EPITECH PROJECT, 2018
** handling
** File description:
** handling
*/

#include "../include/my.h"

void spawn_fireball(game_object_t *object, char **map, int *game_on)
{
	object[4].pos.x = parse_map(map, game_on);
	object[4].pos.y = -200;
	object[4].speedx = 0;
	object[4].speedy = 5;
}

void clock_handling(gen_t *gen)
{
	gen->time = sfClock_getElapsedTime(gen->clock);
	gen->time2 = sfClock_getElapsedTime(gen->clock2);
	if (gen->time.microseconds / 1000000.0 > 0.1) {
		move_rect(&(gen->object[2].obj_hitbox), 200, 400);
		move_rect_ball(&(gen->object[4].obj_hitbox), 100, 400);
		move_rect_end(&(gen->object[5].obj_hitbox), 1200, 2400,
				gen->game_on);
		move_rect_end(&(gen->object[6].obj_hitbox), 1200, 2400,
				gen->game_on);
		sfClock_restart(gen->clock);
	}
	if (gen->time2.microseconds / 1000000.0 > 3.4 && gen->game_on == 0) {
		spawn_fireball(gen->object, &(gen->map), &(gen->game_on));
		sfClock_restart(gen->clock2);
	}
}

void handle_anims(gen_t *gen)
{
	sfSprite_setTextureRect(gen->object[2].sprite,
				gen->object[2].obj_hitbox);
	sfSprite_setTextureRect(gen->object[4].sprite,
				gen->object[4].obj_hitbox);
	sfSprite_setTextureRect(gen->object[5].sprite,
				gen->object[5].obj_hitbox);
	sfSprite_setTextureRect(gen->object[6].sprite,
				gen->object[6].obj_hitbox);
}

char *increment_score(void)
{
	static char str[] = "00000";

	str[4]++;
	for (int i = 4; i != 1; i--) {
		if (str[i] > '9') {
			str[i] = '0';
			str[i - 1]++;
		}
	}
	return (str);
}

void handle_score(gen_t *gen)
{
	char *str;
	static int j = 0;
	static int i = 0;

	if (gen->game_on == 3)
		j++;
	if (j > 360)
		i = 0;
	i++;
	if (i > 5) {
		str = increment_score();
		i = 0;
		gen->object[7].score_str = str;
		sfText_setString(gen->object[7].score,
				gen->object[7].score_str);
	}
}
