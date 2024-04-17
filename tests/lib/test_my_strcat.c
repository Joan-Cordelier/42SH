/*
** EPITECH PROJECT, 2023
** tets test
** File description:
** test
*/

#include <criterion/criterion.h>
#include "my.h"

Test (concat, concat_an_array_to_another)
{
    char *s1 = NULL;

    s1 = concat("Hello", " word");
    cr_assert_str_eq(s1, "Hello word");
    free(s1);
}
