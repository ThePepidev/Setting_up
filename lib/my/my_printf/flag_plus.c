/*
** EPITECH PROJECT, 2024
** B-CPE-101-LIL-1-1-myprintf-mathys1.dupont
** File description:
** flag_plus.c
*/

#include "../my.h"
#include "my_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

static int len_nb(double nb)
{
    int i = 0;

    while (nb > 10.0) {
        nb /= 10.0;
        i++;
    }
    return i;
}

static int float_max(double nb)
{
    if (nb == 340282346638528859811704183484516925440.000000) {
        my_putstr("340282346638528859811704183484516925440.000000");
        return 1;
    }
}

static int is_neg(double *nb)
{
    if (*nb < 0.0) {
        my_putchar('-');
        *nb = -(*nb);
    }
}

static int my_put_float(double nb)
{
    int temp;
    int len = len_nb(nb);
    int temp_len = len;

    if (float_max(nb) == 1)
        return 0;
    is_neg(&nb);
    for (int j = 0; j <= 6; j++) {
        temp = (int)nb;
        if ((nb - temp) >= 0.5 && temp <= nb)
            temp++;
        my_put_nbr(temp);
        nb = nb - temp;
        nb *= 10.0;
        if (len == temp_len) {
            my_putchar('.');
        }
        len--;
    }
}

static int flag_di(char const *format, int *i, int nb)
{
    my_put_nbr(nb);
    return 0;
}

int flag_plus(char const *format, int *i, va_list ac)
{
    int j = *i;
    int nb;
    double nb_t;

    for (; format[*i] == '+' || format[*i] == '-'; j++)
        (*i)++;
    if (format[*i] == 'i' || format[*i] == 'd') {
        nb = va_arg(ac, int);
        if (nb >= 0)
            my_putchar('+');
        flag_di(format, i, nb);
    }
    if (format[*i] == 'f') {
        nb_t = va_arg(ac, double);
        if (nb_t >= 0)
            my_putchar('+');
        my_put_float(nb_t);
    } else
        flag_empty(format, i, ac);
}
