/*
** EPITECH PROJECT, 2024
** B-CPE-101-LIL-1-1-myprintf-mathys1.dupont
** File description:
** flag_m.c
*/

#include "../my.h"
#include <errno.h>
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int flag_m(char const *format, int *i, va_list ac)
{
    char *error_message = strerror(errno);

    if (error_message == NULL) {
        write(1, "success", 7);
        return 0;
    }
    write(2, error_message, my_strlen(error_message));
    return 0;
}
