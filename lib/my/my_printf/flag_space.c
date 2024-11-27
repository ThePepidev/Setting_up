/*
** EPITECH PROJECT, 2024
** B-CPE-101-LIL-1-1-myprintf-mathys1.dupont
** File description:
** flag_space.c
*/

#include "../my.h"
#include "my_printf.h"
#include <stdarg.h>
#include <stdlib.h>

static int increment_power(int *power, double *nb)
{
    if (*nb < 0) {
        my_putchar('-');
        *nb = -(*nb);
    }
    while (*nb > 10.0) {
        *nb = *nb / 10.0;
        (*power)++;
    }
    while (*nb < 1.0) {
        *nb *= 10.0;
        (*power)--;
    }
}

static void put_power(int power)
{
    if (power >= 0)
        my_putchar('+');
    if (power < 0) {
        my_putchar('-');
        power = -power;
    }
    if (power < 10) {
        my_putchar('0');
        my_put_nbr(power);
    } else
        my_put_nbr(power);
}

static int dysplay_temp(int temp)
{
    my_put_nbr(temp);
    my_putchar('.');
}

static int flag_scientific_space(char const *format, int i, double nb)
{
    int temp;
    int power = 0;

    increment_power(&power, &nb);
    temp = (int)nb;
    dysplay_temp(temp);
    nb = (nb - temp) * 10.0;
    for (int j = 0; j < 6; j++) {
        temp = (int)nb;
        if ((nb - temp) >= 0.5 && temp <= nb)
            temp++;
        my_put_nbr(temp);
        nb = nb - temp;
        nb *= 10.0;
    }
    if (format[i] == 'e')
        my_putchar('e');
    else
        my_putchar('E');
    put_power(power);
}

static int my_put_unsigned(unsigned int nb)
{
    if (nb <= 9 && nb >= 0)
        my_putchar(nb + 48);
    else if (nb > 9) {
        my_put_unsigned(nb / 10);
        my_putchar((nb % 10) + 48);
    } else
        return 84;
}

static int flag_di(char const *format, int *i, int nb)
{
    my_put_nbr(nb);
    return 0;
}

static int flag_space_suite(char const *format, int *i, va_list ac)
{
    double nb_d = va_arg(ac, double);

    if (format[*i] == 'f' || format[*i] == 'F') {
        if (nb_d >= 0)
            my_putchar(' ');
        flag_float_space(nb_d);
        return 0;
    }
    if (format[*i] == 'e' || format[*i] == 'E') {
        if (nb_d >= 0)
            my_putchar(' ');
        flag_scientific_space(format, *i, nb_d);
        return 0;
    }
}

int flag_space(char const *format, int *i, va_list ac)
{
    int nb;

    for (; format[*i] == ' '; (*i)++);
    if (format[*i] == 'd' || format[*i] == 'i') {
        nb = va_arg(ac, int);
        if (nb >= 0)
            my_putchar(' ');
        flag_di(format, i, nb);
        return 0;
    }
    if (format[*i] == 'u') {
        nb = va_arg(ac, int);
        if (nb >= 0)
            my_putchar(' ');
        my_put_unsigned(nb);
        return 0;
    }
    if (flag_space_suite(format, i, ac) == 0)
        return 0;
    flag_empty(format, i, ac);
}
