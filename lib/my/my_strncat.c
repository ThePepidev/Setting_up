/*
** EPITECH PROJECT, 2024
** my_strncat
** File description:
** str cat
*/

#include "my.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    int max_dest = my_strlen(dest);

    for (int i = 0; src[i] && nb > i; i++) {
        dest[max_dest + i] = src[i];
    }
    return dest;
}
