/*
** EPITECH PROJECT, 2024
** init_env
** File description:
** init_env
*/

#include "my.h"

env_t *init_env(char **env)
{
    env_t *envir = malloc(sizeof(env_t));

    envir->var = NULL;
    add_var("?=0", &(envir->var));
    envir->job = malloc(sizeof(job_t));
    envir->alias = init_alias();
    envir->env = env;
    envir->history = NULL;
    envir->previous = my_strdup("");
    envir->builtins_return = malloc(sizeof(int));
    *(envir->builtins_return) = -1;
    return envir;
}
