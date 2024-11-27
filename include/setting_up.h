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
    /// @brief
    int **matrix;
} stat_buff_t;

typedef struct max_s {
    int max;
    int y;
    int x;
} max_t;

int setting_up(int ac, char **av);
stat_buff_t *read_to_string_array(char **av);
int verif_error(int ac, char **av);
int handle_generating(int ac, char **av, stat_buff_t *buffer);
int setting_up_algo(stat_buff_t *buffer);
int return_woula(char *buffer);
int verif_size(char *buffer);
int verif_char(char *buffer);

#endif /* SETTING_UP_H */
