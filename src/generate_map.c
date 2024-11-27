/*
** EPITECH PROJECT, 2024
** B-CPE-110-LIL-1-1-settingup-mathys1.dupont
** File description:
** generate_map.c
*/

#include "../include/my_printf.h"
#include "../include/setting_up.h"
#include "../include/my.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static void k_reset(int *k, char *patern)
{
    if (*k >= my_strlen(patern))
        *k = 0;
}

static int generate_map_loop(char **buff, stat_buff_t *buffer, char *patern)
{
    int k = 0;

    for (int i = 0; i < buffer->len_line; i++) {
        buff[i] = malloc(sizeof(char) * (buffer->len_column + 1));
        if (!buff[i])
            return 84;
        for (int j = 0; j < buffer->len_column; j++) {
            k_reset(&k, patern);
            buff[i][j] = patern[k];
            k++;
        }
        buff[i][buffer->len_column] = '\0';
    }
    return 0;
}

static stat_buff_t *generate_map(int ac, char **av)
{
    stat_buff_t *buffer = malloc(sizeof(stat_buff_t));
    char *patern = av[2];
    char **buff;

    if (!buffer)
        return NULL;
    if (!patern || my_strlen(patern) == 0)
        return NULL;
    buffer->len_line = my_getnbr(av[1]);
    buffer->len_column = my_getnbr(av[1]);
    if (buffer->len_line <= 0 || buffer->len_column <= 0)
        return NULL;
    buff = malloc(sizeof(char *) * (buffer->len_line + 1));
    if (!buff)
        return NULL;
    generate_map_loop(buff, buffer, patern);
    buff[buffer->len_line] = NULL;
    buffer->buffer = buff;
    return buffer;
}

static int verif_char2(char c)
{
    if (c != '.' && c != 'o')
        return 84;
    return 0;
}

static int verif_buff(char **buffer)
{
    int error = 0;

    for (int i = 0; buffer[i]; i++) {
        for (int j = 0; buffer[i][j]; j++) {
            error += verif_char2(buffer[i][j]);
        }
    }
    return error;
}

static int verif_generation(char **buffer, int len_column, int len_line)
{
    if (!buffer)
        return 84;
    if (verif_buff(buffer) != 0)
        return 84;
    if (len_column != len_line)
        return 84;
    return 0;
}

int handle_generating(int ac, char **av, stat_buff_t *buffer)
{
    buffer = generate_map(ac, av);
    if (!buffer)
        return 84;
    if (verif_generation(buffer->buffer,
        buffer->len_column, buffer->len_line) == 84)
        return 84;
    setting_up_algo(buffer);
    for (int i = 0; buffer->buffer[i]; i++) {
        write(1, buffer->buffer[i], my_strlen(buffer->buffer[i]));
        write(1, "\n", 1);
    }
    for (int i = 0; i < buffer->len_line; i++)
        free(buffer->buffer[i]);
    free(buffer->buffer);
    free(buffer);
    return 0;
}
