/*
** EPITECH PROJECT, 2023
** my_display_octal.c
** File description:
** convert int to octal and print it, also count the number of char printed
*/

#include "my.h"

static int my_display_octal_rec(unsigned long int nb)
{
    int count = 1;

    if (nb == 0){
        return 0;
        }
    count += my_display_octal_rec(nb / 8);
    my_count_putchar(nb % 8 + '0');
    return count;
}

int my_display_octal(unsigned int nb)
{
    if (nb == 0){
        return my_count_putchar('0');
    }
    return my_display_octal_rec(nb);
}

int my_display_long_octal(unsigned long nb)
{
    if (nb == 0){
        return my_count_putchar('0');
    }
    return my_display_octal_rec(nb);
}
