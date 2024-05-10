/*
** EPITECH PROJECT, 2023
** 42SH
** File description:
** line_refreshing.c
*/

#include "my.h"

char *my_strcat_begining(char c, char *str)
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

void refrech_line(void)
{
    printf("\r");
    printf("\033[K");
    printf("\r$> ");
    printf("\033[C");
}

void reset_line(line_t *line)
{
    memset(line->left, '\0', 100000);
    memset(line->right, '\0', 100000);
    refrech_line();
}

char *rm_first_char(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        str[i] = str[i + 1];
    return str;
}

char *strsub_from_char(char *str, char c)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == c)
            str[i] = '\0';
    return str;
}
