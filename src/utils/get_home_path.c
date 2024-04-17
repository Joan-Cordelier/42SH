/*
** EPITECH PROJECT, 2024
** homepath
** File description:
** homepath
*/

#include "my.h"

static char *get_path(char **env, int i)
{
    for (int j = 0; env[i][j] != '\0'; j++) {
        if (env[i][j] == '=') {
            return copy_string_between(env[i], j + 1, my_strlen(env[i]) - 1);
        }
    }
    return NULL;
}

char *get_home(char **env)
{
    for (int i = 0; env[i] != NULL; i++) {
        if (streq(get_env_name(env[i]), "HOME")) {
            return get_path(env, i);
        }
    }
    return NULL;
}
