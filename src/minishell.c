/*
** EPITECH PROJECT, 2024
** minishell
** File description:
** minishell
*/

#include "my.h"

void child_signaled(int child_return)
{
    int signal;

    if (!WIFSIGNALED(child_return))
        return;
    signal = WTERMSIG(child_return);
    my_putstr(strsignal(signal));
    my_count_putchar('\n');
}

static int get_return(int child_return, int builtins_return)
{
    if (builtins_return > 0) {
        return builtins_return;
    }
    if (WIFEXITED(child_return))
        return WEXITSTATUS(child_return);
    return child_return;
}

static void put_prompt(void)
{
    if (isatty(STDIN_FILENO))
        my_putstr("$> ");
}

static int check_input_valid(ssize_t char_read, int child_return, env_t *envir)
{
    if (char_read <= 0)
        exit(get_return(child_return, *(envir->builtins_return)));
    if (char_read == 1)
        return 0;
    return 1;
}

int main(int ac, __attribute__((unused)) char **av, char **env)
{
    char *input = NULL;
    ssize_t char_read = 0;
    int child_return = 0;
    int child_pid;
    env_t *envir = init_env(env);

    if (ac != 1)
        return 84;
    while (1) {
        put_prompt();
        reinit_alias(envir);
        char_read = get_input(&input, envir->history, envir->job);
        if (!check_input_valid(char_read, child_return, envir))
            continue;
        manage_input(input, envir, &child_pid, &child_return);
    }
    return get_return(child_return, *(envir->builtins_return));
}
