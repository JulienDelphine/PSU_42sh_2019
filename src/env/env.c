/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** All little function for env
*/

#include "mysh.h"

void end_env(char **envp, int m, char **arg)
{
    if (my_strcmp_equal(envp[m], arg[1]) == 0)
        envp[m] = "\0";
}

void my_print_env(char **envp, int i)
{
    if (my_strcmp(envp[i], "\0") != 0)
        printf("%s\n", envp[i]);
}