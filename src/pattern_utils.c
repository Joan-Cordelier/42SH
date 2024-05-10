/*
** EPITECH PROJECT, 2024
** pattern_utils
** File description:
** pattern_utils
*/

#include "my.h"

bool check_char(const char *str, const char *special_chars)
{
    const char *c = special_chars;

    while (*c != '\0') {
        if (*str == *c) {
            return true;
        }
        c++;
    }
    return false;
}

bool contains_pattern(const char *str, const char *special_chars)
{
    while (*str != '\0') {
        if (check_char(str, special_chars)) {
            return true;
        }
        str++;
    }
    return false;
}
