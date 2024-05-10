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
    paths = get_paths(envir->env);
    try_exec_path(args, envir, paths);
    fprintf(stderr, "Error: Failed to execute command.\n");
}

static void parent_process(int pipefd[], char *output)
{
    ssize_t bytes_read = read(pipefd[0], output, MAX_OUTPUT_SIZE - 1);

    close(pipefd[1]);
    if (bytes_read == -1) {
        return;
    } else {
        output[bytes_read] = '\0';
    }
    close(pipefd[0]);
    wait(NULL);
}

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

static void backtick_positions(int *start, int *end, int i)
{
    if (*start == -1) {
        *start = i;
    } else if (*end == -1) {
        *end = i;
    }
}

static void find_backticks(const char *command, int *start, int *end)
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

char **extract_command_between_backticks(char *command, int start, int end)
{
    char **cmd = malloc(sizeof(char *) * 2);

    if (cmd == NULL) {
        fprintf(stderr, "Failed to allocate memory.\n");
        return NULL;
    }
    cmd[0] = malloc(sizeof(char) * (end - start));
    if (cmd[0] == NULL) {
        fprintf(stderr, "Failed to allocate memory.\n");
        free(cmd);
        return NULL;
    }
    strncpy(cmd[0], command + start + 1, end - start - 1);
    cmd[0][end - start - 1] = '\0';
    cmd[1] = NULL;
    return cmd;
}

char *execute_command(char **cmd, env_t *envir)
{
    char *output = my_popen(cmd, envir);

    if (output == NULL) {
        fprintf(stderr, "Failed to execute command.\n");
        free(cmd[0]);
        free(cmd);
        return NULL;
    }
    return output;
}

int replace_backticks(char *command, env_t *envir)
{
    int start = -1;
    int end = -1;
    char **cmd = NULL;
    char *output = NULL;

    find_backticks(command, &start, &end);
    if ((start != -1 && end == -1) || (start == -1 && end != -1))
        fprintf(stderr, "Unmatched '`'.\n");
    if (start == -1 || end == -1)
        return 0;
    cmd = extract_command_between_backticks(command, start, end);
    if (cmd == NULL)
        return 1;
    output = execute_command(cmd, envir);
    printf("Output: %s\n", output);
    free(output);
    free(cmd[0]);
    free(cmd);
    return 0;
}
