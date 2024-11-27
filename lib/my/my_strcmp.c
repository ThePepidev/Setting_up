/*
** EPITECH PROJECT, 2024
** my_strcmp
** File description:
** compare strings
*/

#include "my.h"
#include <stddef.h>

int my_strcmp(char const *s1, char const *s2)
{
    int i;

    for (i = 0; s1[i] && s2[i] && s1[i] == s2[i]; i++);
    if (s1[i] < s2[i])
        return -1;
    if (s1[i] > s2[i])
        return 1;
    if (s1[i] == s2[i])
        return 0;
}
