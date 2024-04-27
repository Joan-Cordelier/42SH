/*
** EPITECH PROJECT, 2024
** minishell2
** File description:
** str_to_arrayv3
*/

#include "my.h"

static void test_inib(int *inib, char c)
{
    if (c == '\"') {
        if (*inib == '\"')
            *inib = 0;
        if (*inib == 0)
            *inib = '\"';
    }
    if (c == '\'') {
        if (*inib == '\'')
            *inib = 0;
        if (*inib == 0)
            *inib = '\'';
    }
}

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
    int inib = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        test_inib(&inib, str[i]);
        if (!is_separator(str[i], separator))
            start = 1;
        if ((is_separator(str[i], separator) && !is_separator(str[i + 1],
            separator)) && str[i + 1] != '\0' && inib == 0)
            count += start;
        if (is_separator(str[i], separator) && inib == 0)
            count += 1;
    }
    return count + 1;
}

static void str_to_arr_logic(char c, int pos[2], char *separator, int *inib)
{
    test_inib(inib, c);
    if (is_separator(c, separator) && pos[0] == pos[1] && *inib == 0) {
        pos[0] += 1;
        pos[1] += 1;
    }
    if (!is_separator(c, separator)) {
        pos[1] += 1;
    }
}

static char *str_to_arr_logic2(char *str, int i, int pos[2])
{
    char *string = copy_string_between(str, pos[0], pos[1] - 1);

    pos[1] = pos[1] - 1;
    pos[0] = i + 1;
    pos[1] = i + 1;
    return string;
}

char **str_to_arr2(char *str, char *separator)
{
    char **arr = malloc(sizeof(char *) * (count_word(str, separator) + 1));
    int pos[2] = {0, 0};
    int inib = 0;
    int curr = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        str_to_arr_logic(str[i], pos, separator, &inib);
        if (is_separator(str[i], separator) && pos[0] != pos[1] && inib == 0) {
            arr[curr] = str_to_arr_logic2(str, i, pos);
            curr++;
        }
        if (is_separator(str[i], separator) && inib == 0) {
            arr[curr] = copy_string_between(str, i, i);
            curr++;
        }
    }
    if (pos[0] != pos[1])
        arr[curr] = copy_string_between(str, pos[0], pos[1]);
    arr[count_word(str, separator)] = NULL;
    return arr;
}
