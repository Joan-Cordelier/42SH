/*
** EPITECH PROJECT, 2024
** 42_SH
** File description:
** manage_pipe
*/

#include "my.h"

static int is_last_pipe(char **pipes, int i)
{
    for (int j = i; pipes[j] != NULL; j++) {
        if (pipes[j][0] == '|' && pipes[j][1] == 0) {
            return 0;
        }
    }
    return 1;
}

static void set_pipe_value(pipe_t **pip, int pipenb, char **pipes, int i)
{
    pipe((*pip)->pipefd[pipenb]);
    (*pip)->index = pipenb;
    (*pip)->is_last = is_last_pipe(pipes, i);
}

int manage_pipe(char *input, env_t *env, int *child_pid, int *child_return)
{
    char **pipes = str_to_arr_pipes(input);
    pipe_t *pip = init_pipe(pipes);
    int pipenb = 0;

    for (int i = 0; pipes[i] != NULL; i++) {
        if ((pipes[i][0] == '|' && pipes[i][1] == 0)) {
            pipenb += 1;
            continue;
        }
        if (pip->can_execute == 0) {
            continue;
        }
        if (logical_manager(pipes[i], child_return, pip) == 0) {
            continue;
        }
        set_pipe_value(&pip, pipenb, pipes, i);
        *child_pid = manage_redirect(pipes[i], env, pipenb, pip);
    }
    if (*child_pid > 0) {
        waitpid(*child_pid, child_return, 0);
        child_signaled(*child_return);
    }
    free(pip);
    return 0;
}
