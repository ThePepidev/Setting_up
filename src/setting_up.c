/*
** EPITECH PROJECT, 2024
** B-CPE-110-LIL-1-1-settingup-mathys1.dupont
** File description:
** setting_up.c
*/

#include "../include/my_printf.h"
#include "../include/setting_up.h"
#include "../include/my.h"
#include <stdio.h>

int setting_up(int ac, char **av)
{
    stat_buff_t *buffer;

    if (verif_error(ac, av) == 84) {
        return 84;
    }
    buffer = read_to_string_array(av);
    if (!buffer->buffer)
        return 84;
    for (int i = 0; buffer->buffer[i] != NULL; i++)
        my_printf("%s\n", buffer->buffer[i]);
    free(buffer);
    return 0;
}
