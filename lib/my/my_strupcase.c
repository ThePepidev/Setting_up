/*
** EPITECH PROJECT, 2024
** my_strupcase
** File description:
** uppercase number
*/

#include "my.h"
#include <stddef.h>

char *my_strupcase(char *str)
{
    if (str == NULL) {
        return NULL;
    }
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 32;
        }
    }
    return str;
}
