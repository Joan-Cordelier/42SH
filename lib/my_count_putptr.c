/*
** EPITECH PROJECT, 2023
** my_count_putptr
** File description:
** print the adress of a variable
*/

#include "my.h"

int my_count_putptr(void *ptr)
{
    int count = 0;

    count += my_count_putstr("0x");
    count += my_count_puthex((long int)ptr, 0);
    return count;
}
