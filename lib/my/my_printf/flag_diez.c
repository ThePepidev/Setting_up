/*
** EPITECH PROJECT, 2024
** B-CPE-101-LIL-1-1-myprintf-mathys1.dupont
** File description:
** flag_diez.c
*/

#include "../my.h"
#include <stdarg.h>
#include "my_printf.h"

int flag_diez(char const *format, int *i, va_list ac)
{
    for (; format[*i] == '#'; (*i)++);
    if (format[*i] == 'x') {
        my_putstr("0x");
        flag_hexa_min(format, i, ac);
        return 0;
    }
    if (format[*i] == 'X') {
        my_putstr("0X");
        flag_hexa_maj(format, i, ac);
        return 0;
    }
    if (format[*i] == 'o') {
        my_put_nbr(0);
        flag_o(format, i, ac);
    } else
        flag_empty(format, i, ac);
}
