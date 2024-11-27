/*
** EPITECH PROJECT, 2024
** my_compute_square_root
** File description:
** square root number
*/

#include "my.h"

int my_compute_square_root(int nb)
{
    if (nb < 0) {
        return 0;
    }
    for (int i = 1; nb >= my_compute_power_it(i, 2); i++) {
        if (nb == my_compute_power_it(i, 2)) {
            return i;
        }
    }
    return 0;
}
