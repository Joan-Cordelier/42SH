/*
** EPITECH PROJECT, 2024
** alias2.c
** File description:
** alias functions
*/

#include "my.h"

void free_alias(alias_t **alias, alias_t *node)
{
    free(node->str);
    free(node->alias);
    if (node->next != NULL)
        node->next->prev = node->prev;
    if (node->prev != NULL)
        node->prev->next = node->next;
    else
        *alias = node->next;
    free(node);
}

int free_all_alias(alias_t **alias)
{
    alias_t *next;

    for (alias_t *node = *alias; node != NULL; node = next) {
        next = node->next;
        free(node->str);
        free(node->alias);
        free(node);
    }
    *alias = NULL;
    return 0;
}

static int change_alias(alias_t **node, char *str)
{
    char *new;

    new = strdup(str);
    free((*node)->alias);
    (*node)->alias = new;
    return 0;
}

int add_alias(char *str, alias_t **alias)
{
    char *name;
    int i = 0;
    alias_t *node = *alias;
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
    find = find ? change_alias(&node, str + i + 1) : create_alias(str, alias);
    free(name);
    return find;
}

alias_t *init_alias(void)
{
    alias_t *new = NULL;

    add_alias("grep=grep --color=auto", &new);
    add_alias("ll=ls -l --color=auto", &new);
    add_alias("ls=ls --color=auto", &new);
    return new;
}
