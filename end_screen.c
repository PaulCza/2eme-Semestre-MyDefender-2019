/*
** EPITECH PROJECT, 2020
** end_game_screen
** File description:
** display the end game string
*/

#include "include/my.h"

int is_esc(sfEvent event, sfRenderWindow *window)
{
    if (event.type == sfEvtKeyPressed)
        if (event.key.code == sfKeyEscape)
            return (1);
    if (event.type == sfEvtClosed) {
        sfRenderWindow_close(window);
        return (48);
    }
    return (0);
}

int end_game(sfRenderWindow *window, sfEvent event)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (is_esc(event, window) == 1) {
            sfRenderWindow_close(window);
            break;
        }
        if (is_esc(event, window) == 48)
            break;
    }
    return (0);
}

char *set_score(int i)
{
    char *score;
    char *tmp;
    char tmp2[] = "score: \0";

    tmp = my_atoa(i);
    score = my_strconcat(tmp2, tmp);
    return (score);
}

int end_screen(sfEvent event, sfRenderWindow *window, int score)
{
    sfText *text = sfText_create();
    sfSprite *sprite1 = sfSprite_create();
    sfTexture *texture1 = sfTexture_createFromFile
    ("sources/game_over.png", NULL);
    char *str = set_score(score);
    sfFont* font = sfFont_createFromFile("sources/Minecraft.ttf");

    sfText_setString(text, str);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 50);
    sfSprite_setTexture (sprite1, texture1, sfTrue);
    sfRenderWindow_drawSprite(window, sprite1, NULL);
    sfRenderWindow_display(window);
    while (sfRenderWindow_isOpen(window)) {
        end_game(window, event);
        sfRenderWindow_drawText(window, text, NULL);
        sfRenderWindow_display(window);
    }
    return (0);
}