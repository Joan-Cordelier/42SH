/*
** EPITECH PROJECT, 2023
** my count putfloat
** File description:
** print a float
*/

#include "my.h"

static int less_than_17(unsigned long int stock, int accuracy)
{
    unsigned long int power = calc_power_pos(10, accuracy);
    int count = 0;

    count += my_count_putnbr(stock / power);
    if (accuracy > 0){
        count += my_count_putchar('.');
        for (int i = 0; i < accuracy; i++){
            count += my_count_putnbr((stock % power) / (power / 10));
            power = power / 10;
            }
    }
    return count;
}

static int count_less_than_17(unsigned long int stock, int accuracy)
{
    unsigned long int power = calc_power_pos(10, accuracy);
    int count = 0;

    count += my_countnbr(stock / power);
    if (accuracy > 0){
        count += 1;
        for (int i = 0; i < accuracy; i++){
            count += my_countnbr((stock % power) / (power / 10));
            power = power / 10;
            }
    }
    return count;
}

static int count_more_than_17(double *nb, int accuracy)
{
    int stock = (int)*nb;
    int count = 0;

    count += my_countnbr(stock);
    if (accuracy > 0){
        count += 1;
        *nb = *nb - stock;
        for (int i = 0; i < accuracy - 1; i++){
            *nb = *nb * 10.0;
            stock = (int)*nb;
            count += my_countnbr(stock);
            *nb = *nb - stock;
        }
        *nb = *nb * 10.0;
        stock = (int)*nb;
        if (stock % 10 >= 5)
            stock++;
        count += my_countnbr(stock % 10);
    }
    return count;
}

static int more_than_17(double *nb, int accuracy)
{
    int stock = (int)*nb;
    int count = 0;

    count += my_count_putnbr(stock);
    if (accuracy > 0){
        count += my_count_putchar('.');
        *nb = *nb - stock;
        for (int i = 0; i < accuracy - 1; i++){
            *nb = *nb * 10.0;
            stock = (int)*nb;
            count += my_count_putnbr(stock);
            *nb = *nb - stock;
        }
        *nb = *nb * 10.0;
        stock = (int)*nb;
        if (stock % 10 >= 5)
            stock++;
        count += my_count_putnbr(stock % 10);
    }
    return count;
}

int my_count_putfloat(double *nb, int accuracy)
{
    unsigned long int power = calc_power_pos(10, accuracy);
    unsigned long int stock;
    int count = 0;

    if (*nb < 0){
        count += my_count_putchar('-');
        *nb *= -1;
        }
    stock = *nb * power;
    if (accuracy < 17){
        if (((unsigned long int)(*nb * power * 10)) % 10 >= 5)
            stock++;
        count += less_than_17(stock, accuracy);
    } else {
        count += more_than_17(nb, accuracy);
    }
    return count;
}

int my_countfloat(double *nb, int accuracy)
{
    unsigned long int power = calc_power_pos(10, accuracy);
    unsigned long int stock;
    int count = 0;

    if (*nb < 0){
        count += 1;
        *nb *= -1;
        }
    stock = *nb * power;
    if (accuracy < 17){
        if (((unsigned long int)(*nb * power * 10)) % 10 >= 5)
            stock++;
        count += count_less_than_17(stock, accuracy);
    } else {
        count += count_more_than_17(nb, accuracy);
    }
    return count;
}
