/*
** EPITECH PROJECT, 2018
** move
** File description:
** move
*/

#include "../include/my.h"

void move_rect(sfIntRect *rect, int offset, int max_value)
{
	if (rect->left != max_value) {
		rect->left += offset;
	}
	if (rect->left >= max_value)
		rect->left = 0;
}

void move_rect_end(sfIntRect *rect, int offset, int max_value, int game_on)
{
	static int tempo2 = 0;
	static int tempo = 0;

	if (rect->left != max_value) {
		if (tempo == 10) {
			rect->left += offset;
			tempo = 0;
		}
		tempo++;
	}
	if (rect->left != max_value && game_on == 3) {
		if (tempo == 10) {
			rect->left += offset;
			tempo2 = 0;
		}
		tempo2++;
	}
	if (rect->left >= max_value)
		rect->left = 0;
}

void move_rect_ball(sfIntRect *rect, int offset, int max_value)
{
	if (rect->top != max_value)
		rect->top += offset;
	if (rect->top >= max_value)
		rect->top = 0;
}

void move_player(game_object_t *obj, music_t *music)
{
	if (obj->pos.x >= 1000) {
		obj->speedx = -1.4;
		if (sfMusic_getStatus(music->hit_side) == sfStopped)
			sfMusic_play(music->hit_side);
	}
	if (obj->pos.x <= 0) {
		obj->speedx = 1.4;
		if (sfMusic_getStatus(music->hit_side) == sfStopped)
			sfMusic_play(music->hit_side);
	}
	if (obj->pos.y >= 550) {
		obj->speedy = -1.4;
		if (sfMusic_getStatus(music->hit) == sfStopped)
			sfMusic_play(music->hit);
	}
	if (obj->pos.y <= 0) {
		obj->speedy = 1.4;
		if (sfMusic_getStatus(music->hit_side) == sfStopped)
			sfMusic_play(music->hit_side);
	}
}

void move_sprite(gen_t *gen, music_t *music, int i)
{
	sfVector2f offset = {gen->object[i].pos.x, gen->object[i].pos.y};
	sfVector2f pos_bkg = {0, 0};
	sfVector2f pos_obj = {20, 480};

	check_reset_sprite(&(gen->object[i]), music);
	if (gen->object[i].type == type_obj && gen->object[i].pos.x <= -1400) {
		gen->object[i].pos.x = 0;
		sfSprite_setPosition(gen->object[i].sprite, pos_obj);
	}
	if (gen->object[i].type == type_bkg && gen->object[i].pos.x <= -1200) {
		gen->object[i].pos.x = 0;
		sfSprite_setPosition(gen->object[i].sprite, pos_bkg);
	}
	if (gen->object[i].type != type_score)
		sfSprite_setPosition(gen->object[i].sprite, offset);
	else {
		sfRenderWindow_drawText(gen->window, gen->object[i].text, NULL);
		sfRenderWindow_drawText(gen->window, gen->object[i].score,
					NULL);
	}
}
