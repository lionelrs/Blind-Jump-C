/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** clocks2
*/

#include "rpg.h"

void info_clocks(all_t *s_all)
{
    s_all->s_infos.time =
        sfClock_getElapsedTime(s_all->s_infos.clock);
    s_all->s_infos.seconds =
        s_all->s_infos.time.microseconds / 1000000.0;
    s_all->s_infos.hit_tm =
        sfClock_getElapsedTime(s_all->s_infos.hit_clk);
    s_all->s_infos.hit_sec =
        s_all->s_infos.hit_tm.microseconds / 1000000.0;
}