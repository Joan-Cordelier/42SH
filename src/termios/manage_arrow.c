/*
** EPITECH PROJECT, 2023
** 42SH
** File description:
** manage_arrow.c
*/

#include "my.h"

void reset_line_up(line_t *line, history_t *history)
{
    line->len_right = 0;
    if (line->history_indice == 0)
        line->history_indice = history->i;
    else
        line->history_indice--;
    for (history_t *temp = history; temp != NULL; temp = temp->next) {
        if (temp->i == line->history_indice) {
            line->left = strcpy(line->left, temp->str);
            line->left = strsub_from_char(line->left, '\n');
            line->len_left = strlen(line->left);
        }
    }
}

void reset_line_down(line_t *line, history_t *history)
{
    line->len_right = 0;
    if (line->history_indice == history->i) {
        line->history_indice = 0;
        return;
    }
    line->history_indice++;
    for (history_t *temp = history; temp != NULL; temp = temp->next) {
        if (temp->i == line->history_indice) {
            line->left = strcpy(line->left, temp->str);
            line->left = strsub_from_char(line->left, '\n');
            line->len_left = strlen(line->left);
        }
    }
}

void manage_arrow_up_down(char c, line_t *line, history_t *history)
{
    if (history == NULL)
        return;
    if (c == UP_K) {
        if (line->history_indice == 1)
            return;
        reset_line(line);
        reset_line_up(line, history);
    }
    if (c == DOWN_K) {
        if (line->history_indice == 0)
            return;
        reset_line(line);
        reset_line_down(line, history);
    }
}

void manage_arrow_left_right(char c, line_t *line)
{
    if (c == LEFT_K) {
        if (line->len_left < 1)
            return;
        line->right = my_strcat_begining(
            (line->left[line->len_left - 1]), line->right);
        line->len_left--;
        line->len_right++;
        line->left[line->len_left] = '\0';
    }
    if (c == RIGHT_K) {
        if (line->len_right < 1)
            return;
        line->left[line->len_left] = line->right[0];
        line->len_left++;
        line->len_right--;
        line->right = rm_first_char(line->right);
        line->left[line->len_left] = '\0';
    }
}
