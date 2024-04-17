/*
** EPITECH PROJECT, 2024
** minishell2
** File description:
** is_empty
*/

int is_empty(char *str)
{
    int empty = 1;

    for (int i = 0; str[i] != 0; i++) {
        if (!(str[i] == ' ' || str[i] == '\t'))
            empty = 0;
    }
    return empty;
}
