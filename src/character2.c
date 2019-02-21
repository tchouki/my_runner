/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** character2.c
*/

#include "../include/my.h"

void set_character2(character2_t *character2, char *name)
{
    sfImage *i_character2 = sfImage_createFromFile(name);
    character2->t_character2 = sfTexture_createFromImage(i_character2, NULL);
    character2->sp_character2 = sfSprite_create();
    character2->pos.x = 100;
    character2->pos.y = 80;
    character2->scale.x = 4;
    character2->scale.y = 4;
    character2->animation.left = 120;
    character2->animation.top = 0;
    character2->animation.height = 24;
    character2->animation.width = 24;
    character2->jump = 0;
    character2->on_ground = 0;
    character2->death = 0;
    character2->music = sfMusic_createFromFile("music/jump_sound.ogg");
    sfSprite_setPosition(character2->sp_character2, character2->pos);
    sfSprite_setScale(character2->sp_character2, character2->scale);
    sfSprite_setTexture(character2->sp_character2, character2->t_character2,
    sfTrue);
    sfSprite_setTextureRect(character2->sp_character2, character2->animation);
}

void jump_character2(game_t *game)
{
    if ((sfKeyboard_isKeyPressed(sfKeyUp) || sfKeyboard_isKeyPressed(sfKeyZ)) &&
    game->scene1->character2->jump == 0 &&
    game->scene1->character2->on_ground == 0) {
        game->scene1->character2->jump = 1;
        game->scene1->character2->on_ground = 1;
        sfMusic_play(game->scene1->character2->music);
    }
    if (game->scene1->character2->jump == 1 &&
    game->scene1->character2->on_ground == 1) {
        game->scene1->character2->pos.y += 16;
        if (game->scene1->character2->pos.y >= 250)
            game->scene1->character2->jump = 0;
    }
    if (game->scene1->character2->pos.y != 80) {
        game->scene1->character2->animation.left = 264;
        game->scene1->character2->pos.y -= 8;
    }
    if (game->scene1->character2->pos.y == 80)
        game->scene1->character2->on_ground = 0;
}

void move_character2(game_t *game)
{
    static int i = 0;

    if (i == 9) {
        i = 0;
        game->scene1->character2->animation.left += 24;
    }
    i++;
    if (game->scene1->character2->animation.left >= 192)
        game->scene1->character2->animation.left = 120;
    jump_character2(game);
    sfSprite_setTextureRect(game->scene1->character2->sp_character2,
    game->scene1->character2->animation);
    sfRenderWindow_drawSprite(game->window,
    game->scene1->character2->sp_character2, NULL);
    sfSprite_setPosition(game->scene1->character2->sp_character2,
    game->scene1->character2->pos);
}

void kill_character2(game_t *game)
{
    static int i = 1;

    if (i == 9) {
        i = 0;
        game->scene1->character2->animation.left += 24;
    }
    i++;
    if (game->scene1->character2->animation.left >= 408)
        game->s = 0;
    sfSprite_setTextureRect(game->scene1->character2->sp_character2,
    game->scene1->character2->animation);
    sfRenderWindow_drawSprite(game->window,
    game->scene1->character2->sp_character2, NULL);
}