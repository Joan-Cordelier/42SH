/*
** EPITECH PROJECT, 2023
** 42SH
** File description:
** job_control.c
*/

#include "my.h"

void add_job(pid_t pid, job_t **job)
{
    job_t *new = malloc(sizeof(job_t));

    new->pid = pid;
    new->prev = NULL;
    new->next = *job;
    if (*job != NULL)
        (*job)->prev = new;
    *job = new;
}

void display_all_pid(job_t *job)
{
    while (job != NULL) {
        printf("%d\n", job->pid);
        job = job->next;
    }
}

int job_control(job_t *job, int c)
{
    if (c == 4)
        exit(130);
    while (job != NULL) {
        if (job->pid != 0)
            kill(job->pid, SIGSTOP);
        job = job->next;
    }
    return 0;
}
