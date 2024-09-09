/*
** EPITECH PROJECT, 2020
** initialise3
** File description:
** initialisation
*/

#include "include/my.h"

int click(bouton_t bouton, int x, int y)
{
        if (x < bouton.vec.x + bouton.size.x && y < bouton.vec.y + bouton.size.y
        && x > bouton.vec.x && y > bouton.vec.y)
            return 1;
    return 0;
}

int click_turret(bouton_t *bouton, int x, int y)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue){
        if (x < bouton->vec.x + bouton->size.x && y
        < bouton->vec.y + bouton->size.y
        && x > bouton->vec.x && y > bouton->vec.y){
            bouton->flag = f;
            f = -1;
            return 1;
        }
    }
    return 0;
}

bouton_t ini_slot(int y, int x)
{
    bouton_t test;

    test.vec.y = y;
    test.vec.x = x;
    test.size.y = 100;
    test.size.x = 100;
    test.rect = sfRectangleShape_create();
    test.texture = sfTexture_createFromFile("sources/turret_marker.png", NULL);
    sfRectangleShape_setPosition(test.rect, test.vec);
    sfRectangleShape_setSize(test.rect, test.size);
    sfRectangleShape_setTexture(test.rect, test.texture, sfTrue);
    test.flag = -1;
    return test;

}

sfVector2f ini_vector(int y, int x)
{
    sfVector2f vec;

    vec.x = x;
    vec.y = y;
    return vec;
}

void ini_turret_uno(turret_s tourelle[6])
{
    tourelle[0].type = -1;
    tourelle[1].type = -1;
    tourelle[2].type = -1;
    tourelle[3].type = -1;
    tourelle[4].type = -1;
    tourelle[5].type = -1;
    tourelle[0].pos = ini_vector(520, 200);
    tourelle[1].pos = ini_vector(600, 400);
    tourelle[2].pos = ini_vector(700, 700);
    tourelle[3].pos = ini_vector(380, 800);
    tourelle[4].pos = ini_vector(380, 1000);
    tourelle[5].pos = ini_vector(380, 1200);
}