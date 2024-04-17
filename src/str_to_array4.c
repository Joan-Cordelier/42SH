/*
** EPITECH PROJECT, 2023
** my_str_to_word_array
** File description:
** The function returns an array in which each cell contains the address of
** a string (representing a word).
*/

#include "my.h"

static int test_char_spe2(const char *str, int i)
{
    if (i == 0)
        return 1;
    if (str[i - 1] == ';' || str[i - 1] == '|')
        return 0;
    return 1;
}

static int test_char_spe(const char *str, int i)
{
    if (i == 0)
        return 1;
    if (str[i] == '|' && str[i - 1] == '|')
        return 1;
    return 0;
}

int test_alphanumeric(char c)
{
    if (c == '\n' || c == 0)
        return 1;
    if (c == ';' || c == '|')
        return 2;
    return 0;
}

char *my_cpy_in_str(char const *str, int i, int len, char *dest)
{
    int j = 0;

    while (j < len) {
        dest[j] = str[i - len + j];
        j++;
    }
    dest[j] = 0;
    return dest;
}

static int test_alpha_before(char const *str, int i)
{
    if (i == 0)
        return 0;
    if (test_alphanumeric(str[i - 1]) != 1)
        return 1;
    return 0;
}

int my_alloc_tab(char const *str)
{
    int j = 0;
    int i = 0;

    while (str[i] != 0) {
        while ((test_alphanumeric(str[i]) == 0 && test_char_spe2(str, i)) ||
            (test_alphanumeric(str[i]) == 2 && test_char_spe(str, i))) {
            i++;
        }
        if (test_alpha_before(str, i)) {
            j++;
        }
        if (str[i] != 0)
            i++;
    }
    return (j + 1);
}

int test_end_str(char const *str, int i, int *len)
{
    *len = 0;
    if (test_alphanumeric(str[i]) == 2 ||
        (test_alphanumeric(str[i]) == 0 && test_char_spe2(str, i) == 0))
        *len += 1;
    if (str[i] != 0)
        i++;
    return i;
}

char **str_to_arr_pipes(char const *str)
{
    int i = 0;
    int j = 0;
    char **tab = malloc((my_alloc_tab(str)) * sizeof(char *));
    int len = 0;

    while (str[i] != 0) {
        while ((test_alphanumeric(str[i]) == 0 && test_char_spe2(str, i)) ||
            (test_alphanumeric(str[i]) == 2 && test_char_spe(str, i))) {
            len++;
            i++;
        }
        if (test_alpha_before(str, i)) {
            tab[j] = malloc((len + 1) * sizeof(char));
            my_cpy_in_str(str, i, len, tab[j]);
            j++;
        }
        i = test_end_str(str, i, &len);
    }
    tab[j] = NULL;
    return tab;
}
