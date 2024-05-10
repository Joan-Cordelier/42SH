/*
** EPITECH PROJECT, 2024
** 42SH
** File description:
** var
*/

#include "my.h"

void replace_var(char **args, var_t *var, int i)
{
    for (var_t *tmp = var; tmp; tmp = tmp->next) {
        if (my_strlen(args[i]) < 2)
            continue;
        if ((args[i][0]) == '$' && streq(args[i] + 1, tmp->str)) {
            free(args[i]);
            args[i] = my_strdup(tmp->alias);
        }
    }
}

void replace_vars(char **args, env_t *envir)
{
    for (int i = 0; args[i]; i++) {
        replace_var(args, envir->var, i);
    }
}
