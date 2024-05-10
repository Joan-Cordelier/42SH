/*
** EPITECH PROJECT, 2024
** execute
** File description:
** execute
*/

#include "my.h"

static void var_testing(var_t *node, char **args, int i, env_t *envir)
{
    var_t *var = node;

    while (var != NULL && args[i][0] == '$') {
        if (strcmp(var->str, args[i] + 1) == 0) {
            tr_args_with_var(&args, var);
            var = envir->var;
        } else
            var = var->next;
    }
}

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

void try_exec_path(char **args, env_t *envir, char **paths)
{
    alias_t *alias = envir->alias;
    var_t *var = envir->var;

    while (alias != NULL && args[0] != NULL) {
        if (strcmp(alias->str, args[0]) == 0 && alias->used == 0) {
            tr_args_with_alias(&args, alias);
            alias->used = 1;
            alias = envir->alias;
        } else
            alias = alias->next;
    }
    for (int i = 0; args[i] != NULL; i++)
        var_testing(var, args, i, envir);
    if (args[0] == NULL)
        return;
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

void handle_matching_files(const char *cmd, const char *pattern,
    env_t *envir, char **paths)
{
    char **matching_files = find_matching(cmd, pattern, envir, paths);

    if (matching_files == NULL) {
        printf("%s: cannot access '%s': No such file or directory\n",
                cmd, pattern);
        return;
    }
}

void execute(char **args, char **env, env_t *envir)
{
    char **paths = get_paths(env);
    const char *pattern = args[1];
    const char *cmd = args[0];
    DIR *dir = opendir(".");
    bool is_pattern = pattern != NULL && contains_pattern(pattern, "*?[]");

    if (dir == NULL)
        return;
    if (is_pattern) {
        handle_matching_files(cmd, pattern, envir, paths);
        return;
    }
    if (run_builtins_command(args, envir, envir->builtins_return))
        return;
    if (exec_local(args, envir))
        return;
    try_exec_path(args, envir, paths);
}
