/*
** EPITECH PROJECT, 2024
** my_strsignal
** File description:
** my_strsignal
*/

#include "my.h"

void str_signal_first(int signal)
{
    switch (signal) {
        case SIGHUP:
            print_error("Hangup");
            break;
        case SIGQUIT:
            print_error("Quit");
            break;
        case SIGILL:
            print_error("Illegal instruction");
            break;
        case SIGTRAP:
            print_error("Trace/breakpoint trap");
            break;
        case SIGABRT:
            print_error("Aborted");
            break;
        case SIGBUS:
            print_error("Bus error");
            break;
    }
}

void str_signal_second(int signal)
{
    switch (signal) {
        case SIGFPE:
            print_error("Floating exception");
            break;
        case SIGKILL:
            print_error("Killed");
            break;
        case SIGUSR1:
            print_error("User signal 1");
            break;
        case SIGSEGV:
            print_error("Segmentation fault");
            break;
        case SIGUSR2:
            print_error("User signal 2");
            break;
        case SIGPIPE:
            print_error("Broken pipe");
            break;
    }
}

void str_signal_third(int signal)
{
    switch (signal) {
        case SIGALRM:
            print_error("Alarm clock");
            break;
        case SIGTERM:
            print_error("Terminated");
            break;
        case SIGSTKFLT:
            print_error("Stack limit exceeded");
            break;
    }
}

void my_strsignal(int signal)
{
    str_signal_first(signal);
    str_signal_second(signal);
    str_signal_third(signal);
}
