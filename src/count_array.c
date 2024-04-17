/*
** EPITECH PROJECT, 2024
** countarray
** File description:
** countarray
*/

int my_arraylen(char **str)
{
    int i = 0;

    while (*str) {
        i++;
        str++;
    }
    return i;
}
