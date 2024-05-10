/*
** EPITECH PROJECT, 2024
** 42SH
** File description:
** act_ret_value
*/

#include "my.h"

char *int_to_str(int nb)
{
    int len = snprintf(NULL, 0, "%d", nb);
    char *str = (char *)malloc(len + 1);

    snprintf(str, len + 1, "%d", nb);
    return str;
}
