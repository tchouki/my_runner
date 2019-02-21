/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** scene1.c
*/

#include "../include/my.h"

void set_game(scene1_t *scene1)
{
    scene1->paralax = malloc(sizeof(paralax_t));
    scene1->character = malloc(sizeof(character_t));
    scene1->character2 = malloc(sizeof(character2_t));
    scene1->score = malloc(sizeof(score_t));

    set_paralax(scene1->paralax, "map/back.png", "map/front.png");
    set_score(scene1->score);
}