/*
** EPITECH PROJECT, 2019
** window
** File description:
** display a window
*/

#include "./include/my.h"

sfRenderWindow* the_window(int width, int height, int bitsPerPixel)
{
    sfRenderWindow *window;
    sfVideoMode video_mode;

    video_mode.width = width;
    video_mode.height = height;
    video_mode.bitsPerPixel = bitsPerPixel;

    window = sfRenderWindow_create(video_mode,
    "Halo arcade", sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(window, 100);
    return (window);
}
