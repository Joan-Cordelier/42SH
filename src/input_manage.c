/*
** EPITECH PROJECT, 2024
** minishell2
** File description:
** input_manage
*/

#include "my.h"

static void pipe_manager(pipe_t *pipe)
{
    if (!pipe->is_first)
        dup2(pipe->pipefd[pipe->index - 1][0], STDIN_FILENO);
    if (!pipe->is_last)
        dup2(pipe->pipefd[pipe->index][1], STDOUT_FILENO);
    if (pipe->output != 0)
        dup2(pipe->output, STDOUT_FILENO);
    if (pipe->input != 0)
        dup2(pipe->input, STDIN_FILENO);
    close(pipe->pipefd[pipe->index][0]);
    close(pipe->pipefd[pipe->index][1]);
}

static int redirect_manager(char **arr, pipe_t *pipe)
{
    int err = check_redirect_amount(arr);

    pipe->righ_redirect = 0;
    pipe->left_redirect = 0;
    if (err < 0)
        return err;
    for (int i = 0; arr[i] != NULL; i++) {
        pipe->righ_redirect += (arr[i][0] == '>') ? 1 : 0;
        pipe->left_redirect += (arr[i][0] == '<') ? 1 : 0;
        if (arr[i][0] != '>' && arr[i][0] != '<')
            get_redirection(arr, pipe, i);
        if (pipe->err > 0)
            return - 1;
    }
    return 0;
}

int input_manager(char *input, env_t *env, int *child_pid, pipe_t *pipe)
{
    char **args = NULL;

    args = str_to_arr(input, " \t\n");
    if (my_arraylen(args) == 0)
        return 84;
    if (pipe->is_last) {
        if (run_builtins_command(args, env, env->builtins_return))
            return 1;
    }
    *(env->builtins_return) = - 1;
    *child_pid = fork();
    if (*child_pid != 0)
        return 0;
    pipe_manager(pipe);
    execute(args, env->env, env);
    exit(1);
}

int manage_redirect(char *input, env_t *env, int i, pipe_t *pipe)
{
    char **redirects = str_to_arr2(input, "><");
    int child_pid = 0;
    int redirect_valid = redirect_error(redirects);

    if (redirect_valid < 0) {
        *env->builtins_return = 1;
        return 1;
    }
    if (redirect_manager(redirects, pipe) < 0) {
        *env->builtins_return = 1;
        return 1;
    }
    if (input_manager(redirects[0], env, &child_pid, pipe) != 1) {
            close(pipe->pipefd[i][1]);
            pipe->is_first = 0;
    }
    return child_pid;
}

int manage_input(char *input, env_t *env, int *child_pid, int *child_return)
{
    char **commands;

    if (my_strlen(input) <= 0)
        return 84;
    commands = str_to_arr(input, ";\n");
    for (int i = 0; commands[i] != NULL; i++) {
        if (is_empty(commands[i]))
            continue;
        if (!is_pipe_valid(commands[i])) {
            print_error("Invalid null command.\n");
            *(env->builtins_return) = 1;
            return 0;
        }
        logical_manager(commands[i], env, child_pid, child_return);
        //manage_pipe(commands[i], env, child_pid, child_return);
    }
    return 0;
}
