/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** combine str
*/

#include "mysh.h"

char *com_str(mysh_s mysh, int i, int p)
{
    char *mix_str = malloc(sizeof(char) * 1024);
    int c = 0;

    mix_str = memset(mix_str, 0, 1024);
    while (mysh.arg[i][p] != '"') {
        if (mysh.arg[i][p] == '\0') {
            i++;
            p = 0;
            mix_str[c] = ' ';
            c++;
        }
        mix_str[c] = mysh.arg[i][p];
        c++;
        p++;
    }
    mix_str[c] = '\0';
    return mix_str;
}

char *combine_str(mysh_s mysh)
{
    int i = 0;
    int p = 0;
    char *mix_str;

    while (mysh.arg[i] != NULL) {
        if (mysh.arg[i][p] == '"') {
            p++;
            mix_str = com_str(mysh, i, p);
        }
        i++;
    }
    return mix_str;
}
