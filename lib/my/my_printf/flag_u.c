/*
** EPITECH PROJECT, 2024
** B-CPE-101-LIL-1-1-myprintf-mathys1.dupont
** File description:
** flag_u.c
*/

#include "../my.h"
#include <stdarg.h>
#include <stddef.h>

static int flag_do(unsigned int nb)
{
    if (nb <= 9 && nb >= 0)
        my_putchar(nb + 48);
    else if (nb > 9) {
        flag_do(nb / 10);
        my_putchar((nb % 10) + 48);
    } else
        return 84;
}

int flag_u(char const *format, int *i, va_list ac, int *loop)
{
    unsigned int nb;

    nb = va_arg(ac, unsigned int);
    flag_do(nb);
}
