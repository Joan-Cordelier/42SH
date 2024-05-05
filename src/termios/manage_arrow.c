/*
** EPITECH PROJECT, 2023
** 42SH
** File description:
** manage_arrow.c
*/

#include "my.h"

static char *my_strcat_begining(char c, char *str)
{
    char *cpy = my_strdup(str);
    int j = 1;

    str[0] = c;
    for (int i = 0; cpy[i] != '\0'; i++) {
        str[j] = cpy[i];
        j++;
    }
    free(cpy);
    str[j] = '\0';
    return str;
}

static char *rm_first_char(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        str[i] = str[i + 1];
    return str;
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
