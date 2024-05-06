/*
** EPITECH PROJECT, 2023
** 42SH
** File description:
** exclamations.c
*/

#include "my.h"

int simple_exclamations(line_t *line, history_t *history)
{
    return 1;
}

int manage_exclamations(line_t *line, history_t *history)
{
    char *str = NULL;
    int end = 0;

    str = concat(line->left, line->right);
    str = strsub_from_char(str, '\n');
    if (strcmp(str, "!!") == 0) {
        manage_arrow_up_down(UP_K, line, history);
        end = 0;
    } else if (strcmp(str, "!") == 0)
        end = simple_exclamations(line, history);
    else
        end = 1;
    free(str);
    return end;
}
