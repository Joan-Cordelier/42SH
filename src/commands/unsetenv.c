/*
** EPITECH PROJECT, 2024
** unsetenv
** File description:
** unsetenv
*/

#include "my.h"

static int get_new_size(char **args, char **env)
{
    int size = my_arraylen(env);

    for (int i = 1; args[i] != NULL; i++) {
        for (int j = 0; env[j] != NULL; j++)
            size -= streq(get_env_name(env[j]), args[i]);
    }
    return size;
}

static int is_removed(char **args, char **env, int j)
{
    for (int i = 1; args[i] != NULL; i++) {
        if (streq(args[i], get_env_name(env[j]))) {
            return 1;
        }
    }
    return 0;
}

char **
my_unsetenv(char **args, char ***env, int *return_value)
{
    int size = get_new_size(args, *env);
    char **new_env = malloc(sizeof(char *) * size);
    int i = 0;

    if (my_arraylen(args) == 1) {
        print_error("unsetenv: Too few arguments.\n");
        *return_value = 1;
        return *env;
    }
    for (int j = 0; (*env)[j] != NULL; j++) {
        if (!is_removed(args, *env, j)) {
            new_env[i] = my_strdup((*env)[j]);
            i++;
        }
    }
    new_env[size] = NULL;
    *return_value = 0;
    return new_env;
}
