/*
** EPITECH PROJECT, 2023
** my_strlen.c
** File description:
** task 02
*/

#include <stdlib.h>

int my_strlen(char const *str)
{
    int i = 0;

    while (str != NULL && str[i] != '\0') {
        i++;
    }
    return i;
}

int my_tablen(char **str)
{
    int i = 0;

    while (str[i] != NULL) {
        i++;
    }
    return i;
}
