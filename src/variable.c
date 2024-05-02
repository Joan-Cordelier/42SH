/*
** EPITECH PROJECT, 2024
** alias.c
** File description:
** aliases functions
*/

#include "my.h"

static void incr_for_var(int *b, int len_word, int a, char **new)
{
    *b += 1;
    if (len_word <= 0)
        new[a][*b] = 0;
}

static int get_len_word_var(char *str, int i)
{
    int j = 0;

    while (str[j + i] != ' ' && str[j + i] != 0 && str[j + i] != 39 &&
        str[j + i] != '\t' && str[j + i] != '\n')
        j++;
    return j;
}

static int tr_args_with_var2(var_t *var, char **new)
{
    int a = -1;
    int b = 0;
    int len_word = 0;

    for (int i = 0; var->alias[i] != 0; i++) {
        for (; len_word <= 0 && (var->alias[i] == ' ' ||
            var->alias[i] == 39) && var->alias[i] != 0; i++);
        if (var->alias[i] == 0)
            break;
        if (len_word <= 0) {
            b = 0;
            a++;
            len_word = get_len_word_var(var->alias, i);
            new[a] = malloc(sizeof(char *) * (len_word + 1));
        }
        new[a][b] = var->alias[i];
        len_word--;
        incr_for_var(&b, len_word, a, new);
    }
    return a + 1;
}

void tr_args_with_var(char ***args, var_t *var)
{
    int a = 1;
    int j = 1;
    char **new;

    for (int i = 1; var->alias[i] != 0; i++) {
        if (var->alias[i - 1] == ' ' && var->alias[i] != ' ')
            a++;
    }
    for (int i = 0; (*args)[i] != NULL; i++)
        a++;
    new = malloc(sizeof(char *) * a);
    free((*args)[0]);
    a = tr_args_with_var2(var, new);
    for (; (*args)[j] != NULL; j++) {
        new[a] = (*args)[j];
        a++;
    }
    new[a] = (*args)[j];
    free(*args);
    *args = new;
}

int create_var(char *str, var_t **var)
{
    var_t *new = malloc(sizeof(var_t));
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
    new->next = *var;
    if (*var != NULL)
        (*var)->prev = new;
    *var = new;
    return 0;
}

static int handle_var(char *arg, var_t **var)
{
    int i;

    for (i = 0; arg[i] != 0 && arg[i] != '='; i++);
    if (arg[i] == '=' && i != 0)
        return add_var(arg, var);
    return 0;
}

int var_command(char **args, env_t *env, int *return_value)
{
    int i;

    if (args[0] == NULL)
        return 0;
    for (i = 0; args[0][i] != 0 && args[0][i] != '='; i++);
    if (args[0][i] == 0)
        return 0;
    *return_value = 0;
    for (int i = 0; args[i] != NULL; i++)
        *return_value += handle_var(args[i], &(env->var));
    *return_value = *return_value > 1 ? 1 : *return_value;
    return 1;
}
