/*
** EPITECH PROJECT, 2024
** my_is_prime
** File description:
** number prime ?
*/

#include "my.h"

int my_find_prime_sup(int nb)
{
    int result;

    while (nb < 46340) {
        if (my_is_prime(nb) == 1){
            return nb;
        }
        nb++;
    }
}
