/*
** EPITECH PROJECT, 2024
** B-CPE-101-LIL-1-1-myprintf-mathys1.dupont
** File description:
** flag_space_float.c
*/

#include "../my.h"

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

int flag_float_space(double nb)
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
