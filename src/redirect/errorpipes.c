/*
** EPITECH PROJECT, 2020
** errorpipes.c
** File description:
** errorpipes
*/

#include "../include/mysh.h"

int check_for_chev(char *input, int re_l, int re_r)
{
    for (int k = 0; input[k] != '\0'; k++) {
        if ((input[k] == '<' || input[k] == '>') && (input[k+1] == '\0' ||
        input[k + 2] == '|' ||  input[k + 2] == ';')) {
            printf("Missing name for redirect.\n");
            return (-1);
        }
        if (input[k] == '>')
            re_r++;
        if (input[k] == '<')
            re_l++;
        if (re_r >= 3 || re_l >= 3) {
            printf("Missing name for redirect.\n");
            return (-1);
        }
        if (input[k] != '>' && input[k] != '<') {
            re_r = 0;
            re_l = 0;
        }
    }
    return (1);
}

int nullcommand(char *input, int pipe, int h_pipe, int space)
{
    for (int j = 0; input[j] != '\0'; j++) {
        if (input[j] == '|') {
            pipe++;
            h_pipe++;
        }
        if (input[j] == ' ' || input[j] == '\t')
            space++;
        if (input[j] != '|' && input[j] != ' ' && input[j] != '\t') {
            if ((pipe == 2 && space != 0) || pipe > 2) {
                printf("Invalid null command.\n");
                return (-1);
            }
            space = 0;
            pipe = 0;
        }
    }
    return h_pipe;
}

char *check_input(char *input, char *sym, int j, int k)
{
    if (input[j] == '>' || input[j] == '<' || input[j] == ';' ||
        input[j] == '|')
        sym[k++] = input[j];
    return (sym);
}

int ambiguousoutoutput(char **cmd_pipe, char *input, int h_pipe)
{
    int i = 0;
    int k = 0;
    char *sym = malloc(10);

    if (h_pipe != 0){
        for (int j = 0; input[j] != '\0'; j++)
            sym = check_input(input, sym, j, k);
        for (i = 0; cmd_pipe[i] != NULL; i++);
    }
    for (int o = 0; sym[o] != '\0'; o++){
        if (sym[o] == '>' && sym[o + 1] == '|'){
            printf("Ambigous output redirect.\n");
            return (-1);
        }
    }
    if (i == 1 && h_pipe != 0) {
        printf("Invalid null command.\n");
        return (-1);
    }
    return (1);
}
