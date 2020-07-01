/*
** EPITECH PROJECT, 2020
** mysh2
** File description:
** handle pipe
*/

#include "../include/mysh.h"

int create_pipe(char **cmd_pipe, int fd_in, int i)
{
    static int fdpipe[2];

    if (i)
        fd_in = fdpipe[0];
    if (pipe(fdpipe) == -1)
        return (-1);
    if (cmd_pipe[i + 1])
    {
        dup2(fdpipe[1], 1);
        close(fdpipe[1]);
    }
    dup2(fd_in, 0);
    return (0);
}

int check_pipe(char **cmd_pipe, struct_t **list, char ***g_envv)
{
    int i = -1;
    char *tmp;
    int save[2];
    int fd_in = 0;

    while (cmd_pipe[++i])
    {
        save[0] = dup(0);
        save[1] = dup(1);
        if ((tmp = check_redir(cmd_pipe[i]))) {
            if (create_pipe(cmd_pipe, fd_in, i) == -1 ||
            my_execution(tmp, list, g_envv) == -1)
                return (my_free(cmd_pipe));
        }
        dup2(save[0], 0);
        dup2(save[1], 1);
    }
    return (1);
}

int my_pipe(char *input, struct_t **list, char ***g_envv)
{
    char **cmd_pipe;
    int pipe = 0;
    int h_pipe = 0;
    int space = 0;
    int re_l = 0;
    int re_r = 0;

    if (check_for_chev(input, re_l, re_r) == -1)
        return (-1);
    h_pipe = nullcommand(input, pipe, h_pipe, space);
    if (h_pipe == -1)
        return (-1);
    cmd_pipe = delimit_string(input, "|");
    if (ambiguousoutoutput(cmd_pipe, input, h_pipe) == -1)
        return (-1);
    if (cmd_pipe == NULL)
        return (-1);
    check_pipe(cmd_pipe, list, g_envv);
    my_free(cmd_pipe);
    return (1);
}