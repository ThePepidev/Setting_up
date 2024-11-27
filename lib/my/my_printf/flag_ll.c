/*
** EPITECH PROJECT, 2024
** B-CPE-101-LIL-1-1-myprintf-mathys1.dupont
** File description:
** flag_ll.c
*/

#include "../my.h"
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>

static int my_put_number(long long nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    }
    if (nb >= 0 && nb <= 9) {
        my_putchar(nb + 48);
    }
    if (nb > 9) {
        my_put_number(nb / 10);
        my_putchar((nb % 10) + 48);
    }
}

static int my_put_unsigned(unsigned long long nb)
{
    if (nb <= 9 && nb >= 0)
        my_putchar(nb + 48);
    else if (nb > 9) {
        my_put_unsigned(nb / 10);
        my_putchar((nb % 10) + 48);
    } else
        return 84;
}

static int my_put_hexa(char const *format, int i, long long nb)
{
    int k = 0;
    int reste = 0;
    char hexa[] = "0123456789abcdef";
    char hexago[] = "0123456789ABCDEF";
    char *str = malloc(sizeof(char) * 9);

    if (nb == 0)
        str[k] = hexa[0];
    while (nb > 0) {
        reste = (nb % 16);
        if (format[i] == 'X')
            str[k] = hexago[reste];
        else
            str[k] = hexa[reste];
        nb = nb / 16;
        k++;
    }
    my_revstr(str);
    my_putstr(str);
    free(str);
}

static int my_put_octal(long long nb)
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

static int flag_do_suite(char const *format, int *i, long long nb)
{
    if (format[*i] == 'o') {
        my_put_octal(nb);
    }
    if (format[*i] == 'u') {
        my_put_unsigned(nb);
    }
    if (format[*i] == 'X' || format[*i] == 'x') {
        my_put_hexa(format, *i, nb);
    }
}

static int flag_do(char const *format, int *i, va_list ac)
{
    long long nb_t;
    unsigned long long nb;

    if (format[*i] == 'd' || format[*i] == 'i') {
        nb_t = (long long)va_arg(ac, int);
        my_put_number(nb_t);
        return 0;
    }
    nb = (unsigned long long)va_arg(ac, int);
    flag_do_suite(format, i, nb);
}

int flag_ll(char const *format, int *i, va_list ac)
{
    (*i) += 2;
    flag_do(format, i, ac);
    return 0;
}
