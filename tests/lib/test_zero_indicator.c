/*
** EPITECH PROJECT, 2023
** tets test
** File description:
** test
*/

#include <criterion/criterion.h>
#include "my.h"

Test (zero_indicator, simple_test)
{
    cr_assert_eq(zero_indicator('0', 10), 10);
}
