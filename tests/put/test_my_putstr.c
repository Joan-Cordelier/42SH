/*
** EPITECH PROJECT, 2023
** B-PSU-200-TLS-2-1-minishell1-joan.cordelier
** File description:
** test_my_putstr.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"

static void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test (my_putstr, simple_str, .init = redirect_all_std)
{
    char *str = "Hello word";

    my_putstr(str);
    cr_assert_stdout_eq_str("Hello word");
}
