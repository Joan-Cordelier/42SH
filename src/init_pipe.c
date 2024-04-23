/*
** EPITECH PROJECT, 2024
** minishell2
** File description:
** init_pipe
*/

#include "my.h"

pipe_t *init_pipe(char **arr)
{
    pipe_t *pipes = malloc(sizeof(pipe_t));
    int i = 0;

    while (arr[i] != NULL)
        i++;
    pipes->is_first = 1;
    pipes->is_last = 0;
    pipes->left_redirect = 0;
    pipes->righ_redirect = 0;
    pipes->output = STDOUT_FILENO;
    pipes->input = STDIN_FILENO;
    pipes->err = 0;
    return pipes;
}
