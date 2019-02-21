/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** character_selection.c
*/

#include "../include/my.h"

void change_cross(game_t *game, sfVector2i pos)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) && pos.x >= 175 &&
        pos.x <= 253 && pos.y >= 325 && pos.y <= 381)
        game->scene2->animation1.left -= 24;
    if (sfMouse_isButtonPressed(sfMouseLeft) && pos.x >= 430 &&
        pos.x <= 507 && pos.y >= 325 && pos.y <= 381)
        game->scene2->animation1.left += 24;
    if (sfMouse_isButtonPressed(sfMouseLeft) && pos.x >= 600 &&
        pos.x <= 678 && pos.y >= 325 && pos.y <= 381)
        game->scene2->animation2.left -= 24;
    if (sfMouse_isButtonPressed(sfMouseLeft) && pos.x >= 850 &&
        pos.x <= 928 && pos.y >= 325 && pos.y <= 381)
        game->scene2->animation2.left += 24;
    if (game->scene2->animation1.left < 0)
        game->scene2->animation1.left = 72;
    if (game->scene2->animation1.left > 72)
        game->scene2->animation1.left = 0;
    if (game->scene2->animation2.left < 0)
        game->scene2->animation2.left = 72;
    if (game->scene2->animation2.left > 72)
        game->scene2->animation2.left = 0;
}

void display_change_character(game_t *game)
{
    sfRenderWindow_drawSprite(game->window,
    game->scene2->background->sp_background, NULL);
    sfRenderWindow_drawSprite(game->window,
    game->scene2->sp_character, NULL);
    sfRenderWindow_drawSprite(game->window,
    game->scene2->sp_character2, NULL);
    sfRenderWindow_drawSprite(game->window,
    game->scene2->button1->sp_background, NULL);
    sfRenderWindow_drawSprite(game->window,
    game->scene2->button2->sp_background, NULL);
    sfRenderWindow_drawSprite(game->window,
    game->scene2->button3->sp_background, NULL);
    sfRenderWindow_drawSprite(game->window,
    game->scene2->button4->sp_background, NULL);
}

void change_character(game_t *game)
{
    static int i = 0;

    sfVector2i pos = sfMouse_getPositionRenderWindow(game->window);

    if (i >= 9 && sfMouse_isButtonPressed(sfMouseLeft)) {
        change_cross(game, pos);
        sfSprite_setTextureRect(game->scene2->sp_character,
        game->scene2->animation1);
        sfSprite_setTextureRect(game->scene2->sp_character2,
        game->scene2->animation2);
        i = 0;
    }
    i++;
    display_change_character(game);
}

void select_sprite(game_t *game)
{
    if (game->scene2->animation1.left == 0)
        set_character2(game->scene1->character2,
        "character/dino-green-rev.png");
    if (game->scene2->animation1.left == 24)
        set_character2(game->scene1->character2,
        "character/dino-blue-rev.png");
    if (game->scene2->animation1.left == 48)
        set_character2(game->scene1->character2,
        "character/dino-red-rev.png");
    if (game->scene2->animation1.left == 72)
        set_character2(game->scene1->character2,
        "character/dino-yellow-rev.png");
    if (game->scene2->animation2.left == 0)
        set_character(game->scene1->character, "character/dino-green.png");
    if (game->scene2->animation2.left == 24)
        set_character(game->scene1->character, "character/dino-blue.png");
    if (game->scene2->animation2.left == 48)
        set_character(game->scene1->character, "character/dino-red.png");
    if (game->scene2->animation2.left == 72)
        set_character(game->scene1->character, "character/dino-yellow.png");
}

void accept_character(game_t *game)
{
    static int i = 0;

    if (sfKeyboard_isKeyPressed(sfKeyEnter) && i >= 9) {
        select_sprite(game);
        if (game->s == 2)
            game->s = 1;
        if (game->s == 20)
            game->s = 10;
        i = 0;
    }
    i++;
}