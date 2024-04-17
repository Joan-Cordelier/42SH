/*
** EPITECH PROJECT, 2023
** hashtag_format
** File description:
** manage the hashtag format
*/

#include "my.h"

int hashtag_indicator_int(char *flag, char const *format, int co_mod,
    long long int arg)
{
    int length = 0;
    int fpos = my_strlen(flag) - 1;

    if (format[co_mod + 1] != '#')
        return length;
    if (flag[fpos] == 'o' && arg != 0)
        length += my_count_putchar('0');
    if ((flag[fpos] == 'x' || flag[fpos] == 'X') && arg != 0)
        length += my_count_putstr("0x");
    return length;
}

/*int hashtag_indicator_float(char *flag, char const *format,
    int co_mod, double arg)
{
    int length = 0;
    int fpos = my_strlen(flag) - 1;

    if (format[co_mod + 1] != '#')
        return length;
}*/
