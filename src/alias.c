/*
** EPITECH PROJECT, 2024
** alias.c
** File description:
** aliases functions
*/

#include "my.h"

static void incr_for_alias(int *b, int len_word, int a, char **new)
{
    *b += 1;
    if (len_word <= 0)
        new[a][*b] = 0;
}

static int get_len_word_alias(char *str, int i)
{
    int j = 0;

    while (str[j + i] != ' ' && str[j + i] != 0 && str[j + i] != 39 &&
        str[j + i] != '\t' && str[j + i] != '\n')
        j++;
    return j;
}

static int tr_args_with_alias2(alias_t *alias, char **new)
{
    int a = -1;
    int b = 0;
    int len_word = 0;

    for (int i = 0; alias->alias[i] != 0; i++) {
        for (; len_word <= 0 && (alias->alias[i] == ' ' ||
            alias->alias[i] == 39) && alias->alias[i] != 0; i++);
        if (alias->alias[i] == 0)
            break;
        if (len_word <= 0) {
            b = 0;
            a++;
            len_word = get_len_word_alias(alias->alias, i);
            new[a] = malloc(sizeof(char *) * (len_word + 1));
        }
        new[a][b] = alias->alias[i];
        len_word--;
        incr_for_alias(&b, len_word, a, new);
    }
    return a + 1;
}

void tr_args_with_alias(char ***args, alias_t *alias)
{
    int a = 1;
    int j = 1;
    char **new;

    for (int i = 1; alias->alias[i] != 0; i++) {
        if (alias->alias[i - 1] == ' ' && alias->alias[i] != ' ')
            a++;
    }
    for (int i = 0; (*args)[i] != NULL; i++)
        a++;
    new = malloc(sizeof(char *) * a);
    free((*args)[0]);
    a = tr_args_with_alias2(alias, new);
    for (; (*args)[j] != NULL; j++) {
        new[a] = (*args)[j];
        a++;
    }
    new[a] = (*args)[j];
    free(*args);
    *args = new;
}

int add_alias(char *str, alias_t **alias)
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
    return 0;
}

static int display_alias(char *arg, alias_t **alias)
{
    alias_t *node = *alias;
    int i;

    if (arg != NULL) {
        for (i = 0; arg[i] != 0 && arg[i] != '='; i++);
        if (arg[i] == '=' && i != 0)
            return add_alias(arg, alias);
    }
    if (arg == NULL) {
        for (; node != NULL; node = node->next)
            printf("alias %s=\'%s\'\n", node->str, node->alias);
    } else {
        for (; node != NULL && strcmp(node->str, arg) != 0; node = node->next);
        if (node == NULL) {
            printf("alias : %s : not found\n", arg);
            return 1;
        } else
            printf("alias: %s=\'%s\'\n", node->str, node->alias);
    }
    return 0;
}

int alias_command(char **args, env_t *env, int *return_value)
{
    if (strcmp("alias", args[0]))
        return 0;
    *return_value = 0;
    if (args[1] == NULL) {
        display_alias(NULL, &(env->alias));
        return 1;
    }
    for (int i = 1; args[i] != NULL; i++) {
        *return_value += display_alias(args[i], &(env->alias));
    }
    return 1;
}

void reinit_alias(env_t *env)
{
    for (alias_t *alias = env->alias; alias != NULL; alias = alias->next)
        alias->used = 0;
}

alias_t *init_alias(void)
{
    alias_t *new = NULL;

    add_alias("grep=grep --color=auto", &new);
    add_alias("ll=ls -l --color=auto", &new);
    add_alias("ls=ls --color=auto", &new);
    return new;
}
