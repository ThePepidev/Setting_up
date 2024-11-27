/*
** EPITECH PROJECT, 2024
** my_strstr
** File description:
** strstr
*/

#include "my.h"
#include <stddef.h>

int suite(char *str, char const *to_find, int i)
{
    int b = 0;

    while (to_find[b] != '\0') {
        if (str[i] != to_find[b]) {
            return 0;
        }
        b++;
        i++;
    }
    return 1;
}

char *my_strstr(char *str, char const *to_find)
{
    int i = 0;
    int a;

    if (my_strlen(str) < my_strlen(to_find)) {
        return NULL;
    }
    while (str[i] != '\0') {
        if (suite(str, to_find, i) == 1) {
            return &str[i];
        }
        i++;
    }
    return 0;
}
