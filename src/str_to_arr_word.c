/*
** EPITECH PROJECT, 2024
** 42SH
** File description:
** str_to_arr_word
*/

#include "my.h"

static int is_separator(char *str, char *word, int i)
{
    for (int j = 0; str[i + j] != 0 && word[j] != 0; j++) {
        if (str[i + j] != word[j])
            return 0;
    }
    return 1;
}

static int count_words(char *str, char *word, char *word2)
{
    int words = 0;
    int last = 0;

    for (int i = 0; str[i] != 0; i++) {
        if (is_separator(str, word, i) || is_separator(str, word2, i)) {
            words = (i > 0) ? words + 1 : words;
            last = i;
            words++;
            i++;
        }
    }
    if (last < my_strlen(str) - my_strlen(word) - 1) {
        words++;
    }
    return words + 1;
}

char **str_to_arr_word(char *str, char *word, char *word2)
{
    char **arr = malloc(sizeof(char *) * (count_words(str, word, word2) + 1));
    int start = 0;
    int curr = 0;

    for (int i = 0; str[i] != 0; i++) {
        if (is_separator(str, word, i) || is_separator(str, word2, i)) {
            arr[curr] = copy_string_between(str, start, i - 1);
            curr = (arr[curr] == NULL) ? curr : curr + 1;
            arr[curr] = copy_string_between(str, i,
            i + my_strlen(word- 1));
            start = i + 2;
            curr += 1;
        }
    }
    arr[curr] = copy_string_between(str, start, my_strlen(str) - 1);
    arr[curr + 1] = NULL;
    return arr;
}
