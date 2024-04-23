/*
** EPITECH PROJECT, 2024
** 42SH
** File description:
** str_to_arr_word
*/

#include "my.h"

static int count_words(char *str, char *word)
{
    char *tmp = str;
    int words = 0;
    int run = 1;

    while (run) {
        tmp = strstr(tmp + 1, word);
        if (tmp == NULL)
            run = 0;
        if (tmp != NULL)
            words++;
    }
    return words + 1;
}

char **str_to_arr_word(char *str, char *word)
{
    char **arr = malloc(sizeof(char *) * (count_words(str, word) + 1));
    char *tmp = str;
    int start = 0;
    int end = 0;

    while (tmp != NULL) {
        tmp = strstr(tmp, word);
        if (tmp == NULL)
            continue;
        end = tmp - str - 1;
        char *jsp = copy_string_between(str, start, end);
        printf("%s %d %d %s\n", tmp, start, end, jsp);
        start = tmp - str;
        tmp++;
    }

}
