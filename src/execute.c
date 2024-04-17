/*
** EPITECH PROJECT, 2024
** execute
** File description:
** execute
*/

#include "my.h"

static void print_errno(int err, char **args)
{
    if (err == ENOEXEC) {
            print_error(concat(args[0],
                ": Exec format error. Wrong Architecture.\n"));
            return;
        }
        if (err == EACCES) {
            print_error(concat(args[0], ": Permission denied.\n"));
            return;
        }
}

static void try_exec_path(char **args, env_t *envir, char **paths)
{
    alias_t *alias = envir->alias;

    while (alias != NULL) {
        if (strcmp(alias->str, args[0]) == 0 && alias->used == 0) {
            tr_args_with_alias(&args, alias);
            alias->used = 1;
            alias = envir->alias;
        } else
            alias = alias->next;
    }
    if (paths != NULL) {
        for (int i = 0; paths[i] != NULL; i++)
            execve(concat(concat(paths[i], "/"), args[0]), args, envir->env);
    }
    print_error(concat(args[0], ": Command not found.\n"));
}

static int exec_local(char **args, env_t *envir)
{
    if (execve(args[0], args, envir->env) == - 1) {
        if (errno == ENOEXEC || errno == EACCES) {
            print_errno(errno, args);
            return 1;
        }
    }
    return 0;
}

void execute(char **args, char **env, env_t *envir)
{
    char **paths = get_paths(env);

    if (run_builtins_command(args, envir, envir->builtins_return))
        return;
    if (exec_local(args, envir))
        return;
    try_exec_path(args, envir, paths);
}
