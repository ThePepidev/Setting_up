/*
** EPITECH PROJECT, 2024
** B-CPE-101-LIL-1-1-myprintf-mathys1.dupont
** File description:
** my_printf.c
*/

#include <stdio.h>
#include <stdarg.h>
#include "../my.h"
#include "my_printf.h"

const p_t handle[] = {
    {"o", flag_o},
    {"d", flag_mini},
    {"i", flag_mini},
    {"c", flag_mini},
    {"s", flag_mini},
    {"%", flag_mini},
    {"u", flag_u},
    {"x", flag_hexa_min},
    {"X", flag_hexa_maj},
    {"e", flag_scientific},
    {"E", flag_scientific},
    {"f", flag_float},
    {"F", flag_float},
    {"#", flag_diez},
    {"hh", flag_hh},
    {"h", flag_h},
    {" ", flag_space},
    {"ll", flag_ll},
    {"q", flag_ll},
    {"+", flag_plus},
    {"z", flag_z},
    {"Z", flag_z},
    {"l", flag_l},
    {"j", flag_j},
    {"m", flag_m},
    {"p", flag_p},
    {"-", flag_neg},
    {"b", flag_b},
    {0, NULL}
};

static int handle_double(char const *format, int *i, va_list ac, int j)
{
    int len_handle = my_strlen(handle[j].str);
    int k = 0;

    while (k < len_handle) {
        if (handle[j].str[k] == format[*i + k])
            k++;
        else
            return 0;
    }
    return k;
}

static int handle_function(char const *format, int *i, va_list ac)
{
    int k = 0;
    int j;

    for (j = 0; handle[j].str; j++) {
        k = handle_double(format, i, ac, j);
        if (k > 0) {
            handle[j].function(format, i, ac);
            return 1;
        }
    }
    return 0;
}

int flag_empty(const char *format, int *i, va_list ac)
{
    int temp;
    int boolean = 0;

    for (int j = 0; format[j]; j++) {
        if (format[j] == '\n') {
            boolean = 1;
        }
    }
    temp = handle_function(format, i, ac);
    if (temp != 1 && boolean == 1) {
        my_putchar('%');
        (*i)--;
    } else if (temp != 1) {
        (*i)--;
    }
}

int my_printf(const char *format, ...)
{
    int i = 0;
    va_list ac;
    int j;

    va_start(ac, format);
    for (; format[i]; i++) {
        if (format[i] == '%') {
            j = i + 1;
            flag_empty(format, &j, ac);
            i = j;
        } else
            my_putchar(format[i]);
    }
    va_end(ac);
}
