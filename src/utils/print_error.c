/*
** EPITECH PROJECT, 2024
** print_error
** File description:
** print_error
*/

#include "my.h"

void print_error(char *msg)
{
    write(2, msg, my_strlen(msg));
}
