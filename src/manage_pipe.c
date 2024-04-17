/*
** EPITECH PROJECT, 2024
** 42_SH
** File description:
** manage_pipe
*/

#include "my.h"

static void set_pipe_value(pipe_t **pip, int pipenb, char **pipes, int i)
{
    pipe((*pip)->pipefd[pipenb]);
    (*pip)->index = pipenb;
    if (pipes[i + 1] != NULL)
        (*pip)->is_last = 0;
    if (pipes[i + 1] == NULL)
        (*pip)->is_last = 1;
}

int manage_pipe(char *input, env_t *env, int *child_pid, int *child_return)
{
    char **pipes = str_to_arr_pipes(input);
    pipe_t *pip = init_pipe(pipes);
    int pipenb = 0;

    for (int i = 0; pipes[i] != NULL; i++) {
        if (pipes[i][0] == '|' && pipes[i][1] == 0)
            continue;
        set_pipe_value(&pip, pipenb, pipes, i);
        *child_pid = manage_redirect(pipes[i], env, pipenb, pip);
        pipenb += 1;
    }
    if (*child_pid > 0) {
        waitpid(*child_pid, child_return, 0);
        child_signaled(*child_return);
    }
    free(pip);
    return 0;
}
