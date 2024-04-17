/*
** EPITECH PROJECT, 2024
** streq
** File description:
** streq
*/

#include "my.h"

int streq(char *str, char *str2)
{
    if (my_strlen(str) != my_strlen(str2))
        return 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != str2[i])
            return 0;
    }
    return 1;
}
