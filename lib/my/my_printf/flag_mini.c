/*
** EPITECH PROJECT, 2024
** B-CPE-101-LIL-1-1-myprintf-mathys1.dupont
** File description:
** flag_mini.c
*/

#include <stdarg.h>
#include "../my.h"

int flag_mini(char const *format, int *i, va_list ac)
{
    char *str;

    if (format[*i] == 'd' || format[*i] == 'i') {
        my_put_nbr(va_arg(ac, int));
        return 0;
    }
    if (format[*i] == '%') {
        my_putchar('%');
        return 0;
    }
    if (format[*i] == 's') {
        my_putstr(va_arg(ac, char *));
        return 0;
    }
    if (format[*i] == 'c') {
        my_putchar((char)va_arg(ac, int));
        return 0;
    }
}
