/*
** EPITECH PROJECT, 2024
** 42SH
** File description:
** which
*/

#include "my.h"
#include "lib.h"
#include <dirent.h>

int is_dir(const char *pathname)
{
    DIR *dir = opendir(pathname);

    if (dir != NULL) {
        closedir(dir);
        return 1;
    }
    return 0;
}

int command_stat_check(const char *pathname, int *err)
{
    struct stat path_stat;

    if (is_dir(pathname)) {
        *err = -2;
        return 0;
    }
    if (stat(pathname, &path_stat) == -1) {
        if (errno == EACCES) {
            *err = -2;
            return 0;
        }
        if (*err != -2)
            *err = -1;
        return 0;
    }
    return S_ISREG(path_stat.st_mode) && (path_stat.st_mode & S_IXUSR
    || path_stat.st_mode & S_IXGRP || path_stat.st_mode & S_IXOTH);
}

int check_command_with_path(char *path, char *command, int *err)
{
    path = concat(path, "/");
    path = concat(path, command);
    if (command_stat_check(path, err)) {
        free(path);
        return 1;
    }
    free(path);
    return 0;
}

static void which_display(char *path, char *command)
{
    my_putstr(path);
    if (command[my_strlen(command) - 1] != '/') {
        my_putstr("/");
    }
    my_printf("%s\n", command);
}

int disp_which_where_alias(char *command, env_t *env)
{
    for (alias_t *tmp = env->alias; tmp; tmp = tmp->next) {
        if (streq(tmp->str, command)) {
            my_printf("%s is aliased to %s\n", tmp->str, tmp->alias);
            return 1;
        }
    }
    return 0;
}

static void print_command_path(char **paths, char *command,
    int *return_value, int exist)
{
    int err = 0;

    for (int i = 0; paths[i]; i++) {
        if (check_command_with_path(paths[i], command, &err)) {
            exist = 1;
            which_display(paths[i], command);
            continue;
        }
    }
    if (command_stat_check(command, &err)) {
        my_printf("%s\n", command);
        exist = 1;
    }
    if (exist == 0) {
        my_printf("%s: Command not found\n", command);
        *return_value = 1;
    }
}

static void do_which(char **args, env_t *env, int *return_value, char **paths)
{
    if (my_arraylen(args) == 1) {
        my_printf("which: Too few arguments.\n");
        *return_value = 1;
        return;
    }
    for (int i = 1; args[i]; i++) {
        if (disp_which_where_alias(args[i], env))
            continue;
        print_command_path(paths, args[i], return_value, 0);
    }
}

static void do_where(char **args, env_t *env, int *return_value, char **paths)
{
    if (my_arraylen(args) == 1) {
        my_printf("where: Too few arguments.\n");
        *return_value = 1;
        return;
    }
    for (int i = 1; args[i]; i++) {
        print_command_path(paths, args[i], return_value,
        disp_which_where_alias(args[i], env));
    }
}

int which_where_command(char **args, env_t *env, int *return_value)
{
    char **paths = get_paths(env->env);

    if (streq(args[0], "which")) {
        do_which(args, env, return_value, paths);
        free(paths);
        return 1;
    }
    if (streq(args[0], "where")) {
        do_where(args, env, return_value, paths);
        free(paths);
        return 1;
    }
    return 0;
}
