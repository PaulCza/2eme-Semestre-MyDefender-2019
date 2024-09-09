/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** macro with all prototypes
*/

#include <SFML/Graphics/RenderWindow.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <stdio.h>
#include "struct.h"
#include <unistd.h>
#include <SFML/Audio/SoundBuffer.h>
#include <SFML/Audio/Sound.h>
#include <SFML/Audio/Music.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stddef.h>
#include <string.h>

int f;
sfRenderWindow* the_window(int width, int height, int bitsPerPixel);
char *my_atoa(int i);
char *my_strconcat(char *str1, char *str2);
int end_screen(sfEvent event, sfRenderWindow *window, int score);
int main_menu(sfRenderWindow *window, sfMusic *title);
sfIntRect test(void);
sfVector2f make_vec(int x, int y);
void init_button(bouton_t *button, char *file);
sfRenderStates make_def_state(void);
void glow_start(sfEvent *event, bouton_t *test);
int loop(sfRenderWindow *window, sfEvent event, sfMusic *game,
bouton_t hud[15]);
son_t ini_sounds(void);
money_t ini_money(void);
text_s ini_text(int i);
enemy1_t *clock_enemy(float i, enemy1_t *enemy);
enemy1_t create_enemy(void);
enemy1_t *move_it(enemy1_t *enemy);
void ini_sub_hud(bouton_t *test, int vec, char *str);
void ini_hud(bouton_t hud[6]);
int click_all(bouton_t bouton[15], int x, int y);
int click(bouton_t bouton, int x, int y);
int click_turret(bouton_t *bouton, int x, int y);
bouton_t ini_slot(int y, int x);
int pause_menu(sfRenderWindow *window);
int chosing(sfEvent *event, sfRenderWindow *window, int i);
void draw_everything(sfSprite *map, money_t money, text_s texte,
sfRenderWindow *window);
void draw_rec(sfRenderWindow *window, bouton_t hud);
sfSprite *map_create(sfRenderWindow *window);
void ini_turret_uno(turret_s tourelle[6]);