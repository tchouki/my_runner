/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** scene3.c
*/

#include "../include/my.h"

void set_helper(scene3_t *scene3)
{
    scene3->background1 = malloc(sizeof(background_t));
    scene3->background2 = malloc(sizeof(background_t));
    scene3->background3 = malloc(sizeof(background_t));
    scene3->background4 = malloc(sizeof(background_t));
    scene3->background5 = malloc(sizeof(background_t));
    set_background(scene3->background1, "menu/helper1.png");
    set_background(scene3->background2, "menu/helper2.png");
    set_background(scene3->background3, "menu/helper3.png");
    set_background(scene3->background4, "menu/helper4.png");
    set_background(scene3->background5, "menu/helper5.png");
}

void display_scene3(game_t *game)
{
    sfRenderWindow_drawSprite(game->window,
    game->scene3->background5->sp_background, NULL);
    if (sfKeyboard_isKeyPressed(sfKeyUp))
        sfRenderWindow_drawSprite(game->window,
        game->scene3->background2->sp_background, NULL);
    if (sfKeyboard_isKeyPressed(sfKeyDown))
        sfRenderWindow_drawSprite(game->window,
        game->scene3->background3->sp_background, NULL);
    if (sfKeyboard_isKeyPressed(sfKeyZ))
        sfRenderWindow_drawSprite(game->window,
        game->scene3->background1->sp_background, NULL);
    if (sfKeyboard_isKeyPressed(sfKeyS))
        sfRenderWindow_drawSprite(game->window,
        game->scene3->background4->sp_background, NULL);
    if (sfKeyboard_isKeyPressed(sfKeyEnter))
        game->s = 0;
}