/*
** EPITECH PROJECT, 2024
** str_to_int.c
** File description:
** function that return int
*/

int str_to_int(char *str)
{
    int nb = 0;

    for (int i = 0; str[i] != 0; i++) {
        nb = nb * 10 + str[i] - '0';
    }
    return nb;
}
