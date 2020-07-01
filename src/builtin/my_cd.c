/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** My_cd
*/

#include "mysh.h"

void error_disp_cd(char *path)
{
    printf("%s", path);
    printf(": ");
    printf("%s", strerror(errno));
    printf(".\n");
}

char *transfer_user(char **envp, int i, char *path_cd)
{
    for (int k = 0; envp[i][k + 5] != '\0'; k++)
        path_cd[k] = envp[i][k + 5];
    return (path_cd);
}

char *get_user(char **envp)
{
    char *path_cd = malloc(10000);

    for (int i = 0; envp[i] != NULL; i++) {
        if (envp[i][0] == 'U' && envp[i][1] == 'S' &&
            envp[i][2] == 'E' && envp[i][3] == 'R')
        path_cd = transfer_user(envp, i, path_cd);
    }
    return (path_cd);
}

int and_cd(char *line)
{
    char *path = malloc(1000);
    int i = 0;
    int j = 0;

    while (line[i] != ' ') {
        if (line[i] == '\0')
            break;
        i++;
    }
    i++;
    while (line[i] != '\0') {
        path[j] = line[i];
        j++;
        i++;
    }
    if (chdir(path) == -1) {
        error_disp_cd(path);
        return (-1);
    }
    return (0);
}

void normal_cd(char *line, char *buffer, char **oldwd, int *chinese)
{
    if (line[3] != '-' && my_strlen(line) != 2) {
        if ((*chinese) == 0)
            (*oldwd) = getcwd(buffer, 1024);
        (*chinese) = and_cd(line);
    }
}