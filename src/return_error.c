/*
** EPITECH PROJECT, 2024
** B-CPE-110-LIL-1-1-settingup-mathys1.dupont
** File description:
** return_woula.c
*/

#include "../include/setting_up.h"
#include "../include/my.h"

int return_read_error(char *buffer, int size)
{
    if (!buffer) {
        free(buffer);
        return 84;
    }
    if (size == -1) {
        free(buffer);
        return 84;
    }
}

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

static int len_nbr(int nb)
{
    int len_nb = 0;

    while (nb >= 1) {
        nb /= 10;
        len_nb++;
    }
    return len_nb;
}

int verif_line_nb(char *buffer)
{
    int my_len_line = 0;
    int len_line = my_getnbr(buffer);
    int i = len_nbr(my_getnbr(buffer)) + 1;

    for (; buffer[i]; i++) {
        if (buffer[i] == '\n')
            my_len_line++;
    }
    if (len_line != my_len_line)
        return 84;
    return 0;
}
