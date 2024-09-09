/*
** EPITECH PROJECT, 2020
** initialise2
** File description:
** initialisation
*/

#include "include/my.h"

son_t ini_sounds(void)
{
    son_t check;
    check.title = sfMusic_createFromFile("./sources/title_music.ogg");
    check.game = sfMusic_createFromFile("./sources/sc.ogg");
    sfMusic_setLoop(check.title, sfTrue);
    sfMusic_setLoop(check.game, sfTrue);
    return check;
}

money_t ini_money(void)
{
    sfVector2f scale;
    sfVector2f pos;
    money_t check;

    pos.x = 60;
    scale.x = 0.2;
    scale.y = 0.2;
    check.money = 0;
    check.dollar = sfSprite_create();
    check.coin = sfTexture_createFromFile("./sources/coin.png", NULL);
    sfSprite_setTexture(check.dollar, check.coin, sfTrue);
    sfSprite_setScale(check.dollar, scale);
    sfSprite_setPosition(check.dollar, pos);
    return check;
}

text_s ini_text(int i)
{
    text_s test;
    char *str;

    test.texte = sfText_create();
    test.font = sfFont_createFromFile("sources/Minecraft.ttf");
    test.a = i;
    str = my_atoa(test.a);
    sfText_setString(test.texte, str);
    sfText_setFont(test.texte, test.font);
    sfText_setCharacterSize(test.texte, 50);
    free(str);
    return test;
}

void ini_sub_hud(bouton_t *test, int vec, char *str)
{
    test->vec.x = vec;
    test->vec.y = 930;
    test->size.x = 100;
    test->size.y = 100;
    test->texture = sfTexture_createFromFile(str, NULL);
    test->rect = sfRectangleShape_create();
    sfRectangleShape_setTexture(test->rect, test->texture, sfTrue);
    sfRectangleShape_setPosition(test->rect, test->vec);
    sfRectangleShape_setSize(test->rect, test->size);
}

int click_all(bouton_t bouton[5], int x, int y)
{
    int a = 0;

    while (a < 5){
        if (click(bouton[a], x, y) == 1){
            f = a;
            return a;
        }
    a = a + 1;
    }
    return -1;
}