/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** main.c
*/

#include "../include/my.h"

void set_background(background_t *background, char *str)
{
    sfImage *i_background = sfImage_createFromFile(str);
    background->t_background = sfTexture_createFromImage(i_background, NULL);
    background->sp_background = sfSprite_create();
    sfSprite_setTexture(background->sp_background, background->t_background,
    sfTrue);
}