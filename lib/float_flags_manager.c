/*
** EPITECH PROJECT, 2023
** float_flag_manager
** File description:
** flag manager for float type
*/

#include "my.h"

static int count_digit_not_0(int nb)
{
    int count = 0;

    if (nb < 0)
        nb = -nb;
    while (nb > 0) {
        nb /= 10;
        count++;
    }
    return count;
}

static int add_start_zero_acc(double arg)
{
    int count = 0;

    while ((int)(arg * 10.0) == 0){
        count++;
        arg = arg * 10.0;
    }
    return count;
}

static int minus_end_zero_acc(unsigned long int int_arg)
{
    int i = 0;
    int count = 0;

    while (int_arg % 10 == 0 && i < 20){
        count++;
        int_arg = int_arg / 10;
        i++;
    }
    return count;
}

int tmp_not_equal_zero(double arg, int acc)
{
    int count;

    if (acc > 1) {
        acc += add_start_zero_acc(arg);
        acc -= minus_end_zero_acc(calc_power_pos(10, acc) * arg);
        count = my_count_putfloat(&arg, acc);
    } else if (acc == 0) {
        acc += add_start_zero_acc(arg);
        acc -= count_digit_not_0((int)arg);
        count = my_count_putfloat(&arg, acc);
    } else {
        acc += add_start_zero_acc(arg) - 1;
        count = my_count_putfloat(&arg, acc);
    }
    return count;
}

static int is_g_or_upperg(double arg, char flag, int acc)
{
    int count;

    if (flag == 'g')
        count = my_count_putsc(&arg, acc, 0);
    if (flag == 'G')
        count = my_count_putsc(&arg, acc, 1);
    return count;
}

int tmp_equal_zero(double arg, char flag, int acc)
{
    int count;

    if (acc > 1){
        acc += add_start_zero_acc(arg);
        acc -= minus_end_zero_acc(calc_power_pos(10, acc + 1) * arg);
        acc -= add_start_zero_acc(arg);
        count = is_g_or_upperg(arg, flag, acc);
    } else if (acc == 0) {
        count = is_g_or_upperg(arg, flag, acc);
    } else {
        count = is_g_or_upperg(arg, flag, acc - 1);
    }
    return count;
}

int is_f_or_e(double *arg, char *flag, int acc)
{
    int count;
    int tmp = 10000 * *arg;

    if ((tmp) != 0) {
        count = tmp_not_equal_zero(*arg, acc);
    } else {
        count = tmp_equal_zero(*arg, flag[my_strlen(flag) - 1], acc);
        }
    return count;
}

int get_print_len(char flag)
{
    if (flag == 'f' || flag == 'F')
        return 7;
    if (flag == 'e' || flag == 'E')
        return 11;
    return 1;
}

static int zero_format(char const *format, int co_mod, char *flag, double *arg)
{
    int acc = indicator_int(format, co_mod + 2);
    int fpos = my_strlen(flag) - 1;
    int length = 0;
    int len = get_print_len(flag[fpos]);

    if (format[co_mod + 1] != '0')
        return 0;
    if (*arg < 0) {
        length += my_count_putchar('-');
        *arg = - *arg;
        acc--;
    }
    len += my_countnbr((int)*arg);
    while (acc - len > 0) {
        length += my_count_putchar('0');
        acc--;
    }
    return length;
}

int float_flags_manager(char *flag, double arg, char const *format, int co_mod)
{
    int length = 0;
    int acc = 6;
    int fpos = my_strlen(flag) - 1;

    zero_format(format, co_mod, flag, &arg);
    if (format[co_mod + 1] == '+' && arg > 0)
        length += my_count_putchar('+');
    if (format[co_mod + 1] == '.')
        acc = indicator_int(format, co_mod + 2);
    if (flag[fpos] == 'f' || flag[fpos] == 'F')
        length = my_count_putfloat(&arg, acc);
    if (flag[fpos] == 'e')
        length = my_count_putsc(&arg, acc, 0);
    if (flag[fpos] == 'E')
        length = my_count_putsc(&arg, acc, 1);
    if (flag[fpos] == 'g' || flag[fpos] == 'G')
        length = is_f_or_e(&arg, flag, acc);
    return length;
}
