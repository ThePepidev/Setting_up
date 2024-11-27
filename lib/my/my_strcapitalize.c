/*
** EPITECH PROJECT, 2024
** my_capitalize
** File description:
** capitalize first letter
*/

#include "my.h"
#include <stddef.h>

char *normalise(char *str, int i)
{
    while (str[i] >= 'A' && str[i] <= 'Z' || str[i] >= 'a' && str[i] <= 'z') {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] += 32;
        }
        i++;
    }
}

char *capitalize1(char *str, int i)
{
    if (str[i - 1] < 'A' || str[i - 1] > 'Z') {
        normalise(str, i);
        str[i] = str[i] - 32;
    }
}

static char *capitalize(char *str, int i)
{
    if (str[i - 1] >= '0' && str[i - 1] <= '9') {
        normalise(str, i + 1);
        return NULL;
    }
    if (str[i] == str[0] && str[i] >= 'a' && str[i] <= 'z') {
        normalise(str, i);
        str[i] = str[i] - 32;
    }
    if (str[i] >= 'a' && str[i] <= 'z') {
        if (str[i - 1] < 'a' || str[i - 1] > 'z') {
            capitalize1(str, i);
        }
    }
    if (str[i] >= 'A' && str[i] <= 'Z') {
        if (str[i + 1] >= 'A' && str[i + 1] <= 'Z') {
            normalise(str, i + 1);
        }
    }
}

char *my_strcapitalize(char *str)
{
    int i = 0;

    for (i = 0; str[i]; i++) {
        capitalize(str, i);
    }
    return str;
}
