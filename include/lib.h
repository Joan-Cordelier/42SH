/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** lib.h
*/

#ifndef LIB_H
    #define LIB_H
    #include <termios.h>
    #include <ncurses.h>
    #include <errno.h>
    #include <fcntl.h>
    #include <limits.h>
    #include <stdarg.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <string.h>
    #include <signal.h>
    #include <sys/stat.h>
    #include <sys/types.h>
    #include <sys/wait.h>
    #include <unistd.h>
    #include <termios.h>
    #include <time.h>

typedef enum arrow_e {
    UP_K = -4,
    DOWN_K = -3,
    RIGHT_K = -2,
    LEFT_K = -1
} arrow_t;

#endif /* LIB_H */
