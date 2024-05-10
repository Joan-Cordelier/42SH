/*
** EPITECH PROJECT, 2024
** gobblings
** File description:
** gobblings
*/

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <fnmatch.h>
#include <string.h>
#include "my.h"

void free_matching_files(char **matching_files, int match_count)
{
    for (int i = 0; i < match_count; i++) {
        free(matching_files[i]);
    }
    free(matching_files);
}

bool matches_pattern(const char *pattern, struct dirent *entry,
    char **matching_files, int *match_count)
{
    if (fnmatch(pattern, entry->d_name, FNM_PATHNAME) == 0) {
        matching_files[*match_count] = strdup(entry->d_name);
        if (matching_files[*match_count] == NULL) {
            return false;
        }
        (*match_count)++;
        return true;
    }
    return false;
}

bool files_exist(const char *pattern, int *count, char **matching_files)
{
    DIR *dir = opendir(".");
    bool exists = false;
    struct dirent *entry;

    if (dir == NULL)
        return false;
    entry = readdir(dir);
    while (entry != NULL) {
        if (matches_pattern(pattern, entry, matching_files, count)) {
            exists = true;
        }
        entry = readdir(dir);
    }
    closedir(dir);
    return exists;
}

char *parse_command(const char *command)
{
    const char *start = NULL;
    const char *end = NULL;
    size_t length = 0;
    char *first_argument = NULL;

    while (*command && *command == ' ') {
        command++;
    }
    start = command;
    end = command;
    while (*end && *end != ' ') {
        end++;
    }
    length = end - start;
    first_argument = malloc(length + 1);
    if (first_argument != NULL) {
        strncpy(first_argument, start, length);
        first_argument[length] = '\0';
    }
    return first_argument;
}

char **find_matching(const char *command, const char *pattern,
    env_t *envir, char **paths)
{
    DIR *dir = opendir(".");
    char *first_argument = parse_command(command);
    char **matching_files = malloc(sizeof(char *) * 100);
    int match_count = 1;

    if (dir == NULL)
        return NULL;
    if (matching_files == NULL)
        return NULL;
    matching_files[0] = strdup(first_argument);
    free(first_argument);
    if (matching_files[0] == NULL)
        return NULL;
    if (!files_exist(pattern, &match_count, matching_files)) {
        return NULL;
    }
    try_exec_path(matching_files, envir, paths);
    free_matching_files(matching_files, match_count);
    matching_files[match_count] = NULL;
    return matching_files;
}
