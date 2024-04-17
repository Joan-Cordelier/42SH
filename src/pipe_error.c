/*
** EPITECH PROJECT, 2024
** minishell2
** File description:
** pipe_error
*/

#include "my.h"

static int is_separator(char c, char *separator)
{
    for (int i = 0; separator[i] != '\0'; i++) {
        if (c == separator[i])
            return 1;
    }
    return 0;
}

static int can_be_a_command(char *str)
{
    int valid = 0;
    char sep[] = {" \t\n"};

    for (int i = 0; str[i] != 0; i++) {
        if (!is_separator(str[i], sep))
            valid = 1;
    }
    return valid;
}

int is_pipe_valid(char *str)
{
    char **arr = str_to_arr2(str, "|");

    for (int i = 0; arr[i] != NULL; i++) {
        if (arr[i][0] == '|' && i == 0)
            return 0;
        if (arr[i][0] == '|' && arr[i + 1] == NULL)
            return 0;
        if (arr[i][0] == '|' && !can_be_a_command(arr[i - 1]))
            return 0;
        if (arr[i][0] == '|' && !can_be_a_command(arr[i + 1]))
            return 0;
    }
    return 1;
}
