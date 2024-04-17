/*
** EPITECH PROJECT, 2023
** my.h
** File description:
** header for the my_printf project
*/

#ifndef MY_H
    #define MY_H
    #include "lib.h"
    #include "shell.h"

int my_printf(const char *format, ...);

int flags_manager(char const *format, va_list list, int co_mod, char *flag);
int int_flags_manager(char *flag, long long int arg, char const *format,
    int co_mod);
int float_flags_manager(char *flag, double arg, char const *format,
    int co_mod);
int str_flags_manager(char *flag, char *arg);
int lint_flags_manager(char *flag, long int arg,
    char const *format, int co_mod);

int my_count_putchar(char c);
int my_count_putnbr(long long int nb);
int my_count_putstr(const char *str);
int my_count_puthex(int nb, int is_upper);
int my_count_putfloat(double *nb, int accuracy);
int my_count_putsc(double *nb, int precision, int upper);
int my_count_putunsigned(unsigned int nb);
int my_display_octal(unsigned int nb);
int my_display_long_octal(unsigned long nb);
int my_count_putptr(void *ptr);
int my_strlen(char const *str);
int my_tablen(char **str);
int my_countnbr(long long int nb);
char *my_strcat(char *dest, char const *src);
char *concat(const char *s1, const char *s2);
char *my_sputnbr(long long int nb, char *str);
int is_number(char c);
int str_to_int(char *str);

unsigned long int calc_power_pos(int nb, int p);

int indicator_manager(char const *format, char flag, int *i, va_list list);
int indicator_int(char const *format, int i);
int zero_indicator(char format, int len);
int minus_indicator(char const *format, int co_mod, int len);
int hashtag_indicator_int(char *flag, char const *format,
    int co_mod, long long int arg);

char *my_strcpy(char *dest, char const *src);
char *my_strdup(char const *src);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);

char get_flag(char c);
int is_flag(char c);
int is_size_prefix(char c);

char *my_memset(char *str, char c, int nb);
int my_printf(const char *format, ...);
void my_putstr(char *str);

//history
void add_history(char *str, history_t **history);
void display_history(history_t *history, int arg);
void free_history(history_t **history);
int history_command(char **args, env_t *env, int *return_value);

char **str_to_arr_pipes(char const *str);

//alias
int alias_command(char **args, env_t *env, int *return_value);
alias_t *init_alias(void);
void tr_args_with_alias(char ***args, alias_t *alias);
void reinit_alias(env_t *env);

#endif
