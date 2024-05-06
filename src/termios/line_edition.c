/*
** EPITECH PROJECT, 2023
** 42SH
** File description:
** line_edition.c
*/

#include "my.h"

static void refrech_output(line_t *line)
{
    printf("\r");
    for (size_t i = 0; i < (line->len_left + line->len_right + 5); i++)
        printf(" ");
    printf("\r$> ");
    printf("%s", line->left);
    printf("\033[C");
    printf("%s", line->right);
}

void manage_current_line(char c, line_t *line)
{
    if (c == 10) {
        line->right[line->len_right] = c;
        line->len_right++;
        return;
    }
    if (c == 127) {
        if (line->len_left >= 1)
            line->len_left--;
        line->left[line->len_left] = '\0';
    } else {
        line->left[line->len_left] = c;
        line->len_left = strlen(line->left);
    }
}

void manage_arrow(char c, line_t *line, history_t *history)
{
    if (c == LEFT_K || c == RIGHT_K)
        manage_arrow_left_right(c, line);
    if (c == UP_K || c == DOWN_K)
        manage_arrow_up_down(c, line, history);
}

void line_edition(line_t *line, history_t *history)
{
    int c = 0;
    int end = 0;

    while (1) {
        refrech_output(line);
        c = manage_char();
        if (c == 4)
            exit(0);
        if (c > 0)
            manage_current_line(c, line);
        else
            manage_arrow(c, line, history);
        if (c == 10)
            end = manage_exclamations(line, history);
        if (end != 0)
            break;
    }
}
