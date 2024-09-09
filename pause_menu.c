/*
** EPITECH PROJECT, 2020
** main_menu
** File description:
** intro screen
*/

#include "include/my.h"

int check_click(sfEvent *event, sfRenderWindow *window)
{
    int x1 = sfMouse_getPositionRenderWindow(window).x;
    int y1 = sfMouse_getPositionRenderWindow(window).y;

    if (event->type == sfEvtMouseButtonPressed) {
        if (x1 < 1100 && x1 > 750 && y1 < 600 && y1 > 480)
            return (0);
        if (x1 < 1100 && x1 > 750 && y1 > 690 && y1 < 800) {
            sfRenderWindow_close(window);
            return (3);
        }
    }
    return (5);
}

int managing_events(sfEvent *event, sfRenderWindow *window)
{
    int a;

    if (event->type == sfEvtClosed) {
        sfRenderWindow_close(window);
        return (3);
    }
    a = check_click(event, window);
    return (a);
}

sfSprite *set_background(sfRenderWindow *window)
{
    sfSprite *sprite1 = sfSprite_create();
    sfTexture *texture1 = sfTexture_createFromFile
    ("sources/pause.jpg", NULL);
    sfSprite_setTexture (sprite1, texture1, sfTrue);
    sfRenderWindow_drawSprite(window, sprite1, NULL);
    sfSprite_destroy(sprite1);
    sfTexture_destroy(texture1);
    return (sprite1);
}

int pause_loop(sfRenderWindow *window, int a)
{
    sfEvent event;

    sfRenderWindow_clear(window, sfBlack);
    set_background(window);
    sfRenderWindow_display(window);
    while (sfRenderWindow_pollEvent(window, &event)){
        a = managing_events(&event, window);
        if (a != 5)
            return (a);
    }
    return (2);
}

int pause_menu(sfRenderWindow *window)
{
    int a = 0;
    int score = 2;

    while (score == 2)
        score = pause_loop(window, a);
    return (score);
}