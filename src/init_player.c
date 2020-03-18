/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_hero
*/

#include "rpg.h"

void init_hero2(all_t *s_all)
{
    s_all->s_player.shadow = sfSprite_create();
    sfSprite_setTexture(s_all->s_player.shadow,
        s_all->s_player.hero_tx, sfTrue);
    s_all->s_player.shadow_pos = (sfVector2f){s_all->s_player.hero_pos.x + 1,
        s_all->s_player.hero_pos.y + 25};
    sfSprite_setPosition(s_all->s_player.shadow, s_all->s_player.shadow_pos);
    sfSprite_setTextureRect(s_all->s_player.shadow,
        (sfIntRect){0, 102, 18, 14});
    s_all->s_player.debug_shadow =
        init_hitbox_debug(s_all->s_player.debug_shadow,
        s_all->s_player.shadow_pos, s_all->s_player.shadow);
}

void init_hero(all_t *s_all)
{
    s_all->s_player.hero_pos = (sfVector2f){render_pos_center(s_all).x - 24,
        render_pos_center(s_all).y + 180};
    create_sprite(&s_all->s_player.hero, &s_all->s_player.hero_tx,
        s_all->s_player.hero_pos, "sprites/game_objects.png");
    s_all->s_player.hero_speed = 3;
    s_all->s_player.hero_clock = sfClock_create();
    s_all->s_player.rect_clock = sfClock_create();
    s_all->s_player.hero_rect = (sfIntRect){406, 109, 20, 31};
    sfSprite_setTextureRect(s_all->s_player.hero, s_all->s_player.hero_rect);
    s_all->s_player.debug = init_hitbox_debug(s_all->s_player.debug,
        s_all->s_player.hero_pos, s_all->s_player.hero);
    init_movement(s_all);
    init_direction(s_all);
    init_hero2(s_all);
}