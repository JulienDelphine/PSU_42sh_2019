/*
** EPITECH PROJECT, 2020
** mysh2
** File description:
** all signal handler
*/

#include "../include/mysh.h"

void ctrl_c(int i)
{
    if (i == 2)
        my_printf("\n$> ");
}