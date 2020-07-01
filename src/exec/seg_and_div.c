/*
** EPITECH PROJECT, 2020
** seg_and_div.c
** File description:
** seg and div
*/

#include "../include/mysh.h"

int seg_and_divzero(pid_t pid, int *storage)
{
    int exit_status = 0;

    waitpid(pid, storage, 0);
    if (WIFEXITED((*storage)))
        exit_status = WEXITSTATUS((*storage));
    if (WTERMSIG((*storage)) == SIGSEGV) {
        write(2, "Segmentation fault\n", 19);
        return (139);
    }
    if (WTERMSIG((*storage)) == SIGFPE) {
        write(2, "Floating exception\n", 19);
        return (139);
    }
    return (exit_status);
}
