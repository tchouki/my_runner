/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** main.c
*/

#include "../include/my.h"

void set_main(game_t *game)
{
    game->map = malloc(sizeof(map_t));
    game->scene0 = malloc(sizeof(scene0_t));
    game->scene1 = malloc(sizeof(scene1_t));
    game->scene2 = malloc(sizeof(scene2_t));
    game->scene3 = malloc(sizeof(scene3_t));
    game->music = sfMusic_createFromFile("music/sound.ogg");
    sfMusic_setVolume(game->music, 40);
    sfMusic_play(game->music);
    game->video_mode.width = 1150;
    game->video_mode.height = 700;
    set_menu(game->scene0);
    set_game(game->scene1);
    set_character_selection(game->scene2);
    set_helper(game->scene3);
    game->s = 0;
    game->clock = sfClock_create();
    game->window = sfRenderWindow_create(game->video_mode, "MyRunner",
    sfDefaultStyle, NULL);
}

void play_scene3(game_t *game)
{
    if (game->s == 3)
        display_scene3(game);
}

void play_scene2(game_t *game)
{
    if (game->s == 2 || game->s == 20) {
        change_character(game);
        accept_character(game);
    }
}

void play_scene1(game_t *game)
{
    if (game->s == 1 || game->s == 10) {
        move_paralax(game);
        if (game->s == 1)
            solo(game);
        if (game->s == 10)
            infinite(game);
        display_score(game);
        check_death(game);
    }
}

void play_scene0(game_t *game, char *file)
{
    if (game->s == 0) {
        swap_scene(game, file);
        swap_infinite(game);
        game->scene1->character->animation.left = 120;
        game->scene1->character->pos.y = 520;
        game->scene1->character->death = 0;
        game->scene1->character2->animation.left = 120;
        game->scene1->character2->pos.y = 80;
        game->scene1->character2->death = 0;
        game->scene1->score->point = 0;
        game->map->pos = 0;
    }
}