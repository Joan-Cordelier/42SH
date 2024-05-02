/*
** EPITECH PROJECT, 2024
** commands
** File description:
** commands
*/

#include "my.h"

static int env_command(char **args, env_t *env, int *return_value)
{
    if (streq(args[0], "env")) {
        print_env(env->env);
        *return_value = 0;
        return 1;
    }
    if (streq(args[0], "unsetenv")) {
        env->env = my_unsetenv(args, &(env->env), return_value);
        return 1;
    }
    if (streq(args[0], "setenv")) {
        *return_value = 0;
        env->env = my_setenv(args, &(env->env), return_value);
        return 1;
    }
    return 0;
}

int run_builtins_command(char **args, env_t *env, int *return_value)
{
    check_exit(args);
    if (env_command(args, env, return_value) == 1)
        return 1;
    if (streq(args[0], "cd")) {
        *return_value = 0;
        changedir(args, env->env, env, return_value);
        return 1;
    }
    if (history_command(args, env, return_value) == 1)
        return 1;
    if (alias_command(args, env, return_value) == 1)
        return 1;
    if (var_command(args, env, return_value) == 1)
        return 1;
    return 0;
}

int check_exit(char **args)
{
    if (streq(args[0], "exit")) {
        exit(0);
    }
    return 0;
}
