/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** inventory.h
*/

#if !defined(INVENTORY_H_)
#define INVENTORY_H_

#include <rpg.h>

t_node *add_node(t_node *node, void *data);
void generate_slots(all_t *data);
void iterate_slots(t_node *inv, all_t *d);
void get_empty_slot(t_node *inv, u_item *item);
void draw_slots(t_node *inv, sfRenderTexture *inv_tex, all_t *d);
void on_click(void *d, struct slot *s, sfRenderWindow *w);
void on_drag(void *d, struct slot *s, sfRenderWindow *w);
void on_hover(void *d, struct slot *s, sfRenderWindow *w);
void init_tooltip(all_t *s_all);

#endif // INVENTORY_H_