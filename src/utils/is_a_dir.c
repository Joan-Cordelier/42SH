/*
** EPITECH PROJECT, 2024
** minishell
** File description:
** minishell
*/

#include "my.h"

int is_a_dir(char *path)
{
    struct stat *stats = malloc(sizeof(struct stat));

    if (stat(path, stats) != 0) {
        free(stats);
        return - 1;
    }
    return S_ISDIR(stats->st_mode);
}
