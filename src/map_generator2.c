/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** map_generator2
*/

#include "rpg.h"

char **create_map(void)
{
    int lines = 20;
    int cols = 30;
    char **map = malloc(sizeof(char *) * (lines + 1));
    int i = 0;
    
    for (; i != lines; i++) {
        map[i] = malloc(sizeof(char) * (cols + 1));
        for (int j = 0; j != cols; j++)
            map[i][j] = '0';
        map[i][cols] = '\0';
    }
    map[i] = NULL;

    return (map);
}

void free_map(char **map)
{
    for (int i = 0; map[i] != NULL; i++)
        free(map[i]);
    free(map);
}

char **init_new_random_map(all_t *s_all)
{
    static int i = 0;
    if (i == 0)
        s_all->s_map.map = create_map();
    char **new_map = copy_map(s_all->s_map.map);
    i = 1;

    fill_random_map(s_all->s_map.map);

    for (int i = 0; i != 10; i++)
        simulation_step(s_all->s_map.map, new_map);

    free_map(s_all->s_map.map);

    return (new_map);
}

void generate_random_map2(all_t *s_all, int i, int j, int *x)
{
    if (s_all->s_map.tileset_pos.x >= 32 * s_all->s_map.x - 1) {
        s_all->s_map.tileset_pos.x = 0;
        s_all->s_map.tileset_pos.y += 26;
    }
    if (s_all->s_map.map[i][j] == '0') {
        s_all->s_map.tileset[*x] = malloc(sizeof(tileset_t));
        s_all->s_map.tileset[*x]->tile = sfSprite_create();
        sfSprite_setTexture(s_all->s_map.tileset[*x]->tile,
            s_all->s_map.tileset_tx, sfTrue);
        set_rect_tile(s_all->s_map.tileset[*x], s_all, i, j);
        sfSprite_setPosition(s_all->s_map.tileset[*x]->tile,
            s_all->s_map.tileset_pos);
        s_all->s_map.tileset[*x]->debug =
            init_hitbox_debug(s_all->s_map.tileset[*x]->debug,
            s_all->s_map.tileset_pos, s_all->s_map.tileset[*x]->tile);
        *x += 1;
    }
}

void generate_random_map(all_t *s_all)
{
    s_all->s_map.map = init_new_random_map(s_all);

    int x = 0;
    for (int i = 0; s_all->s_map.map[i] != NULL; i++)
        for (int j = 0; s_all->s_map.map[i][j] != '\0'; j++) {
            generate_random_map2(s_all, i, j, &x);
            s_all->s_map.tileset_pos.x += 32;
        }
    s_all->s_map.tileset[x] = NULL;
}