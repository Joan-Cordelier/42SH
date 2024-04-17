/*
** EPITECH PROJECT, 2024
** minishell2
** File description:
** str_to_arrayv3
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

static int count_word(char *str, char *separator)
{
    int count = 0;
    int start = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (!is_separator(str[i], separator))
            start = 1;
        if ((is_separator(str[i], separator) && !is_separator(str[i + 1],
            separator))
            && str[i + 1] != '\0')
            count += start;
        if (is_separator(str[i], separator))
            count += 1;
    }
    return count + 1;
}

static void str_to_arr_logic(char c, int *start, int *end, char *separator)
{
    if (is_separator(c, separator) && *start == *end) {
            *start += 1;
            *end += 1;
        }
    if (!is_separator(c, separator)) {
            *end += 1;
        }
}

static char *str_to_arr_logic2(char *str, int i, int *start, int *end)
{
    char *string = copy_string_between(str, *start, *end - 1);

    *end = *end - 1;
    *start = i + 1;
    *end = i + 1;
    return string;
}

char **str_to_arr2(char *str, char *separator)
{
    char **arr = malloc(sizeof(char *) * (count_word(str, separator) + 1));
    int start = 0;
    int end = 0;
    int curr = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        str_to_arr_logic(str[i], &start, &end, separator);
        if (is_separator(str[i], separator) && start != end) {
            arr[curr] = str_to_arr_logic2(str, i, &start, &end);
            curr++;
        }
        if (is_separator(str[i], separator)) {
            arr[curr] = copy_string_between(str, i, i);
            curr++;
        }
    }
    if (start != end)
        arr[curr] = copy_string_between(str, start, end);
    arr[count_word(str, separator)] = NULL;
    return arr;
}
