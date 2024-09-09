/*
** EPITECH PROJECT, 2020
** enemy1
** File description:
** enemy functions
*/

#include "include/my.h"

enemy1_t *enemy_sprite(enemy1_t *enemy)
{
    if (enemy->rect.left <= 330) {
        enemy->rect.left = 540;
        sfSprite_setTextureRect(enemy->sprite, enemy->rect);
        return (enemy);
    }
    enemy->rect.left = enemy->rect.left - 42;
    sfSprite_setTextureRect(enemy->sprite, enemy->rect);
    return (enemy);
}

enemy1_t *enemy_move(enemy1_t *enemy)
{
    int x = sfSprite_getPosition(enemy->sprite).x;
    int y = sfSprite_getPosition(enemy->sprite).y;

    if (x < 500)
        sfSprite_move(enemy->sprite, enemy->vec1);
    else if (y < 580 && x < 1000)
        sfSprite_move(enemy->sprite, enemy->vec2);
    else
        enemy = move_it(enemy);
    return (enemy);
}

enemy1_t *clock_enemy(float i, enemy1_t *enemy)
{
    sfTime time;
    float seconds;

    time = sfClock_getElapsedTime(enemy->clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds > i) {
        enemy = enemy_sprite(enemy);
        enemy = enemy_move(enemy);
        sfClock_restart(enemy->clock);
    }
    return (enemy);
}

sfIntRect rect_run(void)
{
    sfIntRect rect;

    rect.width = 40;
    rect.height = 50;
    rect.top = 0;
    rect.left = 540;
    return (rect);
}

enemy1_t create_enemy(void)
{
    enemy1_t enemy;
    sfVector2f vec;

    vec.y = 390.0;
    vec.x = 0.0;
    enemy.vec1.x = 5;
    enemy.vec2.y = 5;
    enemy.vec2.x = 5;
    enemy.clock = sfClock_create();
    enemy.sprite = sfSprite_create();
    enemy.texture = sfTexture_createFromFile("sources/run1.png", NULL);
    enemy.rect = rect_run();
    sfSprite_setTexture (enemy.sprite, enemy.texture, sfTrue);
    sfSprite_setTextureRect(enemy.sprite, enemy.rect);
    sfSprite_setPosition(enemy.sprite, vec);
    return (enemy);
}