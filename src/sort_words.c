/*
** EPITECH PROJECT, 2024
** sort_words
** File description:
** sort word of a string
*/

#include "my.h"

static int is_separator(char c)
{
    if (c == ' ' || c == '\t')
        return 1;
    if (c == '\n')
        return 1;
    return 0;
}

static int count_word(char *str)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (is_separator(str[i]) && !is_separator(str[i + 1]))
            count++;
    }
    return count;
}

static char **malloc_words(char *str)
{
    int word_count = count_word(str);
    char **words = malloc(sizeof(char *) * (word_count + 1));

    return words;
}

char *get_word(char *str, int word_size, int i)
{
    char *result = malloc(sizeof(char) * word_size);

    for (int j = 0; j < word_size - 1; j++) {
        if (str[i - word_size + j + 1] == ' ' ||
            str[i - word_size + j + 1] == '\t') {
            continue;
        }
        result[j] = str[i - word_size + j + 1];
    }
    result[word_size] = '\0';
    return result;
}

char **string_to_word(char *str)
{
    char **words = malloc_words(str);
    int current_size = 0;
    int j = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        current_size++;
        if (is_separator(str[i]) && current_size > 1) {
            words[j] = get_word(str, current_size, i);
            j++;
            current_size = 0;
        }
        if (str[i + 1] == '\0') {
            current_size++;
            words[j] = get_word(str, current_size, i + 1);
        }
        if (is_separator(str[i]))
            current_size = 0;
    }
    words[my_arraylen(words) - 1] = NULL;
    return words;
}
