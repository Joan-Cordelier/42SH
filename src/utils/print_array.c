/*
** EPITECH PROJECT, 2024
** printarray
** File description:
** printarray
*/

#include "my.h"

int my_printarray(char **str)
{
    int i = 0;

    while (*str) {
        my_putstr(*str);
        my_count_putchar('\n');
        str++;
    }
    return i;
}
