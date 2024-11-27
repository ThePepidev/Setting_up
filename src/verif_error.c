/*
** EPITECH PROJECT, 2024
** B-CPE-110-LIL-1-1-settingup-mathys1.dupont
** File description:
** verif_error.c
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

static int fs_understand_return_of_read(int fd, char *buffer, int size)
{
    int rd = read(fd, buffer, size);

    if (rd == -1)
        return 84;
    if (rd == 0)
        return 84;
    if (rd < size)
        return 84;
    return 0;
}

static int fs_open_file(char const *filepath)
{
    int fo = open(filepath, O_RDONLY);

    if (fo > 0)
        return fo;
    return -1;
}

static int handle_error(char **av)
{
    long size = get_size_file(av[1]);
    int fd;
    int fr;
    char *buffer = malloc(size + 1);

    if (!buffer)
        return 84;
    if (size == -1)
        return 84;
    fd = fs_open_file(av[1]);
    if (fd == -1) {
        free(buffer);
        return 84;
    }
    fr = fs_understand_return_of_read(fd, buffer, size);
    close(fd);
    free(buffer);
    if (fr != 0)
        return 84;
    return 0;
}

static char *read_string(char **av)
{
    const char *filepath = av[1];
    long size = get_size_file(filepath);
    int fd;
    char *buffer = malloc(size + 1);

    if (!buffer)
        return NULL;
    if (size == -1 || handle_error(av) != 0) {
        return NULL;
    }
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

static int len_nbr(int nb)
{
    int len_nb;

    while (nb >= 1) {
        nb /= 10;
        len_nb++;
    }
    return len_nb;
}

static int strlen_colone(char *buffer)
{
    int j = 0;
    int i = len_nbr(my_getnbr(buffer)) + 1;

    while (buffer[i] != '\n' && buffer[i] != '\0') {
        j++;
        i++;
    }
    return j;
}

int verif_size(char *buffer)
{
    int j = len_nbr(my_getnbr(buffer)) + 1;
    int k = 0;
    int len_colone = strlen_colone(buffer);
    char *next = malloc(len_colone + 1);

    if (!next)
        return 84;
    for (; buffer[j] != '\0';) {
        k = 0;
        for (; buffer[j] != '\n' && buffer[j] != '\0'; j++) {
            next[k] = buffer[j];
            k++;
        }
        next[k] = '\0';
        j++;
        if (my_strlen(next) != len_colone)
            return 84;
    }
    free(next);
    return 0;
}

int verif_char(char *buffer)
{
    int len_nb = len_nbr(my_getnbr(buffer)) + 1;

    for (int i = len_nb; buffer[i]; i++) {
        if (buffer[i] != '.' && buffer[i] != 'o' && buffer[i] != '\n')
            return 84;
    }
    return 0;
}

int verif_error(int ac, char **av)
{
    char *buffer;

    if (ac != 2)
        return 84;
    if (handle_error(av) == 84)
        return 84;
    buffer = read_string(av);
    if (return_woula(buffer) == 84)
        return 84;
    free(buffer);
    return 0;
}
