/*
** EPITECH PROJECT, 2020
** play2
** File description:
** other functions of the play file
*/

#include "include/my.h"

void draw_everything(sfSprite *map, money_t money, text_s text,
                    sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window, map, NULL);
    sfRenderWindow_drawSprite(window, money.dollar, NULL);
    sfRenderWindow_drawText(window, text.texte, NULL);
}

void draw_rec(sfRenderWindow *window, bouton_t hud)
{
    if (hud.flag == -1)
        sfRenderWindow_drawRectangleShape(window, hud.rect, NULL);
}

sfSprite *map_create(sfRenderWindow *window)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile("sources/map2.jpg", NULL);
    sfSprite_setTexture (sprite, texture, sfTrue);
    sfRenderWindow_drawSprite(window, sprite, NULL);
    return (sprite);
}

void player_sets(text_s *text, player_t *player)
{
    sfTime time;
    float seconds;

    time = sfClock_getElapsedTime(player->clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds > 0.1) {
        player->dollar.money = player->dollar.money + 1;
        player->score = player->score + 1;
        sfClock_restart(player->clock);
    }
    *text = ini_text(player->dollar.money);
}