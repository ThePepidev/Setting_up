/*
** EPITECH PROJECT, 2024
** B-CPE-101-LIL-1-1-myprintf-mathys1.dupont
** File description:
** flag_p.c
*/

#include "../my.h"
#include <stdint.h>
#include <unistd.h>
#include <stdlib.h>

static int my_put_hexa(uintptr_t nb)
{
    int k = 0;
    int reste = 0;
    char hexa[] = "0123456789abcdef";
    char *str = malloc(sizeof(char) * 9);

    if (nb == 0)
        str[k] = hexa[0];
    while (nb > 0) {
        reste = (nb % 16);
        str[k] = hexa[reste];
        nb = nb / 16;
        k++;
    }
    my_revstr(str);
    my_putstr(str);
    free(str);
}

int flag_p(char const *format, int *i, va_list ac)
{
    uintptr_t addr = (uintptr_t)va_arg(ac, void *);

    my_putstr("0x");
    my_put_hexa(addr);
}
