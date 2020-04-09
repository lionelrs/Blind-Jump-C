/*
** EPITECH PROJECT, 2020
** Defender_v1
** File description:
** event_controll
*/

#include "rpg.h"

void events_control(all_t *s_all)
{
    if (s_all->s_game.event.type == sfEvtClosed ||
        sfKeyboard_isKeyPressed(sfKeyEscape)) {
        sfRenderWindow_close(s_all->s_game.window);
    }
    get_movement(s_all);
    get_aim_direction(s_all);
    activate_debug_mode(s_all);
    if (is_key_released(&s_all->s_game.event, sfKeyP))
        add_weapon(s_all->s_game.inventory.inv, create_pistol());
    if (is_key_released(&s_all->s_game.event, sfKeyO))
        add_weapon(s_all->s_game.inventory.inv, create_scorpion());
}