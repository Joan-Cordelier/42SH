/*
** EPITECH PROJECT, 2023
** B-PSU-200-TLS-2-1-minishell1-joan.cordelier
** File description:
** test_str_to_arr
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"

Test (str_to_arr, simple_string)
{
    char str[41] = "This is a unit test for a str to arr\n ad";
    char **arr = str_to_arr(str, " \n");

    cr_assert_str_eq(arr[0], "This");
    cr_assert_str_eq(arr[1], "is");
    cr_assert_str_eq(arr[2], "a");
    cr_assert_str_eq(arr[3], "unit");
    cr_assert_str_eq(arr[4], "test");
    cr_assert_str_eq(arr[5], "for");
    cr_assert_str_eq(arr[6], "a");
    cr_assert_str_eq(arr[7], "str");
    cr_assert_str_eq(arr[8], "to");
    cr_assert_str_eq(arr[9], "arr");
    cr_assert_str_eq(arr[10], "ad");
}

Test (str_to_arr, one_letter)
{
    char str[2] = "a";
    char **arr = str_to_arr(str, " ");

    cr_assert_str_eq(arr[0], "a");
}

Test (copy_string_between, wrong_start_and_end)
{
    cr_assert_eq(copy_string_between("Hello", 5, 2), NULL);
    cr_assert_eq(copy_string_between("Hello", 2, 22), NULL);
    cr_assert_eq(copy_string_between("Hello", 18, 30), NULL);
}

Test (copy_string_between, wrong_str)
{
    cr_assert_eq(copy_string_between("", 0, 0), NULL);
    cr_assert_eq(copy_string_between(NULL, 0, 0), NULL);
    cr_assert_eq(copy_string_between(NULL, 2, 5), NULL);
}