/*
** EPITECH PROJECT, 2023
** mini_printf
** File description:
** print the argument , can take some flag.
*/

#include "my.h"

int flags_manager2(va_list list, char *flag)
{
    int len = 0;
    int fpos = my_strlen(flag) - 1;

    if (flag[fpos] == 'p')
        len = my_count_putptr(va_arg(list, void *));
    return len;
}

static int do_space(char c)
{
    int len = 0;

    if (c == ' ') {
        len += my_count_putchar(' ');
    }
    return len;
}

int flags_manager(char const *format, va_list list, int co_mod, char *flag)
{
    int len = 0;
    int fpos = my_strlen(flag) - 1;

    len += do_space(format[co_mod + 1]);
    if (flag[fpos] == 'd' || flag[fpos] == 'i' || flag[fpos] == 'o' ||
        flag[fpos] == 'u' || flag[fpos] == 'x' || flag[fpos] == 'X')
        len += int_flags_manager(flag, va_arg(list, int), format, co_mod);
    if (flag[fpos] == 'c' || flag[fpos] == 'C')
        len += my_count_putchar(va_arg(list, int));
    if (flag[fpos] == 's')
        len += my_count_putstr(va_arg(list, const char *));
    if (flag[fpos] == '%')
        len += my_count_putchar('%');
    if (flag[fpos] == 'e' || flag[fpos] == 'E' || flag[fpos] == 'f' ||
        flag[fpos] == 'F' || flag[fpos] == 'g' || flag[fpos] == 'G')
        len += float_flags_manager(flag, va_arg(list, double), format, co_mod);
    len += flags_manager2(list, flag);
    if (format[co_mod + 1] == '-')
        len += minus_indicator(format, co_mod, len);
    return len;
}

char *define_flag(char const *format, int *i)
{
    char *flag = malloc(sizeof(char) * my_strlen(format));
    int j = 0;

    my_memset(flag, '\0', sizeof(char) * my_strlen(format));
    *i = *i + 1;
    while (is_flag(format[*i]) != 1 && is_size_prefix(format[*i]) != 1) {
        *i = *i + 1;
    }
    while (is_flag(format[*i]) != 1) {
        flag[j] = format[*i];
        *i = *i + 1;
        j++;
    }
    flag[j] = format[*i];
    return flag;
}

int print_arg(const char *format, va_list list)
{
    int len = 0;
    int *nb;
    int co_mod;
    char *flag;

    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%' && format[i + 1] == 'n') {
                nb = va_arg(list, int *);
            *nb = len;
        }
        if (format[i] == '%') {
            co_mod = i;
            flag = define_flag(format, &i);
            len += flags_manager(format, list, co_mod, flag);
            free(flag);
        } else {
            len += my_count_putchar(format[i]);
        }
    }
    return len;
}

int my_printf(const char *format, ...)
{
    int len = 0;
    va_list list;

    va_start(list, format);
    len = print_arg(format, list);
    va_end(list);
    return len;
}
