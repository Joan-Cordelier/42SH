/*
** EPITECH PROJECT, 2023
** shell.h
** File description:
** header for the shell project
*/

#ifndef SHELL_H
    #define SHELL_H

typedef struct history_s {
    int i;
    char *str;
    struct history_s *next;
    struct history_s *prev;
}history_t;

typedef struct alias_s {
    int used;
    char *str;
    char *alias;
    struct alias_s *next;
    struct alias_s *prev;
}alias_t;

typedef struct var_s {
    char *str;
    char *alias;
    struct var_s *next;
    struct var_s *prev;
}var_t;

typedef struct environment_s {
    struct var_s *var;
    struct alias_s *alias;
    struct history_s *history;
    char **env;
    char *previous;
    int *builtins_return;
    int child_pid;
}env_t;

typedef struct pipe_s {
    int pipefd[32000][2];
    int is_last;
    int is_first;
    int index;
    int righ_redirect;
    int left_redirect;
    int output;
    int input;
    int err;
}pipe_t;

char **string_to_word(char *str);
int my_arraylen(char **str);
int my_printarray(char **str);
char **str_to_arr(char *str, char *separator);
char **str_to_arr2(char *str, char *separator);
int streq(char *str, char *str2);
int check_exit(char **args);
char *copy_string_between(char *str, int start, int end);
char *get_env_name(char *env);
pipe_t *init_pipe(char **arr);
int is_pipe_valid(char *str);
int is_redirect_valid(char **arr);
void get_redirection(char **arr, pipe_t *pipe, int i);
int check_redirect_amount(char **arr);

env_t *init_env(char **env);

void print_error(char *msg);
char *get_home(char **env);
void execute(char **args, char **env, env_t *envir);
char **get_paths(char **env);

void my_strsignal(int signal);
int is_empty(char *str);

int is_a_dir(char *path);
void child_signaled(int child_return);
int manage_input(char *input, env_t *env, int *child_pid, int *child_return);

int input_manager(char *input, env_t *env, int *child_pid, pipe_t *pipe);

int redirect_error(char **arr);

int manage_redirect(char *input, env_t *env, int i, pipe_t *pipe);
int manage_pipe(char *input, env_t *env, int *child_pid, int *child_return);

int logical_manager(char *input, env_t *env, int *child_pid,
    int *child_return);
char **str_to_arr_word(char *str, char *word, char *word2);

/*      COMMAND     */
char **my_unsetenv(char **args, char ***env, int *return_value);
int print_env(char **env);
int run_builtins_command(char **args, env_t *env, int *return_value);
int changedir(char **args, char **env, env_t *envir, int *return_value);
int changeenvdir(char **env);
char **my_setenv(char **args, char ***env, int *return_value);
int which_where_command(char **args, env_t *env, int *return_value);



#endif
