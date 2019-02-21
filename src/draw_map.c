/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** open_map.c
*/

#include "../include/my.h"

void choose_down(game_t *game, int i, int j)
{
    if (game->map->tab[i][j] == 'O') {
        if (game->map->tab[i][j + 1] == 'X')
            game->map->animation.left = 0;
        else if (game->map->tab[i][j - 1] == 'X')
            game->map->animation.left = 200;
        else
            game->map->animation.left = 300;
        game->map->animation.top = 100;
    }
    if (game->map->tab[i][j] == 'X') {
        game->map->animation.left = 100;
        game->map->animation.top = 100;
    }
}

void choose_up(game_t *game, int i, int j)
{
    if (game->map->tab[i][j] == 'P') {
        if (game->map->tab[i][j + 1] == 'W')
            game->map->animation.left = 0;
        else if (game->map->tab[i][j - 1] == 'W')
            game->map->animation.left = 200;
        else
            game->map->animation.left = 300;
        game->map->animation.top = 0;
    }
    if (game->map->tab[i][j] == 'W') {
        game->map->animation.left = 100;
        game->map->animation.top = 0;
    }
}

void choose_sprite(game_t *game, int i, int j)
{
    sfVector2f pos = {j * 100 - game->map->pos, i * 100};

    game->map->animation.height = 100;
    game->map->animation.width = 100;
    choose_down(game, i, j);
    choose_up(game, i, j);
    if (game->map->tab[i][j] == '.') {
        game->map->animation.left = 400;
    }
    sfSprite_setTexture(game->map->sp_map, game->map->t_map, sfTrue);
    sfSprite_setTextureRect(game->map->sp_map, game->map->animation);
    sfSprite_setPosition(game->map->sp_map, pos);
    sfRenderWindow_drawSprite(game->window, game->map->sp_map, NULL);
}

void solo(game_t *game)
{
    for (int i = 0; game->map->tab[i] != NULL; i++)
        for (int j = 0; game->map->tab[i][j] != '\n'; j++)
            choose_sprite(game, i, j);
    game->map->pos += 4;
}