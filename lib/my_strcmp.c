/*
** EPITECH PROJECT, 2023
** my_strcmp.c
** File description:
** task06
*/

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    for (; s1[i] != '\0' && s2[i] != '\0'; i++) {
        if (s1[i] != s2[i]){
            return s1[i] - s2[i];
        }
    }
    return s1[i] - s2[i];
}

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    for (; s1[i] != '\0' && s2[i] != '\0' && i < n; i++) {
        if (s1[i] != s2[i]){
            return s1[i] - s2[i];
        }
    }
    return s1[i] - s2[i];
}
