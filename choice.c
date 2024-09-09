/*
** EPITECH PROJECT, 2020
** chosing
** File description:
** moving cursor with keyboard
*/

#include "include/my.h"

int chosing(sfEvent *event, sfRenderWindow *window, int i)
{
    if (event->key.code == sfKeyEnter) {
        if (i == 7)
            return (1);
        if (i == 8) {
            sfRenderWindow_close(window);
            return (3);
        }
    }
    if (event->key.code == sfKeyUp)
        i = 7;
    if (event->key.code == sfKeyDown)
        i = 8;
    return (i);
}