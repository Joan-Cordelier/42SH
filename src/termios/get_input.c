/*
** EPITECH PROJECT, 2023
** 42SH
** File description:
** manage_input.c
*/

#include "my.h"

static void refrech_output(line_t *line)
{
    printf("\r");
    for (size_t i = 0; i < line->len_left + 4; i++)
        printf(" ");
    printf("\r$> ");
    printf("%s", line->left);
}

void manage_current_line(char c, line_t *line)
{
    if (c == 127) {
        if (line->len_left >= 1)
            line->len_left--;
        line->left[line->len_left] = '\0';
    } else {
        line->left[line->len_left] = c;
        line->len_left = strlen(line->left);
    }
}

void manage_arrow(char c, line_t *line)
{
    if (c == -1) {
        if (line->len_left < 1)
            return;
        line->len_left--;
    }
    if (c == -2) {
        if (line->left[line->len_left] == '\0')
            return;
        line->len_left++;
    }
}

void init_struct_line(line_t *line)
{
    line->left = malloc(sizeof(char) * 1000);
    memset(line->left, '\0', 1000);
    line->right = malloc(sizeof(char) * 1000);
    memset(line->right, '\0', 1000);
    line->len_left = 0;
    line->len_right = 0;
}

char *recreate_getline(void)
{
    int c = 0;
    line_t *line = NULL;

    line = malloc(sizeof(line_t));
    init_struct_line(line);
    while (1) {
        c = manage_char();
        if (c == 4)
            exit(0);
        if (c > 0)
            manage_current_line(c, line);
        else
            manage_arrow(c, line);
        refrech_output(line);
        if (c == 10)
            break;
    }
    return line->left;
}

int get_input(char **input)
{
    size_t size = 0;

    if (!(isatty(STDIN_FILENO)))
        return (getline(input, &size, stdin));
    *input = recreate_getline();
    return 2;
}
