/*
** EPITECH PROJECT, 2023
** my_memset
** File description:
** do the same as memset
*/

char *my_memset(char *str, char c, int nb)
{
    for (int i = 0; i < nb; i++) {
        str[i] = c;
    }
    return str;
}
