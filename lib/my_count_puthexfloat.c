/*
** EPITECH PROJECT, 2023
** my_count_puthexfloat
** File description:
** print a float in hex format
*/

#include "my.h"

static int calculate_p(double nb)
{
    int count = 0;

    if (nb > 1) {
        while ((int)nb > 1) {
            nb = nb / 2.0;
            count++;
        }
    } else {
        while ((int)nb < 1) {
            nb = nb * 2.0;
            count ++;
        }
    }
    return count;
}

static double calculate_tmp(double nb, unsigned long int power)
{
    double tmp = (double) nb / power;

    if (tmp > 1.0) {
        tmp -= 1.0;
    }
    while ((int)tmp - (double)tmp != 0) {
        tmp *= 16.0;
    }
    return tmp;
}

int my_count_puthexfloat(double nb, int upper)
{
    int length = 0;
    int p = calculate_p(nb);
    unsigned long int power = calc_power_pos(2, p);
    double tmp = 0.0;

    length += my_count_putstr("0x1");
    tmp = calculate_tmp(nb, power);
    if (tmp > 0) {
        length += my_count_putchar('.');
    }
    length += my_count_puthex(tmp, upper);
    length += my_count_putstr("p+");
    length += my_count_putnbr(p);
    return length;
}
