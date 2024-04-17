/*
** EPITECH PROJECT, 2023
** my_count_putnbr
** File description:
** putnbr with counting option
*/

#include "my.h"

int my_countnbr(long long int nb)
{
    int tmp = 0;
    int count = 0;

    tmp++;
    if (nb < 0) {
        nb = nb * (- 1);
        count++;
    }
    if (nb >= 0 && nb <= 9) {
        count++;
    }
    if (nb > 9) {
        tmp = nb % 10;
        count = count + my_countnbr(nb / 10);
        count++;
    }
    return count;
}

int my_count_putnbr(long long int nb)
{
    int tmp;
    int count = 0;

    if (nb < 0) {
        my_count_putchar('-');
        nb = nb * (- 1);
        count++;
    }
    if (nb >= 0 && nb <= 9) {
        my_count_putchar(nb + '0');
        count++;
    }
    if (nb > 9) {
        tmp = nb % 10;
        count = count + my_count_putnbr(nb / 10);
        my_count_putchar(tmp + '0');
        count++;
    }
    return count;
}

//the str in param got to be empty (useful so no malloc)
char *my_sputnbr(long long int nb, char *str)
{
    int tmp;
    char ch[2];

    ch[1] = '\0';
    if (nb < 0) {
        my_strcat(str, "-");
        nb = nb * (- 1);
    }
    if (nb >= 0 && nb <= 9) {
        ch[0] = nb + '0';
        my_strcat(str, ch);
    }
    if (nb > 9) {
        tmp = nb % 10;
        str = my_sputnbr(nb / 10, str);
        ch[0] = tmp + '0';
        my_strcat(str, ch);
    }
    return str;
}
