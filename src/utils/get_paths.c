/*
** EPITECH PROJECT, 2024
** paths
** File description:
** paths
*/

#include "my.h"

char *get_path(char **env)
{
    for (int i = 0; env[i] != NULL; i++) {
        if (streq(get_env_name(env[i]), "PATH")) {
            return env[i];
        }
    }
    return NULL;
}

char *get_path_value(char *env)
{
    int i = 0;

    while (env[i] != '=')
        i++;
    return copy_string_between(env, i + 1, my_strlen(env));
}

char **get_paths(char **env)
{
    char *path_env = get_path(env);
    char **paths;

    if (path_env == NULL)
        return NULL;
    paths = str_to_arr(get_path_value(path_env), ":");
    return paths;
}
