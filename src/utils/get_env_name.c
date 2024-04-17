/*
** EPITECH PROJECT, 2024
** streq
** File description:
** streq
*/

#include "my.h"

char *get_env_name(char *env)
{
    int i = 0;

    while (env[i] != '\0') {
        if (env[i] == '=')
            break;
        i++;
    }
    return copy_string_between(env, 0, i - 1);
}
