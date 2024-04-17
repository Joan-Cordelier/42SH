/*
** EPITECH PROJECT, 2023
** tets test
** File description:
** test
*/

#include <criterion/criterion.h>
#include "my.h"

Test (my_strdup, alloc_a_string_and_fill_it_with_a_string)
{
    char *s1 = my_strdup("Hello word");

    cr_assert_str_eq(s1, "Hello word");
    free(s1);
}
