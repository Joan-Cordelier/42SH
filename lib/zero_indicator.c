/*
** EPITECH PROJECT, 2023
** zero indicator
** File description:
** function for the zero padding indicator flag
*/

#include "my.h"

int zero_indicator(char format, int len)
{
    int length = 0;

    if (format != '0')
        return 0;
    while (len > 0) {
        length += my_count_putchar('0');
        len--;
    }
    return length;
}
