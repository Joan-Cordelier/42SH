/*
** EPITECH PROJECT, 2024
** 42SH
** File description:
** logical_manager
*/

#include "my.h"

int logical_manager(char *input, env_t *env, int *child_pid, int *child_return)
{
    char **logics = str_to_arr_word(input, "&&", "||");

    for (int i = 0; logics[i] != NULL; i++) {
        if (logics[i][0] == '&' && logics[i][1] == '&') {
            continue;
        }
        if (logics[i][0] == '|' && logics[i][1] == '|') {
            continue;
        }
        manage_pipe(logics[i], env, child_pid, child_return);
    }
}
