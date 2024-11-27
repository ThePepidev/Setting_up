/*
** EPITECH PROJECT, 2024
** my_getnbr
** File description:
** get nbr
*/

#include "my.h"
#include <stdio.h>

int my_getnbr(char const *str)
{
    long nb = 0;
    int neg = 0;
    int i;

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == '-')
            neg++;
        while (str[i] >= 48 && str[i] <= 57) {
            nb *= 10;
            nb += str[i] - 48;
            i++;
        }
        if (neg != 0)
            nb *= (-1);
        if (nb > 2147483647 || nb < -2147483648)
            return 0;
        if (nb != 0)
            return nb;
    }
}
