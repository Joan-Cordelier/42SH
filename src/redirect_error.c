/*
** EPITECH PROJECT, 2024
** minishell2
** File description:
** redirect_error
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

static int is_a_redirect_char(char c)
{
    if (c == '>' || c == '<')
        return 1;
    return 0;
}

int is_redirect_valid(char **arr)
{
    for (int i = 0; arr[i] != NULL; i++) {
        if (is_a_redirect_char(arr[i][0]) && i == 0) {
            print_error("Invalid null command.\n");
            return - 1;
        }
        if (is_a_redirect_char(arr[i][0]) && arr[i + 1] == NULL) {
            print_error("Missing name for redirect.\n");
            return - 2;
        }
        if (is_a_redirect_char(arr[i][0]) && !can_be_a_command(arr[i - 1])) {
            print_error("Invalid null command.\n");
            return - 1;
        }
        if (is_a_redirect_char(arr[i][0]) && !can_be_a_command(arr[i + 1])) {
            print_error("Missing name for redirect.\n");
            return - 2;
        }
    }
    return 1;
}

static int is_redirect_changing(char **arr, int i)
{
    if ((arr[i][0] == '>' && arr[i + 1][0] == '<') ||
            (arr[i][0] == '<' && arr[i + 1][0] == '>'))
            return 1;
    return 0;
}

int redirect_error(char **arr)
{
    int err = is_redirect_valid(arr);
    int in_cmd = 0;

    if (err < 0)
        return err;
    for (int i = 0; arr[i] != NULL; i++) {
        in_cmd += (arr[i][0] == '>') ? 1 : 0;
        in_cmd += (arr[i][0] == '<') ? 1 : 0;
        if (is_redirect_changing(arr, i)) {
            print_error("Missing name for redirect.\n");
            return - 1;
        }
        if (can_be_a_command(arr[i]) && (arr[i][0] != '>' && arr[i][0] != '<'))
            in_cmd = 0;
        if (in_cmd > 2) {
            print_error("Missing name for redirect.\n");
            return - 1;
        }
    }
    return 0;
}

int check_redirect_amount(char **arr)
{
    int right = 0;
    int left = 0;

    for (int i = 0; arr[i] != NULL; i++) {
        right += (arr[i][0] == '>') ? 1 : 0;
        left += (arr[i][0] == '<') ? 1 : 0;
        if (right > 2 || left > 2) {
            print_error("Ambiguous output redirect.\n");
            return -1;
        }
    }
    return 0;
}
