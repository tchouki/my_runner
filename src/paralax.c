/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** paralax.c
*/

#include "../include/my.h"

void set_paralax(paralax_t *paralax, char *str1, char *str2)
{
    paralax->first1 = malloc(sizeof(background_t));
    paralax->first2 = malloc(sizeof(background_t));
    paralax->second1 = malloc(sizeof(background_t));
    paralax->second2 = malloc(sizeof(background_t));
    set_background(paralax->first1, str1);
    set_background(paralax->first2, str1);
    set_background(paralax->second1, str2);
    set_background(paralax->second2, str2);
    paralax->v1.x = 0;
    paralax->v1.y = 0;
    paralax->v2.x = 1150;
    paralax->v2.y = 0;
    paralax->v3.x = 0;
    paralax->v3.y = 0;
    paralax->v4.x = 1150;
    paralax->v4.y = 0;
    sfSprite_setPosition(paralax->first1->sp_background, paralax->v1);
    sfSprite_setPosition(paralax->second1->sp_background, paralax->v2);
    sfSprite_setPosition(paralax->first2->sp_background, paralax->v3);
    sfSprite_setPosition(paralax->second2->sp_background, paralax->v4);
}

void display_paralax(game_t *game)
{
    sfSprite_setPosition(game->scene1->paralax->first1->sp_background,
    game->scene1->paralax->v1);
    sfSprite_setPosition(game->scene1->paralax->first2->sp_background,
    game->scene1->paralax->v2);
    sfSprite_setPosition(game->scene1->paralax->second1->sp_background,
    game->scene1->paralax->v3);
    sfSprite_setPosition(game->scene1->paralax->second2->sp_background,
    game->scene1->paralax->v4);
    sfRenderWindow_drawSprite(game->window,
    game->scene1->paralax->first1->sp_background, NULL);
    sfRenderWindow_drawSprite(game->window,
    game->scene1->paralax->first2->sp_background, NULL);
    sfRenderWindow_drawSprite(game->window,
    game->scene1->paralax->second1->sp_background, NULL);
    sfRenderWindow_drawSprite(game->window,
    game->scene1->paralax->second2->sp_background, NULL);
}

void move_paralax(game_t *game)
{
    game->scene1->paralax->v1.x -= 0.25;
    game->scene1->paralax->v2.x -= 0.25;
    game->scene1->paralax->v3.x -= 1;
    game->scene1->paralax->v4.x -= 1;
    if (game->scene1->paralax->v1.x <= -1150)
        game->scene1->paralax->v1.x = 1150;
    if (game->scene1->paralax->v2.x <= -1150)
        game->scene1->paralax->v2.x = 1150;
    if (game->scene1->paralax->v3.x <= -1150)
        game->scene1->paralax->v3.x = 1150;
    if (game->scene1->paralax->v4.x <= -1150)
        game->scene1->paralax->v4.x = 1150;
    display_paralax(game);
}