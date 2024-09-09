/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include "include/my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        my_putchar(str[i]);
}

int print_guide(int ac, char **av)
{
    if (ac == 2)
        if (av[1][0] == '-' && av[1][1] == 'h') {
            my_putstr("my_defender usage:\n");
            my_putstr("\nCONTROL:\nclick on a turret ");
            my_putstr("and keep holding into a zone to ");
            my_putstr("place a turret.\n");
            my_putstr("press esc to use the pause mode.\n");
            my_putstr("the objective is to stop the enemy soldiers");
            my_putstr(" before they cross the map.\n\nGOOD LUCK\n");
            return (1);
        }
    return (0);
}

int main(int ac, char **av)
{
    if (print_guide(ac, av) == 1)
        return (0);
    sfRenderWindow *window = the_window(1920, 1080, 64);
    sfEvent event;
    son_t sounds = ini_sounds();
    bouton_t hud[15];
    player_t player;
    ini_hud(hud);
    sfMusic_play(sounds.title);
    int menu = 2;

    while (menu == 2)
        menu = main_menu(window, sounds.title);
    if (menu == 3) {
        sfMusic_destroy(sounds.game);
        return (0);
    }
    menu = loop(window, event, sounds.game, hud);
    sfRenderWindow_display(window);
    while (sfRenderWindow_isOpen(window))
        end_screen(event, window, menu);
}