/*
** EPITECH PROJECT, 2020
** play
** File description:
** start the game
*/

#include "include/my.h"

int b = -1;

void check_turrets(bouton_t hud[15], turret_s tourelle[6])
{
    int a = 0;

    while (a < 6){
        if (hud[a + 5].flag != -1 && hud[a + 5].flag != 42){
        tourelle[0].type = hud[a + 5].flag + 1;
        hud[a + 5].flag = 42;
        }
        a = a + 1;
    }
}

void check_slots(bouton_t hud[15], int x, int y)
{
    int a = 5;

    while (a <= 10){
        if (click(hud[a], x, y) == 1){
            hud[a].flag = f;
            break;
        }
        a = a + 1;
    }
}

int analyse_events(sfEvent *event, sfRenderWindow *window, bouton_t hud[15])
{
    if (event->type == sfEvtKeyPressed)
        if (event->key.code == sfKeyEscape)
            return (pause_menu(window));
    if (event->type == sfEvtClosed) {
        sfRenderWindow_close(window);
        return (3);
    }
    if (event->type == sfEvtMouseButtonPressed)
        b = click_all(hud, event->mouseButton.x, event->mouseButton.y);
    if (b != -1 && event->type == sfEvtMouseButtonReleased){
        check_slots(hud, event->mouseButton.x, event->mouseButton.y);
    }
    else if (b == -1 && event->type == sfEvtMouseButtonPressed){
        b = -1;
        f = -1;
    }
    return (0);
}

void draw_rectangles(bouton_t hud[15], sfRenderWindow *window)
{
    sfRenderWindow_drawRectangleShape(window, hud[0].rect, NULL);
    sfRenderWindow_drawRectangleShape(window, hud[1].rect, NULL);
    sfRenderWindow_drawRectangleShape(window, hud[2].rect, NULL);
    sfRenderWindow_drawRectangleShape(window, hud[3].rect, NULL);
    sfRenderWindow_drawRectangleShape(window, hud[4].rect, NULL);
    if (b != -1){
        draw_rec(window, hud[5]);
        draw_rec(window, hud[6]);
        draw_rec(window, hud[7]);
        draw_rec(window, hud[8]);
        draw_rec(window, hud[9]);
        draw_rec(window, hud[10]);
    }
}

int loop(sfRenderWindow *window, sfEvent event, sfMusic *game, bouton_t hud[15])
{
    sfSprite *map = map_create(window);
    enemy1_t enemy1 = create_enemy();
    player_t player;
    player.dollar = ini_money();
    player.score = 1;
    player.clock = sfClock_create();
    text_s text = ini_text(1);
    turret_s tourelle[6];
    ini_turret_uno(tourelle);
    int a;

    sfMusic_play(game);
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        while (sfRenderWindow_pollEvent(window, &event))
            a = analyse_events(&event, window, hud);
        if (a != 0){
            sfMusic_destroy(game);
            return (a);
        }
        clock_enemy(0.1, &enemy1);
        player_sets(&text, &player);
        draw_everything(map, player.dollar, text, window);
        draw_rectangles(hud, window);
        check_turrets(hud, tourelle);
        sfRenderWindow_drawSprite(window, enemy1.sprite, NULL);
        sfRenderWindow_display(window);
        if (sfSprite_getPosition(enemy1.sprite).x > 1920)
            break;
    }
    sfMusic_destroy(game);
    return (player.score);
}