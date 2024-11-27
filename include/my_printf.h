/*
** EPITECH PROJECT, 2024
** B-CPE-101-LIL-1-1-myprintf-mathys1.dupont
** File description:
** my_printf.h
*/

#ifndef MY_PRINTF_H
    #define MY_PRINTF_H
    #include <stdarg.h>

int my_printf(const char *format, ...);
int flag_empty(const char *format, int *i, va_list ac);
int flag_mini(char const *format, int *i, va_list ac);
int flag_o(char const *format, int *i, va_list ac);
int flag_scientific(char const *format, int *i, va_list ac);
int flag_hexa_min(char const *format, int *i, va_list ac);
int flag_hexa_maj(char const *format, int *i, va_list ac);
int flag_u(char const *format, int *i, va_list ac);
int flag_float(char const *format, int *i, va_list ac);
int flag_diez(char const *format, int *i, va_list ac);
int flag_hh(char const *format, int *i, va_list ac);
int flag_h(char const *format, int *i, va_list ac);
int flag_space(char const *format, int *i, va_list ac);
int flag_ll(char const *format, int *i, va_list ac);
int flag_plus(char const *format, int *i, va_list ac);
int flag_z(char const *format, int *i, va_list ac);
int flag_l(char const *format, int *i, va_list ac);
int flag_j(char const *format, int *i, va_list ac);
int flag_m(char const *format, int *i, va_list ac);
int flag_p(char const *format, int *i, va_list ac);
int flag_neg(char const *format, int *i, va_list ac);
int flag_float_space(double nb);
int flag_neg_hexastring(char const *format, int *i, va_list ac);
int flag_b(char const *format, int *i, va_list ac);

typedef struct p_s {
    char *str;
    int (*function)(char const *format, int *i, va_list ac);
} p_t;

#endif /* MY_PRINTF_H */
