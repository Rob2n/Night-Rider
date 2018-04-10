/*
** EPITECH PROJECT, 2018
** init
** File description:
** init
*/

#include "../include/my.h"

void init_states(game_object_t *object)
{
	sfVector2f pos_end = {0, 0};

	object[6].pos = pos_end;
	object[0].state = 0;
	object[1].state = 0;
	object[2].state = 0;
	object[3].state = 0;
	object[4].state = 0;
	object[5].state = 2;
	object[6].state = 2;
	object[0].speedy = 0;
	object[1].speedy = 0;
	object[2].speedy = 0;
	object[3].speedy = 0;
	object[4].speedy = 5;
	object[5].speedy = 0;
	object[6].speedy = 0;
	object[4].fptr = &move_sprite;
	object[5].fptr = &move_sprite;
	object[6].fptr = &move_sprite;
}

void init_bis(game_object_t *object)
{
	sfVector2f pos = {-1000, 530};
	sfVector2f pos_obs = {550, -450};
	sfVector2f pos_title = {0, 0};
	sfVector2f pos_bkg = {0, 0};
	sfVector2f pos_road = {20, 480};

	object[0].type = type_bkg;
	object[1].type = type_obj;
	object[2].type = type_player;
	object[3].type = type_obj;
	object[4].type = type_obs;
	object[5].type = type_end;
	object[6].type = type_end;
	object[0].pos = pos_bkg;
	object[1].pos = pos_road;
	object[2].pos = pos;
	object[3].pos = pos_title;
	object[4].pos = pos_obs;
	object[5].pos = pos_bkg;
	init_states(object);
}

void init_car_fly(game_object_t *obj)
{
	sfTexture *texture;

	texture = sfTexture_createFromFile("sprites/delorean_fly.png", NULL);
	sfSprite_setTexture(obj[2].sprite, texture, sfTrue);
}

void init_speeds(game_object_t *object)
{
	sfVector2f pos_end = {10, 10};
	sfIntRect rect_end = {0, 0, 1200, 600};

	object[5] = create_object("sprites/end.png", pos_end, rect_end);
	object[6] = create_object("sprites/win.png", pos_end, rect_end);
	object[0].speedx = -10;
	object[1].speedx = -20;
	object[2].speedx = 10;
	object[3].speedx = 0;
	object[4].speedx = 0;
	object[5].speedx = 0;
	object[6].speedx = 0;
	object[0].fptr = &move_sprite;
	object[1].fptr = &move_sprite;
	object[2].fptr = &move_sprite;
	object[3].fptr = &move_sprite;
	init_bis(object);
}

game_object_t *init_objects(void)
{
	sfVector2f pos = {-1000, 530};
	sfVector2f pos_title = {0, 0};
	sfVector2f pos_bkg = {10, 10};
	sfVector2f pos_obs = {800, -350};
	sfVector2f pos_road = {20, 480};
	sfVector2f pos_score = {900, 480};
	sfIntRect rect = {10, 10, 10, 10};
	sfIntRect rect_car = {0, 0, 200, 59};
	sfIntRect rect_obs = {0, 0, 60, 90};
	game_object_t *object = malloc(sizeof(game_object_t) * 8);

	object[0] = create_object("sprites/bkg.png", pos_bkg, rect);
	object[1] = create_object("sprites/road.png", pos_road, rect);
	object[2] = create_object("sprites/delorean.png", pos, rect_car);
	object[3] = create_object("sprites/title.png", pos_title, rect);
	object[4] = create_object("sprites/fireball.png", pos_obs, rect_obs);
	object[7] = create_score("SCORE: ", pos_score);
	init_speeds(object);
	return (object);
}
