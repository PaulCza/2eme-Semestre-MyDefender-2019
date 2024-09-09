/*
** EPITECH PROJECT, 2020
** main_menu
** File description:
** intro screen
*/

#include "include/my.h"

int check_start(sfEvent *event, sfRenderWindow *window, int i)
{
    int x1 = sfMouse_getPositionRenderWindow(window).x;
    int y1 = sfMouse_getPositionRenderWindow(window).y;

    if (event->type == sfEvtKeyPressed)
        return (chosing(event, window, i));
    if (event->type == sfEvtMouseButtonPressed) {
        if (x1 < 1100 && x1 > 750 && y1 < 600 && y1 > 480)
            return (1);
        if (x1 < 1100 && x1 > 750 && y1 > 690 && y1 < 800) {
            sfRenderWindow_close(window);
            return (3);
        }
    }
    return (i);
}

sfSprite *set_the_position(sfSprite *sprite, int i)
{
    sfVector2f vec1;
    sfVector2f vec2;

    vec1.x = 680;
    vec1.y = 500;
    vec2.x = 680;
    vec2.y = 700;
    if (i == 7)
        sfSprite_setPosition(sprite, vec1);
    if (i == 8)
        sfSprite_setPosition(sprite, vec2);
    return (sprite);
}

int manage_events(sfEvent *event, sfRenderWindow *window, int i)
{
    int a;
    if (event->type == sfEvtClosed) {
        sfRenderWindow_close(window);
        return (3);
    }
    a = check_start(event, window, i);
    return (a);
}

sfSprite *set_back(sfRenderWindow *window, int i)
{
    sfSprite *sprite1 = sfSprite_create();
    sfTexture *texture1 = sfTexture_createFromFile
    ("sources/image.jpg", NULL);
    sfSprite *sprite2 = sfSprite_create();
    sfTexture *texture2 = sfTexture_createFromFile
    ("sources/cursor.png", NULL);

    sprite2 = set_the_position(sprite2, i);
    sfSprite_setTexture(sprite2, texture2, sfTrue);
    sfSprite_setTexture(sprite1, texture1, sfTrue);
    sfRenderWindow_drawSprite(window, sprite1, NULL);
    sfRenderWindow_drawSprite(window, sprite2, NULL);
    sfSprite_destroy(sprite1);
    sfTexture_destroy(texture1);
    sfSprite_destroy(sprite2);
    sfTexture_destroy(texture2);
    return (sprite1);
}

int main_menu(sfRenderWindow *window, sfMusic *title)
{
    sfEvent event;
    static int i = 7;

    sfRenderWindow_clear(window, sfBlack);
    set_back(window, i);
    sfRenderWindow_display(window);
    while (sfRenderWindow_pollEvent(window, &event)){
        i = manage_events(&event, window, i);
        if (i == 1 || i == 3) {
            sfMusic_destroy(title);
            return (i);
        }
    }
    return (2);
}