/*
** EPITECH PROJECT, 2023
** B-PSU-200-TLS-2-1-minishell1-joan.cordelier
** File description:
** test_my_strlen.c
*/

#include <criterion/criterion.h>
#include "my.h"

Test (my_tablen, return_len_of_an_array)
{
    char **tab = NULL;

    tab = str_to_arr("Hello word    I am jojo", " \t");
    cr_assert_eq(my_tablen(tab), 5);
}

Test (my_strlen, return_len_of_a_string)
{
    char *tab;
    char *str = NULL;

    tab = my_strdup("Hello word    I am jojo");
    cr_assert_eq(my_strlen(tab), 23);
    cr_assert_eq(my_strlen(str), 0);
    free(tab);
}
