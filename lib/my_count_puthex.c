/*
** EPITECH PROJECT, 2023
** my_count_puthex
** File description:
** count and print a hex
*/
#include "my.h"

const char UPPER_HEX[] = {'0', '1', '2', '3', '4', '5', '6', '7',
    '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
const char LOWER_HEX[] = {'0', '1', '2', '3', '4', '5', '6', '7',
    '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

static int my_count_puthex_rec(unsigned int nb, int is_upper)
{
    int count = 0;

    if (nb == 0) {
        return 0;
    }
    count += my_count_puthex_rec(nb / 16, is_upper);
    if (is_upper == 1) {
        count += my_count_putchar(UPPER_HEX[nb % 16]);
    } else {
        count += my_count_putchar(LOWER_HEX[nb % 16]);
    }
    return count;
}

int my_count_puthex(int nb, int is_upper)
{
    if (nb == 0)
        return my_count_putchar('0');
    return my_count_puthex_rec(nb, is_upper);
}
