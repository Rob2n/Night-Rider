/*
** EPITECH PROJECT, 2017
** my
** File description:
** header
*/

#ifndef MY_H_
#define MY_H
#include <SFML/Audio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <SFML/Graphics.h>
#include <SFML/System/Time.h>
#include <SFML/System/Clock.h>
#include <SFML/Audio/Music.h>

typedef enum {
	type_bkg,
	type_player,
	type_obj,
	type_obs,
	type_end,
	type_score,
} ObjectType;

typedef struct game_object game_object_t;

typedef struct music_s {
	sfMusic *hit;
	sfMusic *hit_side;
	sfMusic *song;
} music_t;

typedef struct gen_s {
	sfVideoMode mode;
	sfRenderWindow *window;
	sfEvent event;
	game_object_t *object;
	music_t *sound;
	sfClock *clock;
	sfTime time;
	sfClock *clock2;
	char *map;
	sfTime time2;
	int game_on;
	int framerate_limit;
} gen_t;

struct game_object {
	ObjectType type;
	sfSprite *sprite;
	sfTexture *texture;
	sfIntRect obj_hitbox;
	float speedx;
	float speedy;
	sfVector2f pos;
	sfVector2f obj_pos;
	sfText *text;
	sfText *score;
	char *score_str;
	int state;
	void (*fptr)(gen_t*, music_t*, int);
};

void init_states(game_object_t *object);
void init_bis(game_object_t *object);
void init_car_fly(game_object_t *obj);
void init_speeds(game_object_t *object) ;
game_object_t *init_objects(void);
void move_rect(sfIntRect *rect, int offset, int max_value);
void move_rect_end(sfIntRect *rect, int offset, int max_value, int game_on);
void move_rect_ball(sfIntRect *rect, int offset, int max_value);
void move_player(game_object_t *obj, music_t *music) ;
void move_sprite(gen_t *gen, music_t *music, int i);
void check_reset_sprite(game_object_t *obj, music_t *music);
void check_event(sfRenderWindow *window, sfEvent event, game_object_t *obj,
			int game_on);
void check_hit(game_object_t *obj, int *game_on, music_t *sound);
void end_screen(game_object_t *object, int game_on);
void start_screen(game_object_t *object, int *game_on);
void spawn_fireball(game_object_t *object, char **map, int *game_on);
void clock_handling(gen_t *gen);
void handle_anims(gen_t *gen);
char *increment_score(void);
void handle_score(gen_t *gen);
game_object_t create_object(const char *path_to_spritesheet, sfVector2f pos,
				sfIntRect rect);
void handle_keys(sfEvent event, game_object_t *obj);
void position_score(game_object_t *object);
void game_loop(gen_t *gen);
char *path_to_str(char *path);
int parse_map(char **map, int *game_on);
void destroy_object(game_object_t *obj, music_t *music);
music_t *init_music(void);
gen_t *init_all(char **av);
float inertia(float pos);
void create_score_bis(game_object_t *obj, sfFont *font);
game_object_t create_score(char *str, sfVector2f pos_score);
int check_help(char*);
void print_help(int);
void my_putstr(char*);
#endif
