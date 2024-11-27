/*
** EPITECH PROJECT, 2024
** printf
** File description:
** Untitled-1
*/

#include "../my.h"
#include <stdarg.h>

static int len_number(int nb)
{
    int len_nb;

    for (len_nb = 0; nb >= 1; len_nb++)
        nb = nb / 10;
    return len_nb;
}

static int flag_do(int nb)
{
    int temp[12];
    int i = 0;

    if (nb == 0) {
        my_putchar('0');
        return 1;
    }
    while (nb > 0) {
        temp[i] = nb % 8;
        nb = nb / 8;
        i++;
    }
    for (int j = i - 1; j >= 0; j--) {
        my_putchar(temp[j] + '0');
    }
}

int flag_o(char const *format, int *i, va_list ac)
{
    int nb;

    nb = va_arg(ac, int);
    flag_do(nb);
}
