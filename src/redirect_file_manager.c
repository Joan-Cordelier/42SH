/*
** EPITECH PROJECT, 2024
** minishell2
** File description:
** redirect_file_manager
*/

#include "my.h"

void file_open_error(int err, char *name, pipe_t *pipe)
{
    if (err == ENOENT) {
        print_error(name);
        print_error(": No such file or directory.\n");
        pipe->err = 1;
    }
}

static void right_redirect(pipe_t *pipe, char **arr, int i)
{
    int fd = 0;
    char **cleanstr = NULL;

    cleanstr = str_to_arr(arr[i], " \t\n");
    fd = open(cleanstr[0], O_CREAT | O_TRUNC | O_WRONLY, 0666);
    if (fd == - 1)
        return;
    pipe->output = fd;
}

static void double_right_redirect(pipe_t *pipe, char **arr, int i)
{
    int fd = 0;
    char **cleanstr = NULL;

    cleanstr = str_to_arr(arr[i], " \t\n");
    fd = open(cleanstr[0], O_CREAT | O_APPEND | O_WRONLY, 0666);
    if (fd == - 1)
        return;
    pipe->output = fd;
}

static void left_redirect(pipe_t *pipe, char **arr, int i)
{
    int fd = 0;
    char **cleanstr = NULL;

    cleanstr = str_to_arr(arr[i], " \t\n");
    if (cleanstr == NULL)
        return;
    fd = open(cleanstr[0], O_RDONLY);
    if (fd == - 1) {
        file_open_error(errno, cleanstr[0], pipe);
        return;
    }
    pipe->input = fd;
}

void get_redirection(char **arr, pipe_t *pipe, int i)
{
    pipe->output = 0;
    pipe->input = 0;
    pipe->err = 0;
    if (pipe->righ_redirect == 1)
        right_redirect(pipe, arr, i);
    if (pipe->righ_redirect == 2)
        double_right_redirect(pipe, arr, i);
    if (pipe->left_redirect == 1)
        left_redirect(pipe, arr, i);
}
