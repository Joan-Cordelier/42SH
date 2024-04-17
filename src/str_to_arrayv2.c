/*
** EPITECH PROJECT, 2024
** str_to_array
** File description:
** 2nd version of my str to array
*/

#include "my.h"

static char *copy_string_between_logic(char *str, int start, int end)
{
    int len = end - start + 1;
    char *new_str = malloc(sizeof(char) * (len + 1));
    int i = 0;

    for (int j = start; j <= end; j++) {
        new_str[i] = str[j];
        i++;
    }
    new_str[i] = '\0';
    return new_str;
}

char *copy_string_between(char *str, int start, int end)
{
    int len;

    if (start > end)
        return NULL;
    if (str == NULL)
        return NULL;
    len = my_strlen(str);
    if (len < start || len < end)
        return NULL;
    if (len == 0)
        return NULL;
    return copy_string_between_logic(str, start, end);
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

    for (int i = 0; str[i] != '\0'; i++) {
        if (!is_separator(str[i], separator))
            start = 1;
        if ((is_separator(str[i], separator) && !is_separator(str[i + 1],
            separator))
            && str[i + 1] != '\0')
            count += start;
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

char **str_to_arr(char *str, char *separator)
{
    char **arr = malloc(sizeof(char *) * (count_word(str, separator) + 1));
    int start = 0;
    int end = 0;
    int curr = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        str_to_arr_logic(str[i], &start, &end, separator);
        if (is_separator(str[i], separator) && start != end) {
            end--;
            arr[curr] = copy_string_between(str, start, end);
            start = i + 1;
            end = i + 1;
            curr++;
        }
    }
    if (start != end)
        arr[curr] = copy_string_between(str, start, end);
    arr[count_word(str, separator)] = NULL;
    return arr;
}
