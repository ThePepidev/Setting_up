/*
** EPITECH PROJECT, 2024
** my_str_isupper
** File description:
** str is num
*/

#include "my.h"

static int condition(char const *str, int i)
{
    if (str[i] >= 'A' && str[i] <= 'Z') {
        return 1;
    }
    return 0;
}

int my_str_isupper(char const *str)
{
    int i;

    for (i = 0; str[i]; i++) {
        if (condition(str, i) == 0)
            return 0;
    }
    return 1;
}
