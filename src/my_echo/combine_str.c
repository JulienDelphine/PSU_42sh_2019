/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** combine str
*/

#include "mysh.h"

char *com_str(mysh_s mysh, int i, int p)
{
    char *mix_str;
    int c = 0;

    if ((mix_str = malloc(sizeof(char) * 1024)) == NULL)
        return NULL;
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

char *combine_str(mysh_s mysh, int feco)
{
    int i = feco + 1;
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

int find_arg(mysh_s mysh)
{
    int j = 0;

    while (mysh.arg[j][0] != '"')
        j++;
    return j;
}

int find_echo(mysh_s mysh)
{
    int k = 0;

    while (mysh.arg[k] != NULL) {
        if (strncmp(mysh.arg[k], "echo", 4) == 0)
            break;
        k++;
    }
    return k;
}

void print_arg(mysh_s mysh)
{
    int k = find_echo(mysh);
    char c = ' ';
    int d = 0;

    while (mysh.arg[k] != NULL) {
        if (d != 0)
            my_printf("%c", c);
        my_printf("%s", mysh.arg[k]);
        k++;
        d++;
    }
}
