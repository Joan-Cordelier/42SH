/*
** EPITECH PROJECT, 2023
** test
** File description:
** test
*/

#include <criterion/criterion.h>
#include "my.h"
#include <stdio.h>
#include <stdlib.h>

Test(my_printf, test_return_value_simple_str)
{
    cr_assert_eq(printf("hello"), my_printf("hello"));
}

Test(my_printf, test_return_value_int)
{
    cr_assert_eq(printf("hello %d", 5), my_printf("hello %d", 5));
    cr_assert_eq(printf("hello %d", -21), my_printf("hello %d", -21));
    cr_assert_eq(printf("hello %i", 0), my_printf("hello %i", 0));
}

Test(my_printf, test_return_value_char)
{
    cr_assert_eq(printf("hello %c", 'k'), my_printf("hello %c", 'k'));
}

Test(my_printf, test_return_value_float)
{
    cr_assert_eq(printf("%f", 0.25), my_printf("%f", 0.25));
    cr_assert_eq(printf("%.12f", 0.25475), my_printf("%.12f", 0.25475));
    cr_assert_eq(printf("%.8F", 0.15), my_printf("%.8F", 0.15));
}

Test(my_printf, test_return_value_e)
{
    cr_assert_eq(printf("%e", 0.0025), my_printf("%e", 0.0025));
    cr_assert_eq(printf("%E", 0.0025), my_printf("%E", 0.0025));
}

Test(my_printf, test_return_value_p)
{
    void *ptr = malloc(sizeof(void *));

    cr_assert_eq(printf("%p", ptr), my_printf("%p", ptr));
}

Test(my_printf, test_return_value_percent)
{
    cr_assert_eq(printf("%%"), my_printf("%%"));
}

Test(my_printf, test_return_value_string)
{
    cr_assert_eq(printf("hi %s", "hello"), my_printf("hi %s", "hello"));
}

Test(my_printf, test_return_value_octal)
{
    printf("printf : %d , my_printf : %d\n", printf("%o", -85), my_printf("o", -85));
    cr_assert_eq(printf("%o", 865), my_printf("%o", 865));
    cr_assert_eq(printf("%o", -85), my_printf("%o", -85));
}

Test(my_printf, test_return_value_hex)
{
    cr_assert_eq(printf("%x", 89547), my_printf("%x", 89547));
    cr_assert_eq(printf("%x", -9285), my_printf("%x", -9285));
    cr_assert_eq(printf("%X", 123), my_printf("%X", 123));
    cr_assert_eq(printf("%X", -596), my_printf("%X", -596));
}

Test(my_printf, test_return_value_zero)
{
    cr_assert_eq(printf("%09d", -12), my_printf("%09d", -12));
    cr_assert_eq(printf("%04i", 8954), my_printf("%04i", 8954));
    cr_assert_eq(printf("%07o", 120), my_printf("%07o", 120));
    cr_assert_eq(printf("%09x", -4), my_printf("%09x", -4));
    //cr_assert_eq(printf("%014f", 0.12658), my_printf("%014f", 0.12658));
}
