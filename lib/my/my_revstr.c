/*
** EPITECH PROJECT, 2024
** my_evil_str
** File description:
** evil str
*/

#include "my.h"

char *my_revstr(char *str)
{
    int l = my_strlen(str);
    char temp;

    for (int i = 0; i < (l / 2); i++) {
        temp = str[i];
        str[i] = str[l - i - 1];
        str[l - i - 1] = temp;
    }
    return str;
}
