/*
** EPITECH PROJECT, 2023
** 42SH
** File description:
** exclamations.c
*/

#include "my.h"

static void reset_line_exclam(line_t *line, char *str)
{
    memset(line->left, '\0', 1000);
    memset(line->right, '\0', 1000);
    printf("\r");
    printf("\033[K");
    printf("\r$> ");
    printf("%s", str);
    printf("\033[C");
}

int simple_exclamations(line_t *line, history_t *history, char *str)
{
    str = rm_first_char(str);
    while (history != NULL) {
        if (strncmp(str, history->str, strlen(str)) == 0) {
            reset_line_exclam(line, history->str);
            line->left = strcpy(line->left, history->str);
            line->left = strsub_from_char(line->left, '\n');
            line->len_left = strlen(line->left);
            break;
        }
        history = history->next;
    }
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
    } else if (str[0] == '!')
        end = simple_exclamations(line, history, str);
    else
        end = 1;
    free(str);
    return end;
}
