/*
** EPITECH PROJECT, 2024
** my_strupcase
** File description:
** uppercase number
*/

#include "my.h"

char *my_strlowcase(char *str)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32;
        }
    }
    return str;
}
