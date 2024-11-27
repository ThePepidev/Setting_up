/*
** EPITECH PROJECT, 2024
** my_is_prime
** File description:
** number prime ?
*/

#include "my.h"

int my_is_prime(int nb)
{
    int div = 2;
    int mod;

    if (nb <= 1) {
        return 0;
    }
    for (; nb > div; div++) {
        mod = nb % div;
        if (mod == 0) {
            return 0;
        }
    }
    return 1;
}
