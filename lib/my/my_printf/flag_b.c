/*
** EPITECH PROJECT, 2024
** B-CPE-101-LIL-1-1-myprintf-mathys1.dupont
** File description:
** flag_b.c
*/

#include "../my.h"

static int flag_do(unsigned int nb)
{
    int temp[12];
    int i = 0;

    if (nb == 0) {
        my_putchar('0');
        return 1;
    }
    while (nb > 0) {
        temp[i] = nb % 2;
        nb = nb / 2;
        i++;
    }
    for (int j = i - 1; j >= 0; j--)
        my_putchar(temp[j] + '0');
}

int flag_b(char const *format, int *i, va_list ac)
{
    unsigned int nb = va_arg(ac, int);

    flag_do(nb);
    return 0;
}
