/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** scene0.c
*/

#include "../include/my.h"

char *my_evil_str(char *str)
{
    int count = 0;
    int i = 0;
    int midcount;
    int inter;

    while (str[count] != '\0')
        count++;
    midcount = count/2;
    while (count > midcount) {
        inter = str[count-1];
        str[count-1] = str[i];
        str[i] = inter;
        i++;
        count--;
    }
    return (str);
}

char *my_putnbr(int nbr)
{
    int temp;
    int i = 0;
    char *result = malloc(sizeof(char) * nbr);

    if (nbr == 0) {
        result[i] = '0';
        i++;
    }
    while (nbr > 0) {
        temp = nbr % 10;
        result[i] = temp + 48;
        nbr /= 10;
        i++;
    }
    result[i] = '\0';
    result = my_evil_str(result);
    return (result);
}

void set_score(score_t *score)
{
    score->text = sfText_create();
    score->pos.x = 10;
    score->pos.y = 330;
    score->point = 0;
    score->string = malloc(sizeof(int) * score->point);
    score->string = my_putnbr(score->point);
    sfFont *font = sfFont_createFromFile("font/VCR_OSD_MONO_1.001.ttf");

    sfText_setPosition(score->text, score->pos);
    sfText_setFont(score->text, font);
    sfText_setString(score->text, score->string);
}

void display_score(game_t *game)
{
    game->scene1->score->point += game->map->pos / 100;
    game->scene1->score->string = malloc(sizeof(int) *
    game->scene1->score->point);
    game->scene1->score->string = my_putnbr(game->scene1->score->point);
    sfText_setString(game->scene1->score->text, game->scene1->score->string);
    sfRenderWindow_drawText(game->window, game->scene1->score->text, NULL);
}