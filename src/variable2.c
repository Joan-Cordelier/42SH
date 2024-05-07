/*
** EPITECH PROJECT, 2024
** alias2.c
** File description:
** alias functions
*/

#include "my.h"

static int change_var(var_t **node, char *str)
{
    char *new;

    new = strdup(str);
    free((*node)->alias);
    (*node)->alias = new;
    return 0;
}

int add_var(char *str, var_t **var)
{
    char *name;
    int i = 0;
    var_t *node = *var;
    int find = 0;

    for (; str[i] != '='; i++);
    name = malloc(sizeof(char) * (i + 1));
    for (int j = 0; j < i; j++)
        name[j] = str[j];
    name[i] = 0;
    while (node != NULL && find == 0) {
        if (strcmp(node->str, name) == 0)
            find = 1;
        else
            node = node->next;
    }
    find = find ? change_var(&node, str + i + 1) : create_var(str, var);
    free(name);
    return find;
}
