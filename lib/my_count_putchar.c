/*
** EPITECH PROJECT, 2023
** my_count_putchar
** File description:
** putchar with counting option
*/

#include <unistd.h>

int my_count_putchar(char c)
{
    write(1, &c, 1);
    return 1;
}
