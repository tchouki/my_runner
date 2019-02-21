/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** open_map.c
*/

#include "../include/my.h"

void set_sprite(map_t *map)
{
    sfImage *i_map = sfImage_createFromFile("map/bloc.png");

    map->t_map = sfTexture_createFromImage(i_map, NULL);
    map->sp_map = sfSprite_create();
    map->animation.left = 0;
    map->animation.top = 0;
    map->animation.height = 100;
    map->animation.width = 100;
    map->pos = 300;
    sfSprite_setTexture(map->sp_map, map->t_map, sfTrue);
    sfSprite_setTextureRect(map->sp_map, map->animation);
}

char **put_2d_tab(char **tab, char *buf, int size)
{
    int x = 0;
    int y = 0;

    tab = malloc(size * sizeof(char *));
    for (int j = 0; j < size; j++)
        tab[j] = malloc(sizeof(char) * BUFFSIZE);
    for (int i = 0; buf[i] != '\0'; i++)
        if (buf[i] == '\n') {
            tab[x][y] = '\n';
            tab[x][y + 1] = '\0';
            y = 0;
            x++;
        } else {
            tab[x][y] = buf[i];
            y++;
        }
    tab[x] = NULL;
    return (tab);
}

void fs_open_file(map_t *map, char *filepath)
{
    int fd;
    int ret;
    char buf[BUFFSIZE];
    int size = 0;
    set_sprite(map);

    fd = open(filepath, O_RDONLY);
    ret = read(fd, buf, BUFFSIZE);
    for (int i = 0; buf[i] != '\0'; i++)
        if (buf[i] == '\n')
            size++;
    close(fd);
    map->tab = put_2d_tab(map->tab, buf, size);
}