/*
** EPITECH PROJECT, 2020
** setenv.c
** File description:
** setenv
*/

#include "mysh.h"

void cat_to_env(char **envp, char **arguments, int checker, int last_env)
{
    for (int m = 0; envp[m] != NULL; m++) {
        if (my_strcmp_equal(envp[m], arguments[1]) == 0) {
            envp[m] = arguments[1];
            strcat(envp[m], "=");
            strcat(envp[m], arguments[2]);
            checker = 1;
        }
    }
    if (checker == 0) {
        envp[last_env] = arguments[1];
        strcat(envp[last_env], "=");
        strcat(envp[last_env], arguments[2]);
        envp[last_env + 1] = NULL;
    }
}

void setenv_three_arg(char **envp, char *line, char **arguments, int checker)
{
    int last_env = 0;

    for (last_env = 0; envp[last_env] != NULL; ++last_env);
    if (line[0] == 's' && line[1] == 'e' && line[2] == 't' && line[3] == 'e' &&
        line[4] == 'n' && line[5] == 'v' && nb_wordnocolumn(line) == 3) {
        if (is_it_alpha(arguments[1]) == 84) {
            printf("setenv: Variable name must ");
            printf("contain alphanumeric characters.\n");
            return;
        }
        cat_to_env(envp, arguments, checker, last_env);
    }
}

int cat_to_env_no_a(char **envp, char **arguments, int checker, int last_env)
{
    for (int m = 0; envp[m] != NULL; m++) {
        if (my_strcmp_equal(envp[m], arguments[1]) == 0) {
            envp[m] = arguments[1];
            strcat(envp[m], "=");
            checker = 1;
        }
    }
    if (checker == 0) {
        envp[last_env] = arguments[1];
        strcat(envp[last_env], "=");
        envp[last_env + 1] = NULL;
    }
    return checker;
}

int setenv_two_arg(char **envp, char *line, char **arguments, int checker)
{
    int last_env = 0;

    for (last_env = 0; envp[last_env] != NULL; last_env++);
    if (line[0] == 's' && line[1] == 'e' && line[2] == 't' && line[3] == 'e' &&
        line[4] == 'n' && line[5] == 'v' && nb_wordnocolumn(line) == 2) {
        if (is_it_alpha(arguments[1]) == 84) {
            printf("setenv: Variable name must ");
            printf("contain alphanumeric characters.\n");
            return (1);
        }
        checker = cat_to_env_no_a(envp, arguments, checker, last_env);
    }
    return (checker);
}

int recoded_env(char **envp, char *line, char **arguments)
{
    char *newline = malloc(sizeof(char) * (my_strlen(line) + 1));
    int k = 0;
    int checker = 0;
    int back = 0;

    while (line[k] != ' ') {
        if (line[k] == '\0')
            break;
        newline[k] = line[k];
        k++;
    }
    error_env(line);
    back = print_env(envp, line, newline);
    checker = setenv_two_arg(envp, line, arguments, checker);
    setenv_three_arg(envp, line, arguments, checker);
    my_unsetenv(envp, line, arguments);
    return (back);
}