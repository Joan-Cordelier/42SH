/*
** EPITECH PROJECT, 2024
** alias.c
** File description:
** aliases functions
*/

#include "my.h"

void add_alias(char *str, alias_t **alias)
{
    alias_t *new = malloc(sizeof(alias_t));
    int i[2] = {0, 0};

    for (; str[i[0]] != '='; i[0] += 1);
    new->str = malloc(sizeof(char) * (i[0] + 1));
    for (int j = 0; j < i[0]; j++)
        new->str[j] = str[j];
    new->str[i[0]] = 0;
    i[1] = strlen(str) - i[0] - 1;
    new->alias = malloc(sizeof(char) * (i[1] + 1));
    for (int j = i[0] + 1; j < i[1] + i[0] + 1; j++)
        new->alias[j - i[0] - 1] = str[j];
    new->alias[i[1]] = 0;
    new->prev = NULL;
    new->next = *alias;
    if (*alias != NULL)
        (*alias)->prev = new;
    *alias = new;
}

void display_alias(char *arg, alias_t *alias)
{
    if (arg == NULL) {
        for (; alias != NULL; alias = alias->next) {
            printf("alias %s=%s\n", alias->str, alias->alias);
        }
    }
}

int alias_command(char **args, env_t *env, int *return_value)
{
    if (strcmp("alias", args[0]))
        return 0;
    display_alias(NULL, env->alias);
    *return_value = 0;
    return 1;
}

alias_t *init_alias(void)
{
    alias_t *new = NULL;

    add_alias("grep='grep --color=auto'", &new);
    add_alias("ll='ls -l --color=auto'", &new);
    add_alias("ls='ls --color=auto'", &new);
    return new;
}
