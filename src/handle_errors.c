/*
** EPITECH PROJECT, 2020
** mysh2
** File description:
** check only space/tab/\n
*/

#include "../include/mysh.h"

int check_only_space_tab(char *str)
{
    int i = 0;
    int j = 0;

    while (str[i] != '\n' && str[i] != '\0') {
        if (str[i] != ' ' && str[i] != '\t')
            j++;
        i++;
    }
    if (j == 0)
        return (84);
    return (0);
}

int handle_errors(char *buffer, mysh_s mysh, char **env, char **envp)
{
    if (check_only_space_tab(buffer) == 84) {
        my_printf("$> ");
        return (main_mysh(mysh, env, envp));
    }
    if (buffer[0] == '\n') {
        my_printf("$> ");
        return (main_mysh(mysh, env, envp));
    }
    return (0);
}