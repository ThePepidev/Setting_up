/*
** EPITECH PROJECT, 2024
** B-CPE-110-LIL-1-1-settingup-mathys1.dupont
** File description:
** return_woula.c
*/

#include "../include/setting_up.h"

int return_error(char *buffer)
{
    if (!buffer) {
        free(buffer);
        return 84;
    }
    if (verif_char(buffer) == 84) {
        free(buffer);
        return 84;
    }
    if (verif_size(buffer) == 84) {
        free(buffer);
        return 84;
    }
    return 0;
}
