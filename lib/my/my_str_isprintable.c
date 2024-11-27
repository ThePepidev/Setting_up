/*
** EPITECH PROJECT, 2024
** my_str_isprintable
** File description:
** str is printable
*/

#include "my.h"

static int condition(char const *str, int i)
{
    if (str[i] >= 32 && str[i] <= 126) {
        return 1;
    }
    return 0;
}

int my_str_isprintable(char const *str)
{
    int i;

    for (i = 0; str[i]; i++) {
        if (condition(str, i) == 0)
            return 0;
    }
    return 1;
}
