/*
** EPITECH PROJECT, 2023
** 42SH
** File description:
** manage_char.c
*/

#include "my.h"

int my_getchar(void)
{
    int c = 0;
    static struct termios old;
    static struct termios new;

    tcgetattr(STDIN_FILENO, &old);
    new = old;
    new.c_lflag &= ~(ICANON | ECHO | ISIG);
    tcsetattr(STDIN_FILENO, TCSANOW, &new);
    c = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &old);
    return c;
}

int manage_char(void)
{
    int c = 0;
    int c1 = 0;
    int c2 = 0;

    c = my_getchar();
    if (c == 27) {
        c1 = my_getchar();
        c2 = my_getchar();
    }
    if (c1 == 91)
        return c2 - 69;
    return c;
}
