/*
** EPITECH PROJECT, 2020
** mysh2
** File description:
** my exit
*/

#include "../include/mysh.h"

void my_exit(char **arg)
{
    int i = 0;

    if (arg[1] != NULL && my_str_isnum(arg[1]) == 1) {
        i = my_getnbr(arg[1]);
        printf("exit\n");
        free(arg);
        exit(i);
    } else if (arg[1] != NULL && my_str_isnum(arg[1]) == 0) {
        printf("exit: Expression Syntax.\n");
    } else {
        printf("exit\n");
        free(arg);
        exit(0);
    }
}
