/*
** EPITECH PROJECT, 2024
** B-CPE-101-LIL-1-1-myprintf-mathys1.dupont
** File description:
** flag_neg_hexastring.c
*/

#include "../my.h"
#include <stdlib.h>

static int my_display_revstr(char *str)
{
    int l = my_strlen(str);
    char temp;

    for (int i = 0; i < (l / 2); i++) {
        temp = str[i];
        str[i] = str[l - i - 1];
        str[l - i - 1] = temp;
    }
    my_putstr(str);
}

static int my_put_hexa(char const *format, int i, int nb)
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
    return my_strlen(str);
}

static int my_put_string(char *str)
{
    my_putstr(str);
    return my_strlen(str);
}

int flag_neg_hexastring(char const *format, int *i, va_list ac)
{
    int nb;
    char *str;
    int re;

    if (format[*i] == 'x' || format[*i] == 'X') {
        nb = va_arg(ac, int);
        re = my_put_hexa(format, *i, nb);
        return re;
    }
    if (format[*i] == 's') {
        str = va_arg(ac, char *);
        re = my_put_string(str);
        return re;
    }
}
