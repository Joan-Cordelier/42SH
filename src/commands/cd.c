/*
** EPITECH PROJECT, 2024
** cd
** File description:
** cd
*/

#include "my.h"

static void detect_error(char *filepath)
{
    int is_dir = is_a_dir(filepath);

    if (is_dir == 0)
        print_error(concat(filepath, ": Not a directory.\n"));
    if (is_dir == - 1)
        print_error(concat(filepath, ": No such file or directory.\n"));
    return;
}

static int changedirprevious(char **args, env_t *envir,
    int *return_value)
{
    if (streq(args[1], "-")) {
        if (chdir(envir->previous) != 0) {
            *return_value = 1;
            detect_error(envir->previous);
        }
        return 1;
    }
    return 0;
}

static int changedirhome(char **args, char *home,
    int *return_value)
{
    if (args[1] == NULL || streq(args[1], "~")) {
        if (home == NULL) {
            *return_value = 1;
            print_error("No $home variable set.\n");
        }
        if (home != NULL) {
            chdir(home);
        }
        return 1;
    }
    return 0;
}

int changedir(char **args, char **env, env_t *envir, int *return_value)
{
    char *home = get_home(env);
    char buff[256];
    char *oldpath = my_strdup(getcwd(buff, 256));

    if (args[1] == NULL)
        return changedirhome(args, home, return_value);
    if (changedirprevious(args, envir, return_value) ||
            changedirhome(args, home, return_value)) {
        return 1;
    }
    if (chdir(args[1]) != 0) {
        *return_value = 1;
        detect_error(args[1]);
    }
    envir->previous = oldpath;
    changeenvdir(env);
    return 1;
}

int changeenvdir(char **env)
{
    char buff[256];
    char *path = getcwd(buff, 256);

    if (path == NULL)
        return 1;
    for (int i = 0; env[i] != NULL; i++) {
        if (streq(get_env_name(env[i]), "PWD")) {
            env[i] = concat("PWD=", path);
            break;
        }
    }
    return 1;
}
