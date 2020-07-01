/*
** EPITECH PROJECT, 2020
** builtins.c
** File description:
** builtins
*/

#include "../include/mysh.h"

int	my_builtins(char *buf, char ***g_envv)
{
    char **tab;

    tab = delimit_string(buf, " \t");
    if (tab == NULL || !tab[0])
        return (-1 * my_free(tab));
    if (!my_strcmp("exit", tab[0])) {
        my_exit(tab);
        return (my_free(tab));
    }
    if (!my_strcmp("cd", tab[0]))
        ant_cd(buf, *g_envv);
    my_free(tab);
    return (0);
}