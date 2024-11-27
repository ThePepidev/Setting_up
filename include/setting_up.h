/*
** EPITECH PROJECT, 2024
** B-CPE-110-LIL-1-1-settingup-mathys1.dupont
** File description:
** setting_up.h
*/

#ifndef SETTING_UP_H
    #define SETTING_UP_H

    #include <unistd.h>
    #include <errno.h>
    #include <stddef.h>
    #include <stdlib.h>
    #include <sys/stat.h>
    #include <fcntl.h>

typedef struct stat_buff_s {
    int len_line;
    int len_column;
    char **buffer;
} stat_buff_t;

int setting_up(int ac, char **av);
stat_buff_t *read_to_string_array(char **av);
int verif_error(int ac, char **av);

#endif /* SETTING_UP_H */
