/*
** EPITECH PROJECT, 2023
** test_my_printf
** File description:
** test for the my_printf function
*/


#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"
#include <stdio.h>

static void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(my_printf, simple_string, .init = redirect_all_std)
{
    my_printf("hello world");
    cr_assert_stdout_eq_str("hello world");
}

Test(my_printf, flag_d, .init = redirect_all_std)
{
    my_printf("%d", 4);
    cr_assert_stdout_eq_str("4");
}

Test(my_printf, flag_d_bigger_than_9, .init = redirect_all_std)
{
    my_printf("%d", 120);
    cr_assert_stdout_eq_str("120");
}

Test(my_printf, flag_d_negative, .init = redirect_all_std)
{
    my_printf("%d", -20);
    cr_assert_stdout_eq_str("-20");
}

Test(my_printf, flag_d_zero, .init = redirect_all_std)
{
    my_printf("%d", 0);
    cr_assert_stdout_eq_str("0");
}

Test(my_printf, flag_i_negative, .init = redirect_all_std)
{
    my_printf("%i", -20);
    cr_assert_stdout_eq_str("-20");
}

Test(my_printf, flag_i_zero, .init = redirect_all_std)
{
    my_printf("%i", 0);
    cr_assert_stdout_eq_str("0");
}

Test(my_printf, flag_i_more_than_9, .init = redirect_all_std)
{
    my_printf("%i", 9283);
    cr_assert_stdout_eq_str("9283");
}

Test(my_printf, flag_s, .init = redirect_all_std)
{
    my_printf("%s", "-lala");
    cr_assert_stdout_eq_str("-lala");
}

Test(my_printf, flag_s_one_char, .init = redirect_all_std)
{
    my_printf("%s", "l");
    cr_assert_stdout_eq_str("l");
}

Test(my_printf, flag_c, .init = redirect_all_std)
{
    my_printf("lala%c", 'i');
    cr_assert_stdout_eq_str("lalai");
}

Test(my_printf, flag_C, .init = redirect_all_std)
{
    my_printf("lala%C", 'i');
    cr_assert_stdout_eq_str("lalai");
}

Test(my_printf, flag_modulo, .init = redirect_all_std)
{
    my_printf("lala%%");
    cr_assert_stdout_eq_str("lala%");
}

Test(my_printf, nb_of_printed_char)
{
    int result1 = my_printf("lalala");
    int of_result1 = printf("lalala");
    int result2 = my_printf("%d", 5);
    int of_result2 = printf("%d", 5);

    cr_assert_eq(of_result1, result1);
    cr_assert_eq(of_result2, result2);
}

Test(my_printf, test_o, .init = redirect_all_std)
{
    char str[30];

    sprintf(str, "%o", 2023);
    my_printf("%o", 2023);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, test_o_lil, .init = redirect_all_std)
{
    char str[30];

    sprintf(str, "%o", 2);
    my_printf("%o", 2);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, test_o_neg, .init = redirect_all_std)
{
    char str[30];   

    sprintf(str, "%o", -45);
    my_printf("%o", -45);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, test_o_big_neg, .init = redirect_all_std)
{
    char str[30];   

    sprintf(str, "%o", -4547348);
    my_printf("%o", -4547348);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, test_o_zero, .init = redirect_all_std)
{
    my_printf("%o", 0);
    cr_assert_stdout_eq_str("0");
}

Test(my_printf, test_u_neg, .init = redirect_all_std)
{
    char str[11];

    sprintf(str, "%u", -33);
    my_printf("%u", -33);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, test_u_pos, .init = redirect_all_std)
{
    char str[11];

    sprintf(str, "%u", 33);
    my_printf("%u", 33);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, test_u_zero, .init = redirect_all_std)
{
    char str[11];

    sprintf(str, "%u", 0);
    my_printf("%u", 0);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, test_x_pos, .init = redirect_all_std)
{
    char str[4];

    sprintf(str, "%x", 743);
    my_printf("%x", 743);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, test_x_neg, .init = redirect_all_std)
{
    char str[20];

    sprintf(str, "%x", -45);
    my_printf("%x", -45);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, test_x_zero, .init = redirect_all_std)
{
    char str[20];

    sprintf(str, "%x", 0);
    my_printf("%x", 0);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, test_X, .init = redirect_all_std)
{
    char str[4];

    sprintf(str, "%X", 743);
    my_printf("%X", 743);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, test_X_pos, .init = redirect_all_std)
{
    char str[4];

    sprintf(str, "%X", 743);
    my_printf("%X", 743);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, test_X_neg, .init = redirect_all_std)
{
    char str[20];

    sprintf(str, "%X", -45);
    my_printf("%X", -45);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, test_X_zero, .init = redirect_all_std)
{
    char str[20];

    sprintf(str, "%X", 0);
    my_printf("%X", 0);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, test_f, .init = redirect_all_std)
{
    char str[10];

    sprintf(str, "%f", 42.1352);
    my_printf("%f", 42.1352);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, test_f_valuezero, .init = redirect_all_std)
{
    char str[10];

    sprintf(str, "%f", 0.0);
    my_printf("%f", 0.0);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, test_f_big_neg, .init = redirect_all_std)
{
    char str[14];

    sprintf(str, "%f", -12342.1352);
    my_printf("%f", -12342.1352);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, test_0f, .init = redirect_all_std)
{
    char str[10];

    sprintf(str, "%.0f", 42.1352);
    my_printf("%.0f", 42.1352);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, test_0f_neg, .init = redirect_all_std)
{
    char str[10];

    sprintf(str, "%.0f", -42.1352);
    my_printf("%.0f", -42.1352);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, test_0f_zero, .init = redirect_all_std)
{
    char str[10];
    double zero = 0;

    sprintf(str, "%.0f", zero);
    my_printf("%.0f", zero);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, test_12f, .init = redirect_all_std)
{
    char str[16];

    sprintf(str, "%.12f", 42.1352);
    my_printf("%.12f", 42.1352);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, test_12f_neg, .init = redirect_all_std)
{
    char str[17];

    sprintf(str, "%.12f", -42.1352);
    my_printf("%.12f", -42.1352);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, test_12f_zero, .init = redirect_all_std)
{
    char str[15];
    double zero = 0;

    sprintf(str, "%.12f", zero);
    my_printf("%.12f", zero);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, test_F, .init = redirect_all_std)
{
    char str[10];

    sprintf(str, "%F", 42.1352);
    my_printf("%F", 42.1352);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, test_0F, .init = redirect_all_std)
{
    char str[10];

    sprintf(str, "%.0F", 42.1352);
    my_printf("%.0F", 42.1352);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, test_12F, .init = redirect_all_std)
{
    char str[16];

    sprintf(str, "%.12F", 42.1352);
    my_printf("%.12F", 42.1352);
    cr_assert_stdout_eq_str(str);
}

/*Test(my_printf, test_12F_neg, .init = redirect_all_std)
{
    char str[15];

    sprintf(str, "%.12F", -123442.1352);
    my_printf("%.12F", -123442.1352);
    cr_assert_stdout_eq_str(str);
}*/

Test(my_printf, test_e_nb1, .init = redirect_all_std)
{
    char str[15];

    sprintf(str, "%e", 0.00246);
    my_printf("%e", 0.00246);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, test_e_nb2, .init = redirect_all_std)
{
    char str[20];

    sprintf(str, "%.11e", 0.00246);
    my_printf("%.11e", 0.00246);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, test_e_nb3, .init = redirect_all_std)
{
    char str[25];

    sprintf(str, "%.11e", 11.268);
    my_printf("%.11e", 11.268);
    cr_assert_stdout_eq_str(str);   
}

Test(my_printf, test_E_nb1, .init = redirect_all_std)
{
    char str[15];

    sprintf(str, "%E", 0.00246);
    my_printf("%E", 0.00246);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, test_E_nb2, .init = redirect_all_std)
{
    char str[20];

    sprintf(str, "%.11E", 0.00246);
    my_printf("%.11E", 0.00246);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, test_ptr, .init = redirect_all_std)
{
    char str[30];
    void *nb_ptr = malloc(sizeof(void *));

    sprintf(str, "%p", nb_ptr);
    my_printf("%p", nb_ptr);
    cr_assert_stdout_eq_str(str);
    free(nb_ptr);
}

Test(my_printf, test_ptr2, .init = redirect_all_std)
{
    char str[30];
    float *nb_ptr = malloc(sizeof(float *));

    sprintf(str, "%p", nb_ptr);
    my_printf("%p", nb_ptr);
    cr_assert_stdout_eq_str(str);
    free(nb_ptr);
}

Test(my_printf, test_n)
{
    int *nb = malloc(sizeof(int *));
    int *nb2 = malloc(sizeof(int *));
    my_printf("hello\n", nb);
    printf("hello\n", nb2);
    cr_assert_eq(*nb, *nb2);
}

Test(my_printf, test_g_nopowerminusfour, .init = redirect_all_std)
{
    char str[20];

    sprintf(str, "%g", 0.00246);
    my_printf("%g", 0.00246);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, test_g_powerminusfour, .init = redirect_all_std)
{
    char str[40];

    sprintf(str, "%g", 0.0000246);
    my_printf("%g", 0.0000246);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, test_g_smallpower, .init = redirect_all_std)
{
    char str[30];

    sprintf(str, "%g", 0.0000000246);
    my_printf("%g", 0.0000000246);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, test_g_big_number, .init = redirect_all_std)
{
    char str[20];

    sprintf(str, "%g", 246.45);
    my_printf("%g", 246.45);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, test_10g_powerminusfour, .init = redirect_all_std)
{
    char str[20];

    sprintf(str, "%.10g", 0.0000246);
    my_printf("%.10g", 0.0000246);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, test_0g_powerminusfour, .init = redirect_all_std)
{
    char str[20];

    sprintf(str, "%.0g", 0.0000246);
    my_printf("%.0g", 0.0000246);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, test_18g_powerminusfour, .init = redirect_all_std)
{
    char str[20];

    sprintf(str, "%.0g", 0.0000246);
    my_printf("%.0g", 0.0000246);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, test_18G_powerminusfour, .init = redirect_all_std)
{
    char str[20];

    sprintf(str, "%.0G", 0.0000246);
    my_printf("%.0G", 0.0000246);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, test_18g_smallpower, .init = redirect_all_std)
{
    char str[24];

    sprintf(str, "%.18g", 0.0000246);
    my_printf("%.18g", 0.0000246);
    //cr_assert_stdout_eq_str(str);
}

Test(my_printf, test_padding_simple, .init = redirect_all_std)
{
    char str[20];

    sprintf(str, "%-5d", 12);
    my_printf("%-5d", 12);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, test_padding_medium, .init = redirect_all_std)
{
    char str[20];

    sprintf(str, "%-8f", 1.25);
    my_printf("%-8f", 1.25);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, big_test, .init = redirect_all_std)
{
    char str[200];
    double lala = 0.0000000456;
    double lolo = 143.12345;

    sprintf(str, "je suis sur a %d%% qu il y a %.5f mais aussi %g la", 90, lolo, lala);
    my_printf("je suis sur a %d%% qu il y a %.5f mais aussi %g la", 90, lolo, lala);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, accuracy_int_bigger, .init = redirect_all_std)
{
    char str[14];

    sprintf(str, "je suis %.5d", 4);
    my_printf("je suis %.5d", 4);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, accuracy_int_lower, .init = redirect_all_std)
{
    char str[13];

    sprintf(str, "je suis %.3d", 4465);
    my_printf("je suis %.3d", 4465);
    cr_assert_stdout_eq_str(str);
}

/*Test(my_printf, test_weird_g, .init = redirect_all_std)
{
    char str[20];

    sprintf(str, "%g", 2178.346);
    my_printf("%g", 2178.346);
    cr_assert_stdout_eq_str(str);
}*/

Test(my_printf, test_minus_format, .init = redirect_all_std)
{
    char str[20];

    sprintf(str, "%-5d", 8);
    my_printf("%-5d", 8);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, test_minus_format_2, .init = redirect_all_std)
{
    char str[20];

    sprintf(str, "%-5d", 864723);
    my_printf("%-5d", 864723);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, test_plus_format, .init = redirect_all_std)
{
    char str[30];

    sprintf(str, "%+d %+i", 8, 8);
    my_printf("%+d %+i", 8, 8);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, test_plus_format2, .init = redirect_all_std)
{
    char str[30];

    sprintf(str, "%o %u %x", 56, 98, 31);
    my_printf("%+o %+u %+x", 56, 98, 31);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, test_plus_format3, .init = redirect_all_std)
{
    char str[33];

    sprintf(str, "%+f %+e %+g", 0.452, 255.56, 89.51);
    my_printf("%+f %+e %+g", 0.452, 255.56, 89.51);
    cr_assert_stdout_eq_str(str); 
}

Test(my_printf, test_zero_format, .init = redirect_all_std)
{
    char str[15];

    sprintf(str, "%05d %06d", 12, -98);
    my_printf("%05d %06d", 12, -98);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, test_zero_format2, .init = redirect_all_std)
{
    char str[15];

    sprintf(str, "%012f", 0.45);
    my_printf("%012f", 0.45);
    cr_assert_stdout_eq_str(str);  
}

Test(my_printf, test_zero_format3, .init = redirect_all_std)
{
    char str[15];

    sprintf(str, "%012e", 0.45);
    my_printf("%012e", 0.45);
    cr_assert_stdout_eq_str(str);  
}

/*Test(my_printf, test_zero_format4, .init = redirect_all_std)
{
    char str[15];

    sprintf(str, "%012g", 0.45);
    my_printf("%012g", 0.45);
    cr_assert_stdout_eq_str(str);
}*/

Test(my_printf, test_n_flag)
{
    int nb = 0;

    my_printf("hello%n", &nb);
    cr_assert_eq(nb, 5);
}

Test(my_printf, test_n_flag2)
{
    int nb = 0;

    my_printf("hello%s%n", " world", &nb);
    cr_assert_eq(nb, 11);
}

Test(my_printf, test_n_flag3)
{
    int nb = 0;

    my_printf("hello%d%n", 12015, &nb);
    cr_assert_eq(nb, 10);
}

Test(my_printf, test_space, .init = redirect_all_std)
{
    char str[15];

    sprintf(str, "lala % d", 46);
    my_printf("lala % d", 46);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, test_spaces, .init = redirect_all_std)
{
    char str[15];

    sprintf(str, "lala % d", 46);
    my_printf("lala %     d", 46);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, test_spaces_wprefix, .init = redirect_all_std)
{
    char str[15];
    long int lol = 46;

    sprintf(str, "lala % ld", lol);
    my_printf("lala %     ld", lol);
    cr_assert_stdout_eq_str(str);
}
