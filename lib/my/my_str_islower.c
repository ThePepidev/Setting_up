/*
** EPITECH PROJECT, 2024
** my_str_islower
** File description:
** str is lower
*/

#include "my.h"

static int condition(char const *str, int i)
{
    if (str[i] >= 'a' && str[i] <= 'z') {
        return 1;
    }
    return 0;
}

int my_str_islower(char const *str)
{
    int i;

    for (i = 0; str[i]; i++) {
        if (condition(str, i) == 0)
            return 0;
    }
    return 1;
}
