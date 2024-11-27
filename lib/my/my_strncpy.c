/*
** EPITECH PROJECT, 2024
** my_strncpy
** File description:
** my_strncpy
*/

#include "my.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    int i;

    for (i = 0; n > i; i++) {
        dest[i] = src[i];
    }
    return dest;
}
