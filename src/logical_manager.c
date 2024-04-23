/*
** EPITECH PROJECT, 2024
** 42SH
** File description:
** logical_manager
*/

#include "my.h"

int logical_manager(char *input, int *child_return, pipe_t *pip)
{
    if (input[0] == '&' && input[1] == '&') {
        if (*child_return == 0) {
            pip->can_execute = 1;
            return 0;
        }
        pip->can_execute = 0;
        return 0;
    }
    pip->can_execute = 1;
    return 1;
}
