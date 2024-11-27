/*
** EPITECH PROJECT, 2024
** my_sort_int_array
** File description:
** sort int array
*/

#include "my.h"
#include <stdlib.h>
#include <stdio.h>

static void display(int *array, int j)
{
    int temp;

    if (array[j] > array[j + 1]) {
        temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp;
    }
}

void my_sort_int_array(int *array, int size)
{
    int i;
    int j;

    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            display(array, j);
        }
    }
}
