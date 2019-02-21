/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** scene2.c
*/

#include "../include/my.h"

void set_button2(scene2_t *scene2)
{
    set_background(scene2->button1, "menu/button-blue.png");
    set_background(scene2->button2, "menu/button-yellow.png");
    set_background(scene2->button3, "menu/button-orange.png");
    set_background(scene2->button4, "menu/button-green.png");
}

void set_button(scene2_t *scene2)
{
    scene2->button1 = malloc(sizeof(background_t));
    scene2->button2 = malloc(sizeof(background_t));
    scene2->button3 = malloc(sizeof(background_t));
    scene2->button4 = malloc(sizeof(background_t));
    sfVector2f scale = {2, 2};
    sfVector2f pos1 = {175, 325};
    sfVector2f pos2 = {425, 325};
    sfVector2f pos3 = {600, 325};
    sfVector2f pos4 = {850, 325};

    set_button2(scene2);
    sfSprite_setScale(scene2->button1->sp_background, scale);
    sfSprite_setScale(scene2->button2->sp_background, scale);
    sfSprite_setScale(scene2->button3->sp_background, scale);
    sfSprite_setScale(scene2->button4->sp_background, scale);
    sfSprite_setPosition(scene2->button1->sp_background, pos1);
    sfSprite_setPosition(scene2->button2->sp_background, pos2);
    sfSprite_setPosition(scene2->button3->sp_background, pos3);
    sfSprite_setPosition(scene2->button4->sp_background, pos4);
}

void set_character_selection2(scene2_t *scene2, sfImage *i_character,
sfImage *i_character2)
{
    scene2->animation1.top = 0;
    scene2->animation1.left = 0;
    scene2->animation1.height = 24;
    scene2->animation1.width = 24;
    scene2->animation2.top = 0;
    scene2->animation2.left = 0;
    scene2->animation2.height = 24;
    scene2->animation2.width = 24;
    scene2->t_character = sfTexture_createFromImage(i_character, NULL);
    scene2->sp_character = sfSprite_create();
    scene2->t_character2 = sfTexture_createFromImage(i_character2, NULL);
    scene2->sp_character2 = sfSprite_create();
}

void set_character_selection(scene2_t *scene2)
{
    scene2->background = malloc(sizeof(background_t));
    sfImage *i_character = sfImage_createFromFile("menu/character-select.png");
    sfImage *i_character2 = sfImage_createFromFile("menu/character-select.png");
    sfVector2f pos = {250, 250};
    sfVector2f pos2 = {675, 250};
    sfVector2f scale = {8, 8};

    set_character_selection2(scene2, i_character, i_character2);
    sfSprite_setTexture(scene2->sp_character, scene2->t_character, sfTrue);
    sfSprite_setTextureRect(scene2->sp_character, scene2->animation1);
    sfSprite_setScale(scene2->sp_character, scale);
    sfSprite_setPosition(scene2->sp_character, pos);
    sfSprite_setTexture(scene2->sp_character2, scene2->t_character2, sfTrue);
    sfSprite_setTextureRect(scene2->sp_character2, scene2->animation2);
    sfSprite_setScale(scene2->sp_character2, scale);
    sfSprite_setPosition(scene2->sp_character2, pos2);
    set_background(scene2->background, "menu/selection.png");
    set_button(scene2);
}