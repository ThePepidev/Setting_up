/*
** EPITECH PROJECT, 2024
** B-CPE-101-LIL-1-1-myprintf-mathys1.dupont
** File description:
** flag_hexa
*/

#include <stdlib.h>
#include "../my.h"
#include <stdarg.h>

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

int flag_hexa_min(char const *format, int *i, va_list ac)
{
    int k = 0;
    int reste = 0;
    int nb;
    char hexa[] = "0123456789abcdef";
    char *str = malloc((sizeof(char) + 1) * 9);

    nb = va_arg(ac, int);
    if (nb == 0)
        str[k] = hexa[0];
    while (nb > 0) {
        reste = (nb % 16);
        str[k] = hexa[reste];
        nb = nb / 16;
        k++;
    }
    my_display_revstr(str);
    free(str);
}

int flag_hexa_maj(char const *format, int *i, va_list ac)
{
    int nb;
    int reste = 0;
    int k = 0;
    char hexago[] = "0123456789ABCDEF";
    char *str = malloc((sizeof(char) + 1) * 9);

    nb = va_arg(ac, int);
    if (nb == 0)
        str[k] = hexago[0];
    while (nb > 0) {
        reste = (nb % 16);
        str[k] = hexago[reste];
        nb = nb / 16;
        k++;
    }
    my_display_revstr(str);
    free(str);
}
