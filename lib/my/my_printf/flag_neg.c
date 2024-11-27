/*
** EPITECH PROJECT, 2024
** B-CPE-101-LIL-1-1-myprintf-mathys1.dupont
** File description:
** flag_neg.c
*/

#include "../my.h"
#include "my_printf.h"
#include <stdio.h>
#include <stdlib.h>

static int my_put_space(int nb_space)
{
    for (int k = 0; k < nb_space; k++) {
        my_putchar(' ');
    }
}

static void len_flag_suite(int nb, int *len_nb)
{
    if (nb < 0) {
        (*len_nb)++;
        nb *= -1;
    }
    while (nb >= 1) {
        nb /= 10;
        (*len_nb)++;
    }
}

static int len_flag(char const *format, int i, va_list av, int *len_nb)
{
    int nb;

    *len_nb = 0;
    switch (format[i]) {
        case 'F':
        case 'f':
            (*len_nb) = 7;
            nb = (int)va_arg(av, double);
            break;
        case 'E':
        case 'e':
            (*len_nb) = 12;
            if (va_arg(av, double) < 0)
                (*len_nb)++;
            return 0;
            break;
        default:
            nb = va_arg(av, int);
    }
    len_flag_suite(nb, len_nb);
}

int flag_neg(char const *format, int *i, va_list ac)
{
    int temp_nb = 0;
    int len_nb = 0;
    int nb_space;
    va_list av;

    va_copy(av, ac);
    for (int j = (*i + 1); format[j] >= '0' && format[j] <= '9'; j++) {
        temp_nb *= 10;
        temp_nb += (format[j] - 48);
        len_nb++;
    }
    (*i) += (len_nb + 1);
    if (format[*i] == 'x' || format[*i] == 'X' || format[*i] == 's') {
        len_nb = flag_neg_hexastring(format, i, ac);
    } else {
        flag_empty(format, i, ac);
        len_flag(format, *i, av, &len_nb);
    }
    nb_space = temp_nb - len_nb;
    my_put_space(nb_space);
}
