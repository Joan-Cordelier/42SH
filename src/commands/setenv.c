/*
** EPITECH PROJECT, 2024
** etenv
** File description:
** setenv
*/

#include "my.h"

static int get_new_size(char **args, char **env)
{
    int size = my_arraylen(env);

    if (args[1] == NULL)
        return size;
    for (int i = 0; env[i] != NULL; i++) {
        if (streq(get_env_name(env[i]), args[1]))
            return size;
    }
    return size + 1;
}

char *change_env(char **env, char *key, char *value)
{
    *env = concat(key, "=");
    if (value == NULL)
        return *env;
    *env = concat(*env, value);
    return *env;
}

static int is_alpha_num(char c)
{
    if ((c >= 'a' && c <= 'z') ||
    (c >= 'A' && c <= 'Z') ||
    (c >= '0' && c <= '9') ||
    c == '_')
        return 1;
    return 0;
}

static int is_first_letter_valid(char *name)
{
    if ((name[0] >= 'a' && name[0] <= 'z') ||
    (name[0] >= 'A' && name[0] <= 'Z')) {
        return 1;
    }
    return 0;
}

static int is_name_valid(char *name)
{
    if (!is_first_letter_valid(name)) {
        print_error("setenv: Variable name must begin with a letter.\n");
        return 0;
    }
    for (int i = 1; name[i] != '\0'; i++) {
        if (!is_alpha_num(name[i])) {
            print_error("setenv: Variable name must contain"
                " alphanumeric characters.\n");
            return 0;
        }
    }
    return 1;
}

char **fill_new_env(char **args, char **env, char **new_env)
{
    int i = 0;

    for (; env[i] != NULL; i++) {
        new_env[i] = my_strdup(env[i]);
    }
    new_env[i] = concat(args[1], "=");
    if (args[2])
        new_env[i] = concat(new_env[i], args[2]);
    return new_env;
}

static int special_case(char **args, char **env, int *return_value)
{
    if (my_arraylen(args) == 1) {
        print_env(env);
        return 1;
    }
    if (my_arraylen(args) > 3) {
        print_error("setenv: Too many arguments.\n");
        *return_value = 1;
        return 1;
    }
    if (!is_name_valid(args[1])) {
        *return_value = 1;
        return 1;
    }
    return 0;
}

char **my_setenv(char **args, char ***env, int *return_value)
{
    int size = get_new_size(args, *env);
    char **new_env = malloc(sizeof(char *) * size);

    if (special_case(args, *env, return_value))
        return *env;
    if (size != my_arraylen(*env)) {
        new_env = fill_new_env(args, *env, new_env);
        new_env[size] = NULL;
        return new_env;
    }
    for (int i = 0; (*env)[i] != NULL; i++) {
        if (streq(get_env_name((*env)[i]), args[1]))
            change_env(&((*env)[i]), args[1], args[2]);
    }
    return *env;
}
