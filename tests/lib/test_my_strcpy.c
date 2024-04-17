/*
** EPITECH PROJECT, 2023
** strn test
** File description:
** test
*/

#include <criterion/criterion.h>
#include "my.h"

Test (my_strcpy, copy_characters_in_empty_array_prealloc)
{
    char *dest = malloc(sizeof(char) * my_strlen("Helloworld"));

    dest = my_strcpy(dest, "Helloworld");
    cr_assert_str_eq(dest, "Helloworld");
    free(dest);
}
