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

static void cast_int_suite(int i, stat_buff_t *buffer, int **buff)
{
    for (int j = 0; j < buffer->len_column; j++) {
        if (buffer->buffer[i][j] == 'o')
            buff[i + 1][j + 1] = 0;
        if (buffer->buffer[i][j] == '.')
            buff[i + 1][j + 1] = 1;
    }
}

static int cast_int(stat_buff_t *buffer)
{
    int **buff = malloc(sizeof(int *) * (buffer->len_line + 1));

    if (!buff)
        return 84;
    for (int i = 0; i < buffer->len_line + 1; i++) {
        buff[i] = malloc(sizeof(int) * (buffer->len_column + 1));
        if (!buff[i])
            return 84;
        for (int j = 0; j < buffer->len_column + 1; j++) {
            buff[i][j] = 0;
        }
    }
    for (int i = 0; i < buffer->len_line; i++) {
        cast_int_suite(i, buffer, buff);
    }
    buffer->matrix = buff;
}

static int find_min(int **matrix, int i, int j)
{
    int top = matrix[i - 1][j];
    int left = matrix[i][j - 1];
    int diag = matrix[i - 1][j - 1];
    int min_value = top;

    if (left < min_value)
        min_value = left;
    if (diag < min_value)
        min_value = diag;
    return min_value + 1;
}

static void find_square_loop(int i, stat_buff_t *buffer, int **buff)
{
    for (int j = 1; j < buffer->len_column + 1; j++) {
        if (buffer->matrix[i][j] == 1)
            buff[i][j] = find_min(buffer->matrix, i, j);
        else
            buff[i][j] = 0;
    }
}

static void find_square(stat_buff_t *buffer)
{
    int **buff = buffer->matrix;

    for (int i = 1; i < buffer->len_line + 1; i++) {
        find_square_loop(i, buffer, buff);
    }
}

static void find_max_loop(int i, stat_buff_t *buffer, max_t *max, int **matrix)
{
    for (int j = 0; j < buffer->len_column + 1; j++){
        if (matrix[i][j] > max->max) {
            max->max = matrix[i][j];
            max->y = i;
            max->x = j;
        }
    }
}

static max_t *find_max(int **matrix, stat_buff_t *buffer)
{
    max_t *max = malloc(sizeof(max_t));

    if (!max)
        return NULL;
    max->max = 0;
    for (int i = 0; i < buffer->len_line + 1; i++) {
        find_max_loop(i, buffer, max, matrix);
    }
    max->y--;
    max->x--;
    return max;
}

static void update_buffer(stat_buff_t *buffer)
{
    max_t *max = find_max(buffer->matrix, buffer);

    for (int i = max->y; i > (max->y - max->max); i--) {
        for (int j = max->x; j > (max->x - max->max); j--) {
            buffer->buffer[i][j] = 'x';
        }
    }
    free(max);
}

int setting_up_algo(stat_buff_t *buffer)
{
    cast_int(buffer);
    find_square(buffer);
    update_buffer(buffer);
    for (int i = 0; i < buffer->len_line + 1; i++)
        free(buffer->matrix[i]);
    free(buffer->matrix);
}

int setting_up(int ac, char **av)
{
    stat_buff_t *buffer;

    if (ac >= 3) {
        if (handle_generating(ac, av, buffer) == 84)
            return 84;
        return 0;
    }
    if (verif_error(ac, av) == 84) {
        return 84;
    }
    buffer = read_to_string_array(av);
    setting_up_algo(buffer);
    for (int i = 0; buffer->buffer[i]; i++) {
        my_printf("%s\n", buffer->buffer[i]);
    }
    for (int i = 0; i < buffer->len_line; i++)
        free(buffer->buffer[i]);
    free(buffer->buffer);
    free(buffer);
    return 0;
}
