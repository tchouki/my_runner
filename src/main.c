/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** main.c
*/

#include "../include/my.h"

void event(sfRenderWindow *window)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(window);
    sfEvent e;

    while (sfRenderWindow_pollEvent(window, &e)) {
        pos = sfMouse_getPositionRenderWindow(window);
        if (e.type == sfEvtClosed)
            sfRenderWindow_close(window);
    }
}

int loop_game(game_t *game, char *file)
{
    if (sfKeyboard_isKeyPressed(sfKeyEscape))
        game->s = 0;
    play_scene0(game, file);
    play_scene1(game);
    play_scene2(game);
    play_scene3(game);
    sfRenderWindow_display(game->window);
}

int my_window(int helper, char *file)
{
    game_t *game = malloc(sizeof(game_t));
    float delta;

    set_main(game);
    sfRenderWindow_setFramerateLimit(game->window, 60);
    if (helper == 1)
        game->s = 3;
    while (sfRenderWindow_isOpen(game->window)) {
        event(game->window);
        delta = sfClock_restart(game->clock).microseconds;
        if (delta > 10000)
            loop_game(game, file);
        sfMusic_setLoop(game->music, sfTrue);
    }
    sfMusic_destroy(game->music);
    sfMusic_destroy(game->scene1->character->music);
    sfMusic_destroy(game->scene1->character2->music);
    sfRenderWindow_destroy(game->window);
    return (0);
}

int main(int argc, char **argv)
{
    int helper = 0;

    if (argv[1] != NULL) {
        if (argv[1][0] == '-' && argv[1][1] == 'h')
            helper = 1;
    }
    my_window(helper, argv[1]);
    return (0);
}