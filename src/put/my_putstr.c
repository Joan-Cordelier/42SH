/*
** EPITECH PROJECT, 2023
** my_putstr
** File description:
** string
*/

#include "my.h"

int my_putstr(char const *str)
{
    int cpt = 0;

    while (str[cpt] != '\0') {
        cpt++;
    }
    write(1, str, cpt);
    return cpt;
}
