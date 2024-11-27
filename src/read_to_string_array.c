/*
** EPITECH PROJECT, 2024
** B-CPE-110-LIL-1-1-settingup-mathys1.dupont
** File description:
** read_to_string_array.c
*/

#include "../include/my_printf.h"
#include "../include/setting_up.h"
#include "../include/my.h"

static long get_size_file(const char *filename)
{
    struct stat st;

    if (stat(filename, &st) == 0)
        return st.st_size;
    return -1;
}

static char *read_string(char **av)
{
    const char *filepath = av[1];
    long size = get_size_file(filepath);
    int fd;
    char *buffer = malloc(size + 1);

    if (!buffer)
        return NULL;
    fd = open(filepath, O_RDONLY);
    if (fd == -1) {
        free(buffer);
        return NULL;
    }
    read(fd, buffer, size);
    buffer[size] = '\0';
    close(fd);
    return buffer;
}

static int strlen_array(char *buffer)
{
    return my_getnbr(buffer);
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

static int strlen_colone(char *buffer)
{
    int j = 0;
    int i = len_nbr(strlen_array(buffer)) + 1;

    while (buffer[i] != '\n' && buffer[i] != '\0') {
        j++;
        i++;
    }
    return j;
}

static stat_buff_t *create_buff_struct(char **buff,
    int len_line, int len_column)
{
    stat_buff_t *buffer = malloc(sizeof(stat_buff_t));

    buffer->buffer = buff;
    buffer->len_line = len_line;
    buffer->len_column = len_column;
    return buffer;
}

static int put_array(char *buffer, char **buff, int *j, int i)
{
    int k = 0;

    while (buffer[*j] != '\n' && buffer[*j] != '\0') {
        buff[i][k] = buffer[*j];
        k++;
        (*j)++;
    }
    return k;
}

static void end_string(char **buff, int i, int k, int *j)
{
    buff[i][k] = '\0';
    (*j)++;
}

static void end_array(char **buff, stat_buff_t *buffer_s, char *buffer)
{
    buffer_s->buffer = buff;
    free(buffer);
}

stat_buff_t *read_to_string_array(char **av)
{
    char *buffer = read_string(av);
    int j = len_nbr(strlen_array(buffer)) + 1;
    int len_line = strlen_array(buffer);
    char **buff = malloc(sizeof(char *) * (len_line + 1));
    stat_buff_t *buffer_s = create_buff_struct(buff,
        len_line, strlen_colone(buffer));
    int k;

    if (!buffer)
        return NULL;
    for (int i = 0; i < len_line; i++) {
        buff[i] = malloc(sizeof(char) * (strlen_colone(buffer) + 1));
        if (!buff[i])
            return NULL;
        k = put_array(buffer, buff, &j, i);
        end_string(buff, i, k, &j);
    }
    buff[len_line] = NULL;
    end_array(buff, buffer_s, buffer);
    return buffer_s;
}
