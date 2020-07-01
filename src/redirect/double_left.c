/*
** EPITECH PROJECT, 2020
** double_left.c
** File description:
** double_left
*/

#include "../include/mysh.h"

void putcharfordouble(char c)
{
    write(1, &c, 1);
}

int wait_for_word(char *file, char *buf, char *crefile)
{
    int ret = 0;

    while (strcmp(buf, file)) {
        putcharfordouble('?');
        putcharfordouble(' ');
        if ((ret = read(0, buf, 1024)) < 0)
            return (printf("Error\n"));
        if (ret)
            buf[ret - 1] = 0;
        if (strcmp(buf, file)) {
            strcat(crefile, buf);
            strcat(crefile, "\n");
        }
    }
    return (0);
}

int redir_double_input(char *file)
{
    char buf[1024 + 1];
    char *crefile = malloc(1000);
    int fd = 0;
    FILE *fptr;
    int fdpipe[2];

    fptr = fopen("double", "w");
    if (pipe(fdpipe) == -1)
        return (-1);
    buf[0] = 0;
    wait_for_word(file, buf, crefile);
    fd = open("double", O_RDONLY);
    fprintf(fptr, "%s", crefile);
    fclose(fptr);
    dup2(fd, 0);
    close(fd);
    if (remove("double") == 0)
        return (0);
    return (0);
}
