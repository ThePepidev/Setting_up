/*
** EPITECH PROJECT, 2024
** B-CPE-101-LIL-1-1-myprintf-mathys1.dupont
** File description:
** flag_Ee.c
*/

#include "../my.h"
#include <stdarg.h>

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

static int flag_do(char const *format, int i, double nb)
{
    int temp;
    int power = 0;

    increment_power(&power, &nb);
    temp = (int)nb;
    dysplay_temp(temp);
    nb = (nb - temp) * 10.0;
    for (int j = 0; j < 6; j++) {
        temp = (int)nb;
        if ((nb - temp) >= 0.5 && (temp + 1) <= nb)
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

int flag_scientific(char const *format, int *i, va_list ac)
{
    double nb;

    nb = va_arg(ac, double);
    flag_do(format, *i, nb);
}
