/*
** EPITECH PROJECT, 2020
** errsetenv.c
** File description:
** error setevn
*/

#include "mysh.h"

int is_it_alpha(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if ((str[i] < 'A' || str[i] > 'Z') &&
            (str[i] < 'a' || str[i] > 'z') && (str[i] < '0' || str[i] > '9'))
            return (84);
        if (str[i] == ':')
            return (84);
        i++;
    }
    return (0);
}

int print_env(char **envp, char *line, char *newline)
{
    if (line[0] == 'e' && line[1] == 'n' && line[2] == 'v' &&
        strlen(newline) == 3) {
        for (int i = 0; envp[i] != NULL; i++)
            my_print_env(envp, i);
        return (1);
        }
    if (line[0] == 's' && line[1] == 'e' && line[2] == 't' && line[3] == 'e' &&
        line[4] == 'n' && line[5] == 'v' && strlen(line) == 6) {
        for (int i = 0; envp[i] != NULL; i++) {
            my_print_env(envp, i);
        }
        return (1);
    }
    return (0);
}

void my_unsetenv(char **envp, char *line, char **arguments)
{
    if (line[0] == 'u' && line[1] == 'n' && line[2] == 's' &&
        line[3] == 'e' && line[4] == 't' &&
        line[5] == 'e' && line[6] == 'n' && line[7] == 'v' &&
        nb_words(line) == 2) {
        for (int m = 0; envp[m] != NULL; m++)
            end_env(envp, m, arguments);
    }
}

void error_env(char *line)
{
    if (line[0] == 's' && line[1] == 'e' && line[2] == 't' && line[3] == 'e'
    && line[4] == 'n' && line[5] == 'v' && nb_wordnocolumn(line) > 3) {
        printf("setenv: Too many arguments.\n");
    }
    if (line[0] == 'u' && line[1] == 'n' && line[2] == 's' &&
        line[3] == 'e' && line[4] == 't' &&
        line[5] == 'e' && line[6] == 'n' && line[7] == 'v' &&
        nb_wordnocolumn(line) < 2) {
        printf("unsetenv: Too few arguments.\n");
    }
}
