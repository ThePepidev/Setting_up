/*
** EPITECH PROJECT, 2024
** my_compute_power_it
** File description:
** power number
*/

#include "my.h"

int my_compute_power_it(int nb, int p)
{
    int temp = nb;

    if (p == 0) {
        return 1;
    }
    if (p == 1) {
        return nb;
    }
    if (p < 0) {
        return 0;
    }
    for (int k = 1; k < p; k++) {
        nb = nb * temp;
    }
    return nb;
}
