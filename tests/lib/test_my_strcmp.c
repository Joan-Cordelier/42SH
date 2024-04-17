/*
** EPITECH PROJECT, 2023
** tets test
** File description:
** test
*/

#include <criterion/criterion.h>
#include "my.h"

Test (my_strcmp, return_strcmp_function)
{
    char *s1 = my_strdup("Hello");
    char *s2 = my_strdup("Hello");
    char *s3 = my_strdup("hello");
    char *s4 = my_strdup("HEllo");
    char *null1 = my_strdup("\0");

    cr_assert_eq(strcmp(s1, s2), my_strcmp(s1, s2));
    cr_assert_eq(strcmp(s1, s3), my_strcmp(s1, s3));
    cr_assert_eq(strcmp(s1, s4), my_strcmp(s1, s4));
    cr_assert_eq(strcmp(s1, null1), my_strcmp(s1, null1));
    cr_assert_eq(strcmp(null1, null1), my_strcmp(null1, null1));
    free(s1);
    free(s2);
    free(s3);
    free(s4);
    free(null1);
}


Test (my_strncmp, return_strncmp_function)
{
    char *s1 = my_strdup("Hello");
    char *s2 = my_strdup("Hello");
    char *s3 = my_strdup("hello");
    char *s4 = my_strdup("HEllo");
    char *null1 = my_strdup("\0");
    int n = 4;

    cr_assert_eq(strncmp(s1, s2, n), my_strncmp(s1, s2, n));
    cr_assert_eq(strncmp(s1, s2, -n), my_strncmp(s1, s2, -n));
    cr_assert_eq(strncmp(s1, s3, n), my_strncmp(s1, s3, n));
    cr_assert_eq(strncmp(s1, s4, n), my_strncmp(s1, s4, n));
    cr_assert_eq(strncmp(null1, null1, n), my_strncmp(null1, null1, n));
    cr_assert_eq(strncmp(null1, null1, -n), my_strncmp(null1, null1, -n));
    free(s1);
    free(s2);
    free(s3);
    free(s4);
    free(null1);
}
