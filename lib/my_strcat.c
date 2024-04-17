/*
** EPITECH PROJECT, 2023
** my_strcat
** File description:
** task02
*/

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int dest_len = my_strlen(dest);
    int src_len = my_strlen(src);
    int i = 0;

    while (i < src_len){
        dest[i + dest_len] = src[i];
        i++;
    }
    dest[i + dest_len] = '\0';
    return dest;
}

char *concat(const char *s1, const char *s2)
{
    char *result = malloc(my_strlen(s1) + my_strlen(s2) + 1);

    my_strcpy(result, s1);
    my_strcat(result, s2);
    return result;
}
