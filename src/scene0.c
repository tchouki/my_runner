/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** scene0.c
*/

#include "../include/my.h"

void set_menu2(scene0_t *scene0, sfVector2f pos1, sfVector2f pos2,
sfVector2f scale)
{
    sfSprite_setPosition(scene0->button1->sp_background, pos1);
    sfSprite_setPosition(scene0->button2->sp_background, pos2);
    sfSprite_setScale(scene0->button1->sp_background, scale);
    sfSprite_setScale(scene0->button2->sp_background, scale);
}

void set_menu(scene0_t *scene0)
{
    scene0->background = malloc(sizeof(background_t));
    scene0->button1 = malloc(sizeof(background_t));
    scene0->button2 = malloc(sizeof(background_t));
    sfVector2f pos1 = {430, 250};
    sfVector2f pos2 = {430, 380};
    sfVector2f scale = {1.5, 1.5};
    scene0->animation1.height = 48;
    scene0->animation1.width = 190;
    scene0->animation1.left = 0;
    scene0->animation1.top = 0;
    scene0->animation2.height = 48;
    scene0->animation2.width = 190;
    scene0->animation2.left = 0;
    scene0->animation2.top = 0;
    set_background(scene0->background, "menu/menu-sans-boutton.png");
    set_background(scene0->button1, "menu/solo.png");
    set_background(scene0->button2, "menu/versus.png");
    set_menu2(scene0, pos1, pos2, scale);
}

void display_scene0(game_t *game)
{
    sfSprite_setTextureRect(game->scene0->button1->sp_background,
    game->scene0->animation1);
    sfSprite_setTextureRect(game->scene0->button2->sp_background,
    game->scene0->animation2);
    sfRenderWindow_drawSprite(game->window,
    game->scene0->background->sp_background, NULL);
    sfRenderWindow_drawSprite(game->window,
    game->scene0->button1->sp_background, NULL);
    sfRenderWindow_drawSprite(game->window,
    game->scene0->button2->sp_background, NULL);
}

void swap_infinite(game_t *game)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(game->window);

    if (pos.x >= 430 && pos.x <= 715 && pos.y >= 380 && pos.y <= 452) {
        game->scene0->animation2.left = 190;
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            fs_open_file(game->map, "level/level1.txt");
            game->s = 20;
        }
    }
    display_scene0(game);
}

void swap_scene(game_t *game, char *file)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(game->window);

    game->scene0->animation1.left = 0;
    game->scene0->animation2.left = 0;
    if (pos.x >= 430 && pos.x <= 715 && pos.y >= 250 && pos.y <= 322) {
        game->scene0->animation1.left = 190;
        if (sfMouse_isButtonPressed(sfMouseLeft) && file[0] != '-') {
            fs_open_file(game->map, file);
            game->s = 2;
        } else if (sfMouse_isButtonPressed(sfMouseLeft)) {
            fs_open_file(game->map, "level/level1.txt");
            game->s = 2;
        }
    }
    if (sfKeyboard_isKeyPressed(sfKeyH))
        game->s = 3;
    display_scene0(game);
}