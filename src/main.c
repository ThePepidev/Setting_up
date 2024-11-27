/*
** EPITECH PROJECT, 2024
** B-CPE-110-LIL-1-1-settingup-mathys1.dupont
** File description:
** main.c
*/

#include "../include/my_printf.h"
#include "../include/setting_up.h"
#include "../include/my.h"

int main(int ac, char **av)
{
    if (ac < 2) {
        my_putstr("too few arguments");
        return 84;
    }
    if (setting_up(ac, av) == 84) {
        return 84;
    }
}
