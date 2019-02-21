/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** move.c
*/

#include "../include/my.h"

void check_finish(game_t *game, int x, int y)
{
    if (game->map->tab[x][y] == 'F' && game->scene1->character->pos.x >=
        (y * 100 - game->map->pos))
        game->scene1->character2->death = 2;
}

void check_character(game_t *game, int x, int y)
{
    if (game->map->tab[x][y] == 'X' && game->scene1->character->pos.x >=
    (y * 100 - game->map->pos - 50) && game->scene1->character->pos.x <=
    (y * 100 - game->map->pos + 50) &&
    game->scene1->character->pos.y == 520) {
        game->scene1->character->death = 1;
        game->scene1->character->animation.left = 336;
    }
}

void check_character2(game_t *game, int x, int y)
{
    if (game->map->tab[x][y] == 'W' && game->scene1->character2->pos.x >=
    (y * 100 - game->map->pos - 50) && game->scene1->character2->pos.x <=
    (y * 100 - game->map->pos + 50) &&
    game->scene1->character2->pos.y == 80) {
        game->scene1->character2->death = 1;
        game->scene1->character2->animation.left = 336;
    }
}

void check_death(game_t *game)
{
    if (!game->scene1->character->death)
        move_character(game);
    if (!game->scene1->character2->death)
        move_character2(game);
    for (int x = 0; game->map->tab[x] != NULL; x++) {
        for (int y = 0; game->map->tab[x][y] != '\0'; y++) {
            check_character(game, x, y);
            check_character2(game, x, y);
            check_finish(game, x, y);
        }
    }
    if (game->scene1->character2->death == 2)
        game->s = 0;
    if (game->scene1->character->death == 1)
        kill_character(game);
    if (game->scene1->character2->death == 1)
        kill_character2(game);
}