/*
** EPITECH PROJECT, 2020
** enemy2
** File description:
** other functions for enemy moving
*/

#include "include/my.h"

enemy1_t *move_it(enemy1_t *enemy)
{
    sfVector2f vect;

    vect.x = 5;
    vect.y = -0.75;
    sfSprite_move(enemy->sprite, vect);
    return (enemy);
}