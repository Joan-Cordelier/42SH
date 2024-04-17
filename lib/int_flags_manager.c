/*
** EPITECH PROJECT, 2023
** int_flags_manager
** File description:
** flag manager for int
*/

#include "my.h"

static const unsigned int unsigned_int = 4294967230;

int accuracy_printf(long long int *arg, int acc)
{
    int count = 0;
    int len_nbr = my_countnbr(*arg);

    if (*arg < 0) {
        count += my_count_putchar('-');
        *arg = - *arg;
    }
    for (; len_nbr < acc; len_nbr++) {
        count += my_count_putchar('0');
    }
    return count;
}

int int_flags_manager2(char *flag, long long int arg)
{
    int length = 0;
    unsigned int unsigned_arg = - (arg) + unsigned_int;
    int fpos = my_strlen(flag) - 1;

    if (flag[fpos] == 'u') {
        if (arg < 0) {
            length += my_count_putunsigned(unsigned_arg);
        } else {
            length += my_count_putunsigned(arg);
        }
    }
    if (flag[fpos] == 'x')
        length += my_count_puthex(arg, 0);
    if (flag[fpos] == 'X')
        length += my_count_puthex(arg, 1);
    return length;
}

static int positive_format(long long int arg, char format, char flag)
{
    int length = 0;

    if (format != '+')
        return 0;
    if (arg > 0 && (flag == 'd' || flag == 'i')) {
        length += my_count_putchar('+');
    }
    return length;
}

int int_flags_manager(char *flag, long long int arg, char const *format,
    int co_mod)
{
    int length = 0;
    int fpos = my_strlen(flag) - 1;
    int acc;

    if (format[co_mod + 1] == '.' || format[co_mod + 1] == '0') {
        acc = indicator_int(format, co_mod + 2);
        length += accuracy_printf(&arg, acc);
    }
    length += hashtag_indicator_int(flag, format, co_mod, arg);
    length += positive_format(arg, format[co_mod + 1], flag[fpos]);
    if (flag[fpos] == 'd' || flag[fpos] == 'i')
        length += my_count_putnbr(arg);
    if (flag[0] == 'l' && flag[fpos] == 'o') {
        length += my_display_long_octal(arg);
    } else {
    if (flag[fpos] == 'o')
        length += my_display_octal(arg);
    }
    return length + int_flags_manager2(flag, arg);
}
