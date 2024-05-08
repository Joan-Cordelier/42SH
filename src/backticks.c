/*
** EPITECH PROJECT, 2024
** backticks
** File description:
** backticks
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include "my.h"

void child_process(int pipefd[], char **args, env_t *envir)
{
    char **paths = NULL;

    close(pipefd[0]);
    dup2(pipefd[1], STDOUT_FILENO);
    close(pipefd[1]);
    fprintf(stderr, "Executing command: %s\n", args[0]);
    paths = get_paths(envir->env);
    my_printarray(paths);
    try_exec_path(args, envir, paths);
    fprintf(stderr, "Error: Failed to execute command.\n");
}

//Lit et affiche la sortie du processus enfant.
static void parent_process(int pipefd[], char *output)
{
    close(pipefd[1]);
    ssize_t bytes_read = read(pipefd[0], output, MAX_OUTPUT_SIZE - 1);
    if (bytes_read == -1) {
        return;
    } else {
        output[bytes_read] = '\0';
    }
    close(pipefd[0]);
    wait(NULL);
    printf("Output: %s\n", output);
}
//Crée un processus enfant pour exécuter une commande et récupère sa sortie.
char *my_popen(char **args, env_t *envir)
{
    char *output = malloc(sizeof(char) * MAX_OUTPUT_SIZE);
    int pipefd[2];
    pid_t pid;

    if (output == NULL)
        return NULL;
    if (pipe(pipefd) == -1) {
        fprintf(stderr, "Error: Failed to create pipe.\n");
        return NULL;
    }
    pid = fork();
    if (pid == -1) {
        fprintf(stderr, "Error: Failed to fork.\n");
        return NULL;
    }
    if (pid == 0)
        child_process(pipefd, args, envir);
    else
        parent_process(pipefd, output);
    return output;
}

void backtick_positions(int *start, int *end, int i)
{
    if (*start == -1) {
        *start = i;
    } else if (*end == -1) {
        *end = i;
    }
}

void find_backticks(const char *command, int *start, int *end)
{
    int i = 0;

    *start = -1;
    *end = -1;
    while (command[i] != '\0') {
        if (command[i] == '`') {
            backtick_positions(start, end, i);
        }
        i++;
    }
}

//Récupère le contenu entre les backticks l'exécute et le remplace
int replace_backticks(char *command, env_t *envir)
{
    int start = -1;
    int end = -1;
    char *cmd = NULL;
    char *output = NULL;

    find_backticks(command, &start, &end);
    if (start == -1 || end == -1)
        fprintf(stderr, "Unmatched '`'.\n");
    cmd = malloc(sizeof(char) * (end - start + 1));
    if (cmd == NULL) {
        fprintf(stderr, "Failed allocate memory\n");
    }
    strncpy(cmd, command + start + 1, end - start - 1);
    cmd[end - start - 1] = '\0';
    output = my_popen(&cmd, envir);
    if (output == NULL) {
        fprintf(stderr, "Failed to execute command.\n");
    }
    printf("Output: %s\n", output);
    free(output);
    free(cmd);
    return 0;
}
