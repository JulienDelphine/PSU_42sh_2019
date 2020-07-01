/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** my_echo
*/

#include "mysh.h"

char *echo_v(char *new_str, int p)
{
    int u = 0;

    while (u <= p)
        u++;
    new_str[p] = '\n';
    p++;
    for (int y = 0; y <= u - 1; y++, p++) {
        new_str[p] = ' ';
    }
    return new_str;
}

char *echo_e(mysh_s mysh, int feco)
{
    int p = 0;
    char *new_str;
    if ((new_str = malloc(sizeof(char) * strlen(mysh.arg[feco]) * 2)) == NULL)
        return NULL;
    for (int i = 0; mysh.arg[feco][i] != '\0'; i++, p++) {
        if (mysh.arg[feco][i] == 92 && mysh.arg[feco][i + 1] == 't') {
            new_str[p++] = '\t'; i = i + 2;
        }
        if (mysh.arg[feco][i] == 92 && mysh.arg[feco][i + 1] == 92)
            i++;
        if (mysh.arg[feco][i] == 92 && mysh.arg[feco][i + 1] == 'v') {
            new_str = echo_v(new_str, p);
            p += p + 1;
            i += 2;
        }
        if (mysh.arg[feco][i] == 92 && mysh.arg[feco][i + 1] == 'c') {
            new_str[p] = '\0'; return new_str;
        }
        new_str[p] = mysh.arg[feco][i];
    }
    new_str[p] = '\0'; return new_str;
}

int echo_var(mysh_s mysh, char **env, int feco)
{
    int i = 0;
    int c = 0;
    char *var;
    if ((var = malloc(sizeof(char) * 20)) == NULL)
        return 0;
    for (; mysh.arg[feco + 1][i] != '\0'; i++)
        if (mysh.arg[feco + 1][i] == '$') break;
    i++;
    for (; mysh.arg[feco + 1][i] != '\0'; i++, c++)
        var[c] = mysh.arg[feco + 1][i];
    var[c] = '\0';
    for (; env[i] != NULL; i++) {
        if (my_strncmp(var, env[i], (strlen(var))) == 0) {
            my_printf("%s\n", env[i]);
            return 0;
        }
    }
    if (env[i] == NULL)
        printf("%s: Undefined variable.\n", var);
    return 0;
}

int bis_echo(mysh_s mysh, int c, int feco)
{
    int count_argc = 0;
    mysh.g = 1;

    if (mysh.arg[feco + 1] != NULL && mysh.arg[feco + 2] != NULL) {
        count_argc = find_arg(mysh) - 1;
        mysh.arg[feco] = combine_str(mysh, feco);
    } else {
        return 0;
    }
    for (; (count_argc >= 1) && (mysh.arg[count_argc][0] == '-');
    count_argc--, mysh.g = 1) {
        for (; mysh.arg[count_argc][mysh.g] != '\0'; mysh.g++) {
            c = switch_echo(mysh, feco, c, count_argc);
        }
    }
    if (c == 0)
        printf("%s\n", mysh.arg[feco]);
    else
        my_printf("%s", mysh.arg[feco]);
    return 0;
}

int my_echo(mysh_s mysh, char **env)
{
    int feco = find_echo(mysh);
    int c = 0;

    if (mysh.arg[feco + 1] == NULL) {
        putchar('\n');
        return 0;
    }
    if (mysh.arg[feco + 1][0] == '$') {
        echo_var(mysh, env, feco);
        if (mysh.arg[feco + 2] == NULL)
            return 0;
    }
    if (mysh.arg[feco + 1][0] == '"') {
        mysh.arg[feco + 1] = combine_str(mysh, feco);
        printf("%s\n", echo_e(mysh, feco + 1));
    } else {
        c = bis_echo(mysh, c, feco);
    }
    return 0;
}
