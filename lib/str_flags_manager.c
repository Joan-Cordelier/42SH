/*
** EPITECH PROJECT, 2023
** str_flags_manager
** File description:
** flags manager for str
*/

#include "my.h"

int str_flags_manager(char *flag, char *arg)
{
    int length;
    int fpos = my_strlen(flag) - 1;

    if (flag[fpos] == 's') {
        length = my_count_putstr(arg);
    }
    return length;
}
