/*
** EPITECH PROJECT, 2023
** my_count_putstr
** File description:
** putstr with counting option
*/

#include "my.h"

int my_count_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0'){
        my_count_putchar(str[i]);
        i++;
    }
    return i;
}

void my_putstr(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        my_count_putchar(str[i]);
    }
}
