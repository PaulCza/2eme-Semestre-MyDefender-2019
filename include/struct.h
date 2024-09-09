/*
** EPITECH PROJECT, 2020
** struct.h
** File description:
** all the structures
*/

#include <SFML/Audio.h>

typedef struct  button_s {
    sfRectangleShape *rect;
    sfTexture *texture;
    sfVector2f vec;
    sfVector2f size;
    int flag;
}bouton_t;

typedef struct sonson {
    sfMusic *title;
    sfMusic *game;
    sfMusic *end;
} son_t;

typedef struct money {
    int money;
    sfTexture *coin;
    sfSprite *dollar;
} money_t;

typedef struct text {
    sfText *texte;
    sfFont* font;
    int a;
} text_s;

typedef struct enemy {
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect;
    sfClock *clock;
    sfVector2f vec1;
    sfVector2f vec2;
} enemy1_t;

typedef struct turret {
    int type;
    sfVector2f pos;
    sfIntRect rect;
    sfSprite *sprite;
    sfTexture *texture;
}turret_s;

typedef struct player {
    int score;
    sfClock *clock;
    money_t dollar;
}player_t;