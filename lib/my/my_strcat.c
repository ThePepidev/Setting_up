/*
** EPITECH PROJECT, 2024
** my_strcat
** File description:
** str cat
*/

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int max_dest = my_strlen(dest);

    for (int i = 0; src[i]; i++) {
        dest[max_dest + i] = src[i];
    }
    dest[max_dest + my_strlen(src)] = '\0';
    return dest;
}
