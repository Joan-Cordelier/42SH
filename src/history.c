/*
** EPITECH PROJECT, 2024
** history.c
** File description:
** history functions
*/

#include "my.h"

static int get_flags_history(char *str, int *flag)
{
    if (str[0] == 0) {
        printf("history: - : enter a valid flag");
        return 1;
    }
    for (int i = 0; str[i] != 0; i++) {
        switch (str[i]) {
            case 'c':
                *flag = *flag | 0x0001;
                break;
            default:
                printf("history: -%s : enter a valid flag\n", str);
                return 1;
        }
    }
    return 0;
}

static int add_arg_history(char *args, int *arg)
{
    if (*arg != -1) {
        printf("history: too many arguments\n");
        return 1;
    }
    for (int i = 0; args[i] != 0; i++) {
        if (args[i] > '9' || args[i] < '0') {
            printf("history: %s: numeric argument required\n", args);
            return 1;
        }
    }
    *arg = atoi(args);
    return 0;
}

static void exec_history(int flag, env_t *env, int arg)
{
    if ((flag & 0x0001) == 1)
        free_history(&(env->history));
    else
        display_history(env->history, arg);
}

int history_command(char **args, env_t *env, int *return_value)
{
    int flag = 0;
    int arg = -1;
    int ret = 0;

    if (strcmp("history", args[0]))
        return 0;
    for (int i = 1; args[i] != NULL; i++) {
        if (args[i][0] == '-')
            ret += get_flags_history(args[i] + 1, &flag);
        else
            ret += add_arg_history(args[i], &arg);
    }
    if (ret != 0) {
        *return_value = 1;
        return 1;
    }
    exec_history(flag, env, arg);
    *return_value = 0;
    return 1;
}

void free_history(history_t **history)
{
    history_t *next = NULL;

    while (*history != NULL) {
        next = (*history)->next;
        free((*history)->str);
        free(*history);
        *history = next;
    }
}

void display_history(history_t *history, int arg)
{
    int spaces;
    int i = 0;

    for (; history->next != NULL; i++)
        history = history->next;
    for (; history != NULL && (arg <= i && arg != -1); i--)
        history = history->prev;
    while (history != NULL) {
        spaces = 4;
        for (int j = 10; history->i >= j; j = j * 10)
            spaces -= 1;
        for (; spaces > 0; spaces--)
            printf(" ");
        printf("%d  %s", history->i, history->str);
        history = history->prev;
    }
}

void add_history(char *str, history_t **history)
{
    history_t *new = malloc(sizeof(history_t));

    if (*history == NULL)
        new->i = 1;
    else
        new->i = (*history)->i + 1;
    new->prev = NULL;
    new->str = my_strdup(str);
    new->next = *history;
    if (new->next != NULL)
        new->next->prev = new;
    *history = new;
}
