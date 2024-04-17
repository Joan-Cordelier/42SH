/*
** EPITECH PROJECT, 2023
** tets test
** File description:
** test
*/

#include <criterion/criterion.h>
#include "my.h"

Test (str_flags_manager, simple_test)
{
    cr_assert_eq(str_flags_manager("%s", "hello word"), 10);
}
