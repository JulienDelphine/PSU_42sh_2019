/*
** EPITECH PROJECT, 2020
** antcd.c
** File description:
** antcd
*/

#include "mysh.h"

char *get_secondwd(char *secondwd, char *buffer, int chinese)
{
    if (chinese == 0)
        secondwd = getcwd(buffer, 1024);
    return (secondwd);
}

char *cd_noarg(char *line, char *user, char *oldwd, int chinese)
{
    char *userone = malloc(1000);
    char *buffer = malloc(1000);

    if (strlen(line) == 2 && chinese == 0) {
        strcat(userone, "/home/");
        strcat(userone, user);
        free(oldwd);
        oldwd = getcwd(buffer, 1024);
        chdir(userone);
    }
    return (oldwd);
}

void ant_cd(char *line, char **envp)
{
    char *user = get_user(envp);
    char *buffer = malloc(1000);
    static char *oldwd;
    static char *secondwd;
    static int chinese;

    if (line[0] == 'c' && line[1] == 'd') {
        oldwd = cd_noarg(line, user, oldwd, chinese);
        normal_cd(line, buffer, &oldwd, &chinese);
        if (line[3] == '|' || line[3] == ';')
        return;
        if (line[3] == '-') {
            secondwd = get_secondwd(secondwd, buffer, chinese);
            chdir(oldwd);
            free(oldwd);
            oldwd = secondwd;
            chinese = 0;
        }
    }
}