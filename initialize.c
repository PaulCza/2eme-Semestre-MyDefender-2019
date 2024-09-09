/*
** EPITECH PROJECT, 2020
** initialise
** File description:
** initialisation
*/

#include "include/my.h"

void ini_hud(bouton_t hud[15])
{
    ini_sub_hud(&hud[0], 200, "sources/turret_01_bouton.png");
    ini_sub_hud(&hud[1], 300, "sources/turret_02_bouton.png");
    ini_sub_hud(&hud[2], 400, "sources/turret_03_bouton.png");
    ini_sub_hud(&hud[3], 500, "sources/turret_04_bouton.png");
    ini_sub_hud(&hud[4], 600, "sources/turret_04_bouton.png");
    hud[5] = ini_slot(520, 200);
    hud[6] = ini_slot(600, 400);
    hud[7] = ini_slot(700, 700);
    hud[8] = ini_slot(380, 800);
    hud[9] = ini_slot(380, 1000);
    hud[10] = ini_slot(380, 1200);
}