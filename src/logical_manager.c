/*
** EPITECH PROJECT, 2024
** 42SH
** File description:
** logical_manager
*/

#include "my.h"

static int is_logic(char *input)
{
    if (input[0] == '&' && input[1] == '&')
        return 1;
    if (input[0] == '|' && input[1] == '|')
        return 1;
    return 0;
}

static int logic_error(char **logics)
{
    for (int i = 0; logics[i] != NULL; i++) {
        if (logics[i][0] == '|' && i == 0)
            return 1;
        if (logics[i][0] == '|' && logics[i + 1] == NULL)
            return 1;
        if (logics[i][0] == '|' && is_logic(logics[i + 1]))
            return 1;
        if (logics[i][0] == '|' && is_logic(logics[i - 1]))
            return 1;
        if (logics[i][0] == '&' && logics[i + 1] == NULL)
            return 1;
    }
    return 0;
}

static int logic_handler(char *input, int *child_return)
{
    if (input[0] == '&' && input[1] == '&') {
        if ((*child_return) == 0)
            return 1;
        return 0;
    }
    if (input[0] == '|' && input[1] == '|') {
        if ((*child_return) != 0)
            return 1;
        return 0;
    }
    return 1;
}

int logical_manager(char *input, env_t *env, int *child_pid, int *child_return)
{
    char **logics = str_to_arr_word(input, "&&", "||");
    int can_exec = 1;

    if (logic_error(logics)) {
        write(2, "Invalid null command.\n", 23);
        (*env->builtins_return) = 1;
        return 1;
    }
    for (int i = 0; logics[i] != NULL; i++) {
        if (is_logic(logics[i])) {
            can_exec = logic_handler(logics[i], child_return);
            continue;
        }
        if (can_exec == 0)
            continue;
        manage_pipe(logics[i], env, child_pid, child_return);
    }
}
