/*
** EPITECH PROJECT, 2023
** my_count_putunsigned
** File description:
** putunsigned with counting
*/

#include "my.h"

int my_count_putunsigned(unsigned int nb)
{
    int tmp;
    int count = 0;

    if (nb <= 9) {
        my_count_putchar(nb + '0');
        count++;
    }
    if (nb > 9) {
        tmp = nb % 10;
        count = count + my_count_putunsigned(nb / 10);
        my_count_putchar(tmp + '0');
        count++;
    }
    return count;
}
