/*
** EPITECH PROJECT, 2017
** bootstrap_cgraph
** File description:
** main
*/

#include "../include/my.h"

game_object_t create_object(const char *path_to_spritesheet, sfVector2f pos,
			sfIntRect rect)
{
	game_object_t obj;

	obj.texture = sfTexture_createFromFile(path_to_spritesheet,
						NULL);
	obj.sprite = sfSprite_create();
	obj.obj_pos = pos;
	sfSprite_setTexture(obj.sprite, obj.texture, sfTrue);
	sfSprite_setPosition(obj.sprite, pos);
	obj.obj_hitbox = rect;
	return (obj);
}

void handle_keys(sfEvent event, game_object_t *obj)
{
	if (event.key.code == sfKeyRight)
		obj[2].speedx += 1.2;
	if (event.key.code == sfKeyLeft)
		obj[2].speedx -= 1.2;
	if (event.key.code == sfKeyUp)
		obj[2].speedy -= 1.2;
	if (event.key.code == sfKeyDown)
		obj[2].speedy += 1.2;
}

void position_score(game_object_t *object)
{
	sfVector2f pos = {260, 280};
	sfVector2f pos2 = {610, 280};

	sfText_setCharacterSize(object[7].text, 100);
	sfText_setPosition(object[7].text, pos);
	sfText_setCharacterSize(object[7].score, 100);
	sfText_setPosition(object[7].score, pos2);
}

void game_loop(gen_t *gen)
{
	while (sfRenderWindow_pollEvent(gen->window, &(gen->event)))
	{
		check_event(gen->window, gen->event, gen->object, gen->game_on);
	}
	for (int i = 0; i != 8; i++) {
		if (gen->object[i].state != 2 &&
		gen->object[i].type != type_score)
			sfRenderWindow_drawSprite(gen->window,
						gen->object[i].sprite, NULL);
		gen->object[i].fptr(gen, gen->sound, i);
	}
	clock_handling(gen);
	start_screen(gen->object, &(gen->game_on));
	check_hit(gen->object, &(gen->game_on), gen->sound);
	end_screen(gen->object, gen->game_on);
	handle_anims(gen);
	if (gen->game_on == 0 || gen->game_on == 3)
		handle_score(gen);
	sfRenderWindow_display(gen->window);
	sfRenderWindow_clear(gen->window, sfBlack);
}

int main(int ac, char **av)
{
	gen_t *gen = malloc(sizeof(gen));

	if (av[1] && check_help(av[1]) == 0) {
		gen = init_all(av);
		if (!(gen->map)) {
			destroy_object(gen->object, gen->sound);
			return (84);
		}
		while (sfRenderWindow_isOpen(gen->window))
		{
			game_loop(gen);
		}
		destroy_object(gen->object, gen->sound);
		sfRenderWindow_destroy(gen->window);
		return (0);
	}
	if (ac != 2)
		print_help(1);
	return (84);
}
