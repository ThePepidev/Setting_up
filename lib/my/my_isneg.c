/*
** EPITECH PROJECT, 2024
** my_inseg
** File description:
** positif or negatif
*/

#include "my.h"

int my_isneg(int n)
{
    if (n < 0) {
        my_putchar(78);
    } else {
        my_putchar(80);
    }
    my_putchar('\n');
    return 0;
}
