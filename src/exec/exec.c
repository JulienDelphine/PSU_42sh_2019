/*
** EPITECH PROJECT, 2020
** minishell2
** File description:
** execution
*/

#include "../include/mysh.h"

void signal_handler(int status)
{
    if (status == SIGINT) {
        printf("\n");
        signal(SIGINT, signal_handler);
    }
}

int	my_execution(char *input, struct_t **list, char ***g_envv)
{
    pid_t pid;
    int	stat;
    int storage = 0;
    int exit_status;

    if ((stat = my_builtins(input, g_envv)))
        return (stat);
    if ((pid = fork()) == -1)
        return (printf("Error\n"));
    exit_status = seg_and_divzero(pid, &storage);

    if (pid > 0) {
        if (wait(&stat) == -1)
            return (exit_status);
        signal(SIGINT, signal_handler);
    }
    else {
        return (parsing_input(input, *list, *g_envv));
    }
    return (exit_status);
}
