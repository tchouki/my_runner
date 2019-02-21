/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** my_runner.h
*/

#ifndef MY_H_
#define MY_H_

#include <SFML/Graphics/Sprite.h>
#include <SFML/System/Vector2.h>
#include <SFML/System.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFSIZE 9999

typedef struct map {
    char **tab;
    sfTexture *t_map;
    sfSprite *sp_map;
    sfIntRect animation;
    double pos;
} map_t;

typedef struct background {
    sfTexture *t_background;
    sfSprite *sp_background;
} background_t;

typedef struct character {
    sfTexture *t_character;
    sfSprite *sp_character;
    sfIntRect animation;
    sfVector2f pos;
    sfVector2f scale;
    int jump;
    int on_ground;
    int death;
    sfMusic *music;
} character_t;

typedef struct character2 {
    sfTexture *t_character2;
    sfSprite *sp_character2;
    sfIntRect animation;
    sfVector2f pos;
    sfVector2f scale;
    int jump;
    int on_ground;
    int death;
    sfMusic *music;
} character2_t;

typedef struct paralax {
    background_t *first1;
    background_t *second1;
    background_t *first2;
    background_t *second2;
    sfVector2f v1;
    sfVector2f v2;
    sfVector2f v3;
    sfVector2f v4;
} paralax_t;

typedef struct score {
    sfText *text;
    int point;
    sfVector2f pos;
    char *string;
} score_t;

typedef struct scene3 {
    background_t *background1;
    background_t *background2;
    background_t *background3;
    background_t *background4;
    background_t *background5;
} scene3_t;

typedef struct scene2 {
    background_t *background;
    background_t *button1;
    background_t *button2;
    background_t *button3;
    background_t *button4;
    sfTexture *t_character;
    sfSprite *sp_character;
    sfIntRect animation1;
    sfTexture *t_character2;
    sfSprite *sp_character2;
    sfIntRect animation2;
} scene2_t;

typedef struct scene1 {
    paralax_t *paralax;
    character_t *character;
    character2_t *character2;
    score_t *score;
} scene1_t;

typedef struct scene0 {
    background_t *background;
    background_t *button1;
    background_t *button2;
    sfIntRect animation1;
    sfIntRect animation2;
} scene0_t;

typedef struct game {
    sfRenderWindow *window;
    sfVideoMode video_mode;
    sfMusic *music;
    int s;
    map_t *map;
    scene0_t *scene0;
    scene1_t *scene1;
    scene2_t *scene2;
    scene3_t *scene3;
    sfClock *clock;
} game_t;

//background.c
void set_background(background_t *background, char *str);

//character.c
void set_character(character_t *character, char *name);
void jump_character(game_t *game);
void move_character(game_t *game);
void kill_character(game_t *game);

//character2.c
void set_character2(character2_t *character2, char *name);
void jump_character2(game_t *game);
void move_character2(game_t *game);
void kill_character2(game_t *game);

//character_selection.c
void change_cross(game_t *game, sfVector2i pos);
void display_change_character(game_t *game);
void change_character(game_t *game);
void select_sprite(game_t *game);
void accept_character(game_t *game);

//draw_map.c
void choose_down(game_t *game, int i, int j);
void choose_up(game_t *game, int i, int j);
void choose_sprite(game_t *game, int i, int j);
void solo(game_t *game);

//draw_map_infinite.c
void infinite(game_t *game);

//game.c
void set_main(game_t *game);
void play_scene3(game_t *game);
void play_scene2(game_t *game);
void play_scene1(game_t *game);
void play_scene0(game_t *game, char *file);

//main.c
void event(sfRenderWindow *window);
int loop_game(game_t *game, char *file);
int my_window(int helper, char *file);
int main(int argc, char **argv);

//move.c
void check_finish(game_t *game, int x, int y);
void check_character(game_t *game, int x, int y);
void check_character2(game_t *game, int x, int y);
void check_death(game_t *game);

//open_map.c
void set_sprite(map_t *map);
char **put_2d_tab(char **tab, char *buf, int size);
void fs_open_file(map_t *map, char *filepath);

//paralax.c
void set_paralax(paralax_t *paralax, char *str1, char *str2);
void display_paralax(game_t *game);
void move_paralax(game_t *game);

//scene0.c
void set_menu2(scene0_t *scene0, sfVector2f pos1, sfVector2f pos2,
sfVector2f scale);
void set_menu(scene0_t *scene0);
void display_scene0(game_t *game);
void swap_infinite(game_t *game);
void swap_scene(game_t *game, char *file);

//scene1.c
void set_game(scene1_t *scene1);

//scene2.c
void set_button2(scene2_t *scene2);
void set_button(scene2_t *scene2);
void set_character_selection2(scene2_t *scene2, sfImage *i_character,
sfImage *i_character2);
void set_character_selection(scene2_t *scene2);

//scene3.c
void set_helper(scene3_t *scene3);
void display_scene3(game_t *game);

//score.c
char *my_evil_str(char *str);
char *my_putnbr(int nbr);
void set_score(score_t *score);
void display_score(game_t *game);

#endif