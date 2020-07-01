/*
** EPITECH PROJECT, 2020
** mysh2
** File description:
** all init for struct
*/

#include "../include/mysh.h"

void end_main(char *str)
{
    free(str);
    if (isatty(STDIN_FILENO) != 0)
        my_printf("$> ");
}

void init_mysh(mysh_s *mysh)
{
    mysh->arg = NULL;
    mysh->buffer = NULL;
    mysh->fd = 0;
}