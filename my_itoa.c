/*
** EPITECH PROJECT, 2020
** my_itoa
** File description:
** from int to string
*/

#include "include/my.h"

int my_strlen(char *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++)
        i++;
    return (i);
}

char *my_revstr(char *str)
{
    int i = my_strlen(str);
    int y = 0;
    char *tmp2 = malloc(sizeof(char) * (i + 2));

    for (; i > 0; i--) {
        tmp2[y] = str[i - 1];
        y++;
    }
    tmp2[y++] = '\0';
    free(str);
    return (tmp2);
}

char *my_strconcat(char *str1, char *str2)
{
    int first = my_strlen(str1);
    int sec = my_strlen(str2);
    char *final = malloc(sizeof(char) * (first + sec + 1));
    int nb = 0;
    int i = 0;

    for (; i < first; i++)
            final[i] = str1[i];
        i--;
    for (nb = 0; nb < sec; nb++) {
            final[i] = str2[nb];
            i++;
    }
    final[i++] = '\0';

    return (final);
}

char *my_atoa(int i)
{
    char *tmp;
    int len = 0;

    for (int y = i; y > 0; y = y / 10)
        len++;
    tmp = malloc(sizeof(char) * len + 1);
    tmp[len] = '\0';
    while (len--) {
        tmp[len] = i % 10 + 48;
        i = i / 10;
    }
    return (tmp);
}
