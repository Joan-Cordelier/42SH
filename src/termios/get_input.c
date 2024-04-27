/*
** EPITECH PROJECT, 2023
** 42SH
** File description:
** manage_input.c
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

char *manage_current_line(char c, char *current_input, size_t *len)
{
    if (c == 127) {
        current_input[(*len) - 1] = '\0';
        if ((*len) >= 1)
            (*len)--;
    }
    else {
        if (strlen(current_input) < *len) {
            realloc(current_input, *len);
        }
        current_input = strcat(current_input, (char *)&c);
        (*len) = strlen(current_input);
    }
    //printf("%s\n", current_input);
    return current_input;
}

char *recreate_getline(void)
{
    int c = 0;
    char *input = NULL;
    size_t len = 0;

    input = malloc(sizeof(char));
    input[0] = '\0';
    while (1) {
        c = manage_char();
        //printf("%d\n", c);
        if (c == 4 || c == 3)
            exit(0);
        if (c > 0)
            input = manage_current_line(c, input, &len);
        printf("\r                                        ");
        printf("                                        \r");
        printf("$> %s", input);
        if (c == 10)
            break;
    }
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
