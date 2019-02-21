/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** draw_map_infinite.c
*/

#include "../include/my.h"

void infinite(game_t *game)
{
    static int speed = 0;

    for (int i = 0; game->map->tab[i] != NULL; i++)
        for (int j = 0; game->map->tab[i][j] != '\n'; j++)
            choose_sprite(game, i, j);
    if (speed == 2)
        game->map->pos += 8;
    if (speed == 1)
        game->map->pos += 6;
    if (speed == 0)
        game->map->pos += 4;
    if (game->map->pos >= 4450 && speed == 1)
        speed = 2;
    if (game->map->pos >= 4450 && speed == 0)
        speed = 1;
    if (game->map->pos >= 4450)
        game->map->pos = 0;
}