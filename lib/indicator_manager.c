/*
** EPITECH PROJECT, 2023
** indicator manager
** File description:
** manage the indicator flags
*/

#include "my.h"

char get_flag(char c)
{
    if (c == 'e' || c == 'E' || c == 'f' || c == 'F' ||
    c == 'g' || c == 'G' || c == 'a' || c == 'A' ||
    c == '%' || c == 's' || c == 'S' || c == 'c' ||
    c == 'C' || c == 'd' || c == 'i' || c == 'o' ||
    c == 'u' || c == 'x' || c == 'X' || c == 'p') {
        return c;
    } else {
        return '\0';
    }
}

int is_flag(char c)
{
    if (c == 'e' || c == 'E' || c == 'f' || c == 'F' ||
    c == 'g' || c == 'G' || c == 'a' || c == 'A' ||
    c == '%' || c == 's' || c == 'S' || c == 'c' ||
    c == 'C' || c == 'd' || c == 'i' || c == 'o' ||
    c == 'u' || c == 'x' || c == 'X' || c == 'p')
        return 1;
    return 0;
}

int is_size_prefix(char c)
{
    if (c == 'h' || c == 'l' || c == 'q' || c == 'L' || c == 'j' ||
    c == 'z' || c == 'Z' || c == 't')
        return 1;
    return 0;
}

int indicator_int(char const *format, int i)
{
    int nb = 0;

    while (is_flag(format[i]) == 0 && is_size_prefix(format[i]) == 0){
        nb = nb * 10 + format[i] - '0';
        i++;
        }
    return nb;
}

int minus_indicator(char const *format, int co_mod, int len)
{
    int length = 0;
    int acc = indicator_int(format, co_mod + 2);

    acc -= len;
    while (acc > 0) {
        length += my_count_putchar(' ');
        acc -= 1;
    }
    return length;
}
