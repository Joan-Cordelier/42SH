/*
** EPITECH PROJECT, 2023
** my_count_putsc
** File description:
** put float into scientific number
*/

#include "my.h"

static int putsc_bellow_zero(double *nb, int precision, int upper)
{
    double i = 1.0;
    int pow = 0;
    int count = 0;

    while (*nb * i < 1.0) {
        i *= 10.0;
        pow += 1;
    }
    *nb = *nb * i;
    count += my_count_putfloat(nb, precision);
    if (upper == 1) {
        count += my_count_putchar('E');
    } else {
        count += my_count_putchar('e');
    }
    count += my_count_putchar('-');
    if (pow < 10)
        count += my_count_putchar('0');
    count += my_count_putnbr(pow);
    return count;
}

static int putsc_bigger_zero(double *nb, int precision, int upper)
{
    double i = 1.0;
    int pow = 0;
    int count = 0;

    while (*nb / i > 10.0) {
        i *= 10.0;
        pow += 1;
    }
    *nb = *nb / i;
    count += my_count_putfloat(nb, precision);
    if (upper == 1) {
        count += my_count_putchar('E');
    } else {
        count += my_count_putchar('e');
    }
    count += my_count_putchar('+');
    if (pow < 10)
        count += my_count_putchar('0');
    count += my_count_putnbr(pow);
    return count;
}

int my_count_putsc(double *nb, int precision, int upper)
{
    int count = 0;

    if (*nb < 1) {
        count = putsc_bellow_zero(nb, precision, upper);
    } else {
        count = putsc_bigger_zero(nb, precision, upper);
    }
    return count;
}
