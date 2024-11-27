/*
** EPITECH PROJECT, 2024
** my_swap
** File description:
** swap integers
*/

#include "my.h"

void my_swap(int *a, int *b)
{
    int temp = *a;

    *a = *b;
    *b = temp;
}
