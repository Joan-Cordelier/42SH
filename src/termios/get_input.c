/*
** EPITECH PROJECT, 2023
** 42SH
** File description:
** manage_input.c
*/

#include "my.h"

static void print_final_output(char *str, size_t len)
{
    printf("\r");
    printf("\033[K");
    printf("\r$> ");
    printf("%s", str);
}

void init_struct_line(line_t *line)
{
    line->left = malloc(sizeof(char) * 1000);
    memset(line->left, '\0', 1000);
    line->right = malloc(sizeof(char) * 1000);
    memset(line->right, '\0', 1000);
    line->history_indice = 0;
    line->len_left = 0;
    line->len_right = 0;
}

char *recreate_getline(history_t *history)
{
    line_t *line = NULL;
    char *str = NULL;

    line = malloc(sizeof(line_t));
    init_struct_line(line);
    line_edition(line, history);
    str = concat(line->left, line->right);
    print_final_output(str, line->len_left + line->len_right);
    return str;
}

int get_input(char **input, history_t *history)
{
    size_t size = 0;

    if (!(isatty(STDIN_FILENO)))
        return (getline(input, &size, stdin));
    *input = recreate_getline(history);
    return 2;
}
