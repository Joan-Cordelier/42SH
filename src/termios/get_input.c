/*
** EPITECH PROJECT, 2023
** 42SH
** File description:
** manage_input.c
*/

#include "my.h"

char *recreate_getline(void)
{
    int c = 0;
    char *input = NULL;
    static struct termios old;
    static struct termios new;

    input = malloc(sizeof(char) * 1);
    input[0] = '\0';
    tcgetattr(STDIN_FILENO, &old);
    new = old;
    new.c_cflag &= ~(ICANON | ECHONL);
    tcsetattr(STDIN_FILENO, TCSANOW, &new);
    while (c != '\n') {
        c = getchar();
        if (c != '\n')
            input = concat(input, (char *)&c);
    }
    tcsetattr(STDIN_FILENO, TCSANOW, &old);
    return input;
}

int get_input(char **input)
{
    size_t size = 0;

    if (!(isatty(STDIN_FILENO)))
        return (getline(input, &size, stdin));
    *input = recreate_getline();
    return 2;
}
