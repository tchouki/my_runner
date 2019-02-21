/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** character.c
*/

#include "../include/my.h"

void set_character(character_t *character, char *name)
{
    sfImage *i_character = sfImage_createFromFile(name);
    character->t_character = sfTexture_createFromImage(i_character, NULL);
    character->sp_character = sfSprite_create();
    character->pos.x = 100;
    character->pos.y = 520;
    character->scale.x = 4;
    character->scale.y = 4;
    character->animation.left = 120;
    character->animation.top = 0;
    character->animation.height = 24;
    character->animation.width = 24;
    character->jump = 0;
    character->on_ground = 0;
    character->death = 0;
    character->music = sfMusic_createFromFile("music/jump_sound.ogg");
    sfSprite_setPosition(character->sp_character, character->pos);
    sfSprite_setScale(character->sp_character, character->scale);
    sfSprite_setTexture(character->sp_character, character->t_character,
    sfTrue);
    sfSprite_setTextureRect(character->sp_character, character->animation);
}

void jump_character(game_t *game)
{
    if ((sfKeyboard_isKeyPressed(sfKeyDown) || sfKeyboard_isKeyPressed(sfKeyS))
    && game->scene1->character->jump ==
    0 && game->scene1->character->on_ground == 0) {
        game->scene1->character->jump = 1;
        game->scene1->character->on_ground = 1;
        sfMusic_play(game->scene1->character->music);
    }
    if (game->scene1->character->jump == 1 &&
    game->scene1->character->on_ground == 1) {
        game->scene1->character->pos.y -= 16;
        if (game->scene1->character->pos.y <= 350)
            game->scene1->character->jump = 0;
    }
    if (game->scene1->character->pos.y != 520) {
        game->scene1->character->animation.left = 264;
        game->scene1->character->pos.y += 8;
    }
    if (game->scene1->character->pos.y == 520)
        game->scene1->character->on_ground = 0;
}

void move_character(game_t *game)
{
    static int i = 0;

    if (i == 9) {
        i = 0;
        game->scene1->character->animation.left += 24;
    }
    i++;
    if (game->scene1->character->animation.left >= 192)
        game->scene1->character->animation.left = 120;
    jump_character(game);
    sfSprite_setTextureRect(game->scene1->character->sp_character,
    game->scene1->character->animation);
    sfRenderWindow_drawSprite(game->window,
    game->scene1->character->sp_character, NULL);
    sfSprite_setPosition(game->scene1->character->sp_character,
    game->scene1->character->pos);
}

void kill_character(game_t *game)
{
    static int i = 1;

    if (i == 9) {
        i = 0;
        game->scene1->character->animation.left += 24;
    }
    i++;
    if (game->scene1->character->animation.left >= 408)
        game->s = 0;
    sfSprite_setTextureRect(game->scene1->character->sp_character,
    game->scene1->character->animation);
    sfRenderWindow_drawSprite(game->window,
    game->scene1->character->sp_character, NULL);
}