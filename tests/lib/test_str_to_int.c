/*
** EPITECH PROJECT, 2024
** 42_SH
** File description:
** test_str_to_int
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"

Test (str_to_int, simple_test)
{
    cr_assert_eq(str_to_int("10"), 10);
}
